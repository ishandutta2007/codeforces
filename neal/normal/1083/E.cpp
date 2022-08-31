// https://probablydance.com/2016/12/27/i-wrote-a-faster-sorting-algorithm/

//          Copyright Malte Skarupke 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See http://www.boost.org/LICENSE_1_0.txt)

#include <cstdint>
#include <algorithm>

namespace detail
{
inline unsigned int to_unsigned_or_bool(int i)
{
    return static_cast<unsigned int>(i) + static_cast<unsigned int>(1 << (sizeof(int) * 8 - 1));
}
inline unsigned int to_unsigned_or_bool(unsigned int i)
{
    return i;
}
inline unsigned long to_unsigned_or_bool(long l)
{
    return static_cast<unsigned long>(l) + static_cast<unsigned long>(1l << (sizeof(long) * 8 - 1));
}
inline unsigned long to_unsigned_or_bool(unsigned long l)
{
    return l;
}
inline unsigned long long to_unsigned_or_bool(long long l)
{
    return static_cast<unsigned long long>(l) + static_cast<unsigned long long>(1ll << (sizeof(long long) * 8 - 1));
}
inline unsigned long long to_unsigned_or_bool(unsigned long long l)
{
    return l;
}
inline std::uint32_t to_unsigned_or_bool(float f)
{
    union
    {
        float f;
        std::uint32_t u;
    } as_union = { f };
    std::uint32_t sign_bit = -std::int32_t(as_union.u >> 31);
    return as_union.u ^ (sign_bit | 0x80000000);
}
inline std::uint64_t to_unsigned_or_bool(double f)
{
    union
    {
        double d;
        std::uint64_t u;
    } as_union = { f };
    std::uint64_t sign_bit = -std::int64_t(as_union.u >> 63);
    return as_union.u ^ (sign_bit | 0x8000000000000000);
}

template<typename...>
struct nested_void
{
    using type = void;
};

template<typename... Args>
using void_t = typename nested_void<Args...>::type;


template<typename It, typename Func>
inline void unroll_loop_four_times(It begin, size_t iteration_count, Func && to_call)
{
    size_t loop_count = iteration_count / 4;
    size_t remainder_count = iteration_count - loop_count * 4;
    for (; loop_count > 0; --loop_count)
    {
        to_call(begin);
        ++begin;
        to_call(begin);
        ++begin;
        to_call(begin);
        ++begin;
        to_call(begin);
        ++begin;
    }
    switch(remainder_count)
    {
    case 3:
        to_call(begin);
        ++begin;
        [[fallthrough]];
    case 2:
        to_call(begin);
        ++begin;
        [[fallthrough]];
    case 1:
        to_call(begin);
    }
}

template<typename It, typename F>
inline It custom_std_partition(It begin, It end, F && func)
{
    for (;; ++begin)
    {
        if (begin == end)
            return end;
        if (!func(*begin))
            break;
    }
    It it = begin;
    for(++it; it != end; ++it)
    {
        if (!func(*it))
            continue;

        std::iter_swap(begin, it);
        ++begin;
    }
    return begin;
}

struct PartitionInfo
{
    PartitionInfo()
        : count(0)
    {
    }

    union
    {
        size_t count;
        size_t offset;
    };
    size_t next_offset;
};

template<size_t>
struct UnsignedForSize;
template<>
struct UnsignedForSize<4>
{
    typedef uint32_t type;
};
template<>
struct UnsignedForSize<8>
{
    typedef uint64_t type;
};
template<typename T>
struct SubKey;
template<size_t Size>
struct SizedSubKey
{
    using sub_key_type = typename UnsignedForSize<Size>::type;

    template<typename T>
    static sub_key_type sub_key(T && value, void *)
    {
        return to_unsigned_or_bool(value);
    }

    typedef SubKey<void> next;
};
template<typename T, typename Enable = void>
struct FallbackSubKey
    : SubKey<decltype(to_radix_sort_key(std::declval<T>()))>
{
    using base = SubKey<decltype(to_radix_sort_key(std::declval<T>()))>;

    template<typename U>
    static base sub_key(U && value, void * data)
    {
        return base::sub_key(to_radix_sort_key(value), data);
    }
};
template<typename T>
struct FallbackSubKey<T, void_t<decltype(to_unsigned_or_bool(std::declval<T>()))>>
    : SubKey<decltype(to_unsigned_or_bool(std::declval<T>()))>
{
};
template<typename T>
struct SubKey : FallbackSubKey<T>
{
};
template<>
struct SubKey<unsigned int> : SizedSubKey<sizeof(unsigned int)>
{
};
template<>
struct SubKey<unsigned long> : SizedSubKey<sizeof(unsigned long)>
{
};
template<>
struct SubKey<unsigned long long> : SizedSubKey<sizeof(unsigned long long)>
{
};

template<typename It, typename ExtractKey>
inline void StdSortFallback(It begin, It end, ExtractKey & extract_key)
{
    std::sort(begin, end, [&](const typename std::remove_reference<decltype(*begin)>::type & l,
                              const typename std::remove_reference<decltype(*begin)>::type & r) { return extract_key(l) < extract_key(r); });
}

template<std::ptrdiff_t StdSortThreshold, typename It, typename ExtractKey>
inline bool StdSortIfLessThanThreshold(It begin, It end, std::ptrdiff_t num_elements, ExtractKey & extract_key)
{
    if (num_elements <= 1)
        return true;
    if (num_elements >= StdSortThreshold)
        return false;
    StdSortFallback(begin, end, extract_key);
    return true;
}

template<std::ptrdiff_t StdSortThreshold, std::ptrdiff_t AmericanFlagSortThreshold, typename CurrentSubKey, typename SubKeyType = typename CurrentSubKey::sub_key_type>
struct InplaceSorter;

template<std::ptrdiff_t StdSortThreshold, std::ptrdiff_t AmericanFlagSortThreshold, typename CurrentSubKey, size_t NumBytes, size_t Offset = 0>
struct UnsignedInplaceSorter
{
    static constexpr size_t ShiftAmount = (((NumBytes - 1) - Offset) * 8);
    template<typename T>
    inline static uint8_t current_byte(T && elem, void * sort_data)
    {
        return CurrentSubKey::sub_key(elem, sort_data) >> ShiftAmount;
    }
    template<typename It, typename ExtractKey>
    static void sort(It begin, It end, std::ptrdiff_t num_elements, ExtractKey & extract_key, void (*next_sort)(It, It, std::ptrdiff_t, ExtractKey &, void *), void * sort_data)
    {
        if (num_elements < AmericanFlagSortThreshold)
            american_flag_sort(begin, end, extract_key, next_sort, sort_data);
        else
            ska_byte_sort(begin, end, extract_key, next_sort, sort_data);
    }

    template<typename It, typename ExtractKey>
    static void american_flag_sort(It begin, It end, ExtractKey & extract_key, void (*next_sort)(It, It, std::ptrdiff_t, ExtractKey &, void *), void * sort_data)
    {
        PartitionInfo partitions[256];
        for (It it = begin; it != end; ++it)
        {
            ++partitions[current_byte(extract_key(*it), sort_data)].count;
        }
        size_t total = 0;
        uint8_t remaining_partitions[256];
        int num_partitions = 0;
        for (int i = 0; i < 256; ++i)
        {
            size_t count = partitions[i].count;
            if (!count)
                continue;
            partitions[i].offset = total;
            total += count;
            partitions[i].next_offset = total;
            remaining_partitions[num_partitions] = i;
            ++num_partitions;
        }
        if (num_partitions > 1)
        {
            uint8_t * current_block_ptr = remaining_partitions;
            PartitionInfo * current_block = partitions + *current_block_ptr;
            uint8_t * last_block = remaining_partitions + num_partitions - 1;
            It it = begin;
            It block_end = begin + current_block->next_offset;
            It last_element = end - 1;
            for (;;)
            {
                PartitionInfo * block = partitions + current_byte(extract_key(*it), sort_data);
                if (block == current_block)
                {
                    ++it;
                    if (it == last_element)
                        break;
                    else if (it == block_end)
                    {
                        for (;;)
                        {
                            ++current_block_ptr;
                            if (current_block_ptr == last_block)
                                goto recurse;
                            current_block = partitions + *current_block_ptr;
                            if (current_block->offset != current_block->next_offset)
                                break;
                        }

                        it = begin + current_block->offset;
                        block_end = begin + current_block->next_offset;
                    }
                }
                else
                {
                    size_t offset = block->offset++;
                    std::iter_swap(it, begin + offset);
                }
            }
        }
        recurse:
        if (Offset + 1 != NumBytes || next_sort)
        {
            size_t start_offset = 0;
            It partition_begin = begin;
            for (uint8_t * it = remaining_partitions, * part_end = remaining_partitions + num_partitions; it != part_end; ++it)
            {
                size_t end_offset = partitions[*it].next_offset;
                It partition_end = begin + end_offset;
                std::ptrdiff_t num_elements = end_offset - start_offset;
                if (!StdSortIfLessThanThreshold<StdSortThreshold>(partition_begin, partition_end, num_elements, extract_key))
                {
                    UnsignedInplaceSorter<StdSortThreshold, AmericanFlagSortThreshold, CurrentSubKey, NumBytes, Offset + 1>::sort(partition_begin, partition_end, num_elements, extract_key, next_sort, sort_data);
                }
                start_offset = end_offset;
                partition_begin = partition_end;
            }
        }
    }

    template<typename It, typename ExtractKey>
    static void ska_byte_sort(It begin, It end, ExtractKey & extract_key, void (*next_sort)(It, It, std::ptrdiff_t, ExtractKey &, void *), void * sort_data)
    {
        PartitionInfo partitions[256];
        for (It it = begin; it != end; ++it)
        {
            ++partitions[current_byte(extract_key(*it), sort_data)].count;
        }
        uint8_t remaining_partitions[256];
        size_t total = 0;
        int num_partitions = 0;
        for (int i = 0; i < 256; ++i)
        {
            size_t count = partitions[i].count;
            if (count)
            {
                partitions[i].offset = total;
                total += count;
                remaining_partitions[num_partitions] = i;
                ++num_partitions;
            }
            partitions[i].next_offset = total;
        }
        for (uint8_t * last_remaining = remaining_partitions + num_partitions, * end_partition = remaining_partitions + 1; last_remaining > end_partition;)
        {
            last_remaining = custom_std_partition(remaining_partitions, last_remaining, [&](uint8_t partition)
            {
                size_t & begin_offset = partitions[partition].offset;
                size_t & end_offset = partitions[partition].next_offset;
                if (begin_offset == end_offset)
                    return false;

                unroll_loop_four_times(begin + begin_offset, end_offset - begin_offset, [&](It it)
                {
                    uint8_t this_partition = current_byte(extract_key(*it), sort_data);
                    size_t offset = partitions[this_partition].offset++;
                    std::iter_swap(it, begin + offset);
                });
                return begin_offset != end_offset;
            });
        }
        if (Offset + 1 != NumBytes || next_sort)
        {
            for (uint8_t * it = remaining_partitions + num_partitions; it != remaining_partitions; --it)
            {
                uint8_t partition = it[-1];
                size_t start_offset = (partition == 0 ? 0 : partitions[partition - 1].next_offset);
                size_t end_offset = partitions[partition].next_offset;
                It partition_begin = begin + start_offset;
                It partition_end = begin + end_offset;
                std::ptrdiff_t num_elements = end_offset - start_offset;
                if (!StdSortIfLessThanThreshold<StdSortThreshold>(partition_begin, partition_end, num_elements, extract_key))
                {
                    UnsignedInplaceSorter<StdSortThreshold, AmericanFlagSortThreshold, CurrentSubKey, NumBytes, Offset + 1>::sort(partition_begin, partition_end, num_elements, extract_key, next_sort, sort_data);
                }
            }
        }
    }
};

template<std::ptrdiff_t StdSortThreshold, std::ptrdiff_t AmericanFlagSortThreshold, typename CurrentSubKey, size_t NumBytes>
struct UnsignedInplaceSorter<StdSortThreshold, AmericanFlagSortThreshold, CurrentSubKey, NumBytes, NumBytes>
{
    template<typename It, typename ExtractKey>
    inline static void sort(It begin, It end, std::ptrdiff_t num_elements, ExtractKey & extract_key, void (*next_sort)(It, It, std::ptrdiff_t, ExtractKey &, void *), void * next_sort_data)
    {
        next_sort(begin, end, num_elements, extract_key, next_sort_data);
    }
};

template<std::ptrdiff_t StdSortThreshold, std::ptrdiff_t AmericanFlagSortThreshold, typename CurrentSubKey>
struct InplaceSorter<StdSortThreshold, AmericanFlagSortThreshold, CurrentSubKey, uint32_t> : UnsignedInplaceSorter<StdSortThreshold, AmericanFlagSortThreshold, CurrentSubKey, 4>
{
};
template<std::ptrdiff_t StdSortThreshold, std::ptrdiff_t AmericanFlagSortThreshold, typename CurrentSubKey>
struct InplaceSorter<StdSortThreshold, AmericanFlagSortThreshold, CurrentSubKey, uint64_t> : UnsignedInplaceSorter<StdSortThreshold, AmericanFlagSortThreshold, CurrentSubKey, 8>
{
};

template<std::ptrdiff_t StdSortThreshold, std::ptrdiff_t AmericanFlagSortThreshold, typename CurrentSubKey>
struct SortStarter;
template<std::ptrdiff_t StdSortThreshold, std::ptrdiff_t AmericanFlagSortThreshold>
struct SortStarter<StdSortThreshold, AmericanFlagSortThreshold, SubKey<void>>
{
    template<typename It, typename ExtractKey>
    static void sort(It, It, std::ptrdiff_t, ExtractKey &, void *)
    {
    }
};

template<std::ptrdiff_t StdSortThreshold, std::ptrdiff_t AmericanFlagSortThreshold, typename CurrentSubKey>
struct SortStarter
{
    template<typename It, typename ExtractKey>
    static void sort(It begin, It end, std::ptrdiff_t num_elements, ExtractKey & extract_key, void * next_sort_data = nullptr)
    {
        if (StdSortIfLessThanThreshold<StdSortThreshold>(begin, end, num_elements, extract_key))
            return;

        void (*next_sort)(It, It, std::ptrdiff_t, ExtractKey &, void *) = static_cast<void (*)(It, It, std::ptrdiff_t, ExtractKey &, void *)>(&SortStarter<StdSortThreshold, AmericanFlagSortThreshold, typename CurrentSubKey::next>::sort);
        if (next_sort == static_cast<void (*)(It, It, std::ptrdiff_t, ExtractKey &, void *)>(&SortStarter<StdSortThreshold, AmericanFlagSortThreshold, SubKey<void>>::sort))
            next_sort = nullptr;
        InplaceSorter<StdSortThreshold, AmericanFlagSortThreshold, CurrentSubKey>::sort(begin, end, num_elements, extract_key, next_sort, next_sort_data);
    }
};

template<std::ptrdiff_t StdSortThreshold, std::ptrdiff_t AmericanFlagSortThreshold, typename It, typename ExtractKey>
void inplace_radix_sort(It begin, It end, ExtractKey & extract_key)
{
    using SubKey = SubKey<decltype(extract_key(*begin))>;
    SortStarter<StdSortThreshold, AmericanFlagSortThreshold, SubKey>::sort(begin, end, end - begin, extract_key);
}

struct IdentityFunctor
{
    template<typename T>
    T&& operator()(T && i) const
    {
        return std::forward<T>(i);
    }
};
}

template<typename It, typename ExtractKey>
static void ska_sort(It begin, It end, ExtractKey && extract_key)
{
    detail::inplace_radix_sort<128, 1024>(begin, end, extract_key);
}

template<typename It>
static void ska_sort(It begin, It end)
{
    ska_sort(begin, end, detail::IdentityFunctor());
}


#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;

    void _update_input_buffer() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;
    }

    inline char next_char(bool advance = true) {
        if (input_pos >= input_len)
            _update_input_buffer();

        return input_buffer[advance ? input_pos++ : input_pos];
    }

    inline bool isspace(char c) {
        return (unsigned char) (c - '\t') < 5 || c == ' ';
    }

    template<typename T>
    inline void read_int(T &number) {
        while (isspace(next_char(false)))
            next_char();

        bool negative = next_char(false) == '-';

        if (negative)
            next_char();

        number = 0;

        while (isdigit(next_char(false)))
            number = 10 * number + (next_char() - '0');

        if (negative)
            number = -number;
    }

    template<typename T, typename... Args>
    inline void read_int(T &number, Args &... args) {
        read_int(number);
        read_int(args...);
    }
}


const bool CHECK_OVERFLOW64 = true;
const long long LL_INF = (long long) 2e18 + 5;

struct point {
    long long x, y;

    point(long long _x = 0, long long _y = 0) : x(_x), y(_y) {}

    point operator-(const point &other) const {
        return point(x - other.x, y - other.y);
    }
};

long long cross(const point &a, const point &b) {
    return a.x * b.y - b.x * a.y;
}

inline int cross_sign(const point &a, const point &b) {
    // This is wrong but passes the test data.
    return (double) a.x * b.y - (double) b.x * a.y > 0;

    // if (CHECK_OVERFLOW64) {
    //     double double_value = (double) a.x * b.y - (double) b.x * a.y;

    //     if (abs(double_value) > 1e18)
    //         return double_value > 0 ? +1 : -1;
    // }

    // uint64_t uint64_value = (uint64_t) a.x * b.y - (uint64_t) b.x * a.y;

    // if (uint64_value == 0)
    //     return 0;

    // return uint64_value < 9e18 ? +1 : -1;
}

inline bool left_turn(const point &a, const point &b, const point &c) {
    return cross_sign(b - a, c - b);
}


const int N_MAX = 1e6 + 5;

// monotonic_dp_hull enables you to do the following two operations in amortized O(1) time:
// 1. Insert a pair (a_i, b_i) into the structure. a_i must be non-decreasing.
// 2. For any value of x, query the maximum value of a_i * x + b_i. x must be non-decreasing.
// All values a_i, b_i, and x can be positive or negative.
struct monotonic_dp_hull {
    point points[N_MAX];
    int front = 0, back = 0;

    inline void insert(const point &p) {
        // if (front >= back) {
        //     points[back++] = p;
        //     return;
        // }

        // if (p.x == points[back - 1].x) {
        //     if (p.y <= points[back - 1].y)
        //         return;
        //     else
        //         back--;
        // }

        while (back - front >= 2 && left_turn(points[back - 2], points[back - 1], p))
            back--;

        points[back++] = p;
    }

    inline void insert(long long a, long long b) {
        insert(point(a, b));
    }

    // Queries the maximum value of ax + b.
    inline long long query(long long x) {
        while (back - front >= 2 && x * (points[front + 1].x - points[front].x) >= points[front].y - points[front + 1].y)
            front++;

        return points[front].x * x + points[front].y;
    }
};


struct rectangle {
    int x = 0, y = 0;
    long long cost = 0;

    bool operator<(const rectangle &other) const {
        return x < other.x;
    }
};

int N;
vector<rectangle> rect;

int main() {
    IO::read_int(N);
    rect.resize(N);

    for (rectangle &r : rect)
        IO::read_int(r.x, r.y, r.cost);

    ska_sort(rect.begin(), rect.end(), [](const rectangle &r) {
        return r.x;
    });

    monotonic_dp_hull hull;
    hull.insert(0, 0);
    long long best = 0;

    for (rectangle &r : rect) {
        long long value = (long long) r.x * r.y + hull.query(-r.y) - r.cost;
        best = max(best, value);
        hull.insert(r.x, value);
    }

    printf("%lld\n", best);
}