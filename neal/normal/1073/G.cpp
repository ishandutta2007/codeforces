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
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;

    char output_buffer[BUFFER_SIZE];
    int output_pos = 0;

    char number_buffer[100];
    uint8_t lookup[100];

    void _update_input_buffer() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;

        if (input_len == 0)
            input_buffer[0] = EOF;
    }

    inline char next_char(bool advance = true) {
        if (input_pos >= input_len)
            _update_input_buffer();

        return input_buffer[advance ? input_pos++ : input_pos];
    }

    template<typename T>
    inline void read_int(T &number) {
        bool negative = false;
        number = 0;

        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;

        do {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));

        if (negative)
            number = -number;
    }

    template<typename T, typename... Args>
    inline void read_int(T &number, Args &... args) {
        read_int(number);
        read_int(args...);
    }

    inline void read_str(string &str) {
        while (isspace(next_char(false)))
            next_char();

        str.clear();

        do {
            str += next_char();
        } while (!isspace(next_char(false)));
    }

    void _flush_output() {
        fwrite(output_buffer, sizeof(char), output_pos, stdout);
        output_pos = 0;
    }

    inline void write_char(char c) {
        if (output_pos == BUFFER_SIZE)
            _flush_output();

        output_buffer[output_pos++] = c;
    }

    template<typename T>
    inline void write_int(T number, char after = '\0') {
        if (number < 0) {
            write_char('-');
            number = -number;
        }

        int length = 0;

        while (number >= 10) {
            uint8_t lookup_value = lookup[number % 100];
            number /= 100;
            number_buffer[length++] = (lookup_value & 15) + '0';
            number_buffer[length++] = (lookup_value >> 4) + '0';
        }

        if (number != 0 || length == 0)
            write_char(number + '0');

        for (int i = length - 1; i >= 0; i--)
            write_char(number_buffer[i]);

        if (after)
            write_char(after);
    }

    void init() {
        // Make sure _flush_output() is called at the end of the program.
        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);

        for (int i = 0; i < 100; i++)
            lookup[i] = (i / 10 << 4) + i % 10;
    }
}

template<typename T>
struct RMQ {
    int n = 0, levels = 0;
    vector<vector<T>> range_min;

    RMQ(const vector<T> &values = {}) {
        if (!values.empty())
            build(values);
    }

    static int largest_bit(int x) {
        return 31 - __builtin_clz(x);
    }

    void build(const vector<T> &values) {
        n = values.size();
        levels = largest_bit(n) + 1;
        range_min.resize(levels);

        for (int k = 0; k < levels; k++)
            range_min[k].resize(n - (1 << k) + 1);

        for (int i = 0; i < n; i++)
            range_min[0][i] = values[i];

        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_min[k][i] = min(range_min[k - 1][i], range_min[k - 1][i + (1 << (k - 1))]);
    }

    T query(int a, int b) const {
        assert(a < b);
        int level = largest_bit(b - a);
        return min(range_min[level][a], range_min[level][b - (1 << level)]);
    }
};

struct suffix_array {
    int n = 0;
    vector<int> suffix;
    vector<int> rank;
    vector<int> lcp;
    RMQ<int> rmq;

    suffix_array() {}

    template<typename T_string>
    suffix_array(const T_string &str, bool build_rmq = true) {
        build(str, build_rmq);
    }

    template<typename T_string>
    void build(const T_string &str, bool build_rmq = true) {
        n = str.size();
        suffix.resize(n);

        for (int i = 0; i < n; i++)
            suffix[i] = i;

        bool large_alphabet = false;

        for (int i = 0; i < n; i++)
            if (str[i] < 0 || str[i] >= 128)
                large_alphabet = true;

        // Sort each suffix by the first character.
        if (large_alphabet) {
            sort(suffix.begin(), suffix.end(), [&](int a, int b) {
                return str[a] < str[b];
            });
        } else {
            vector<int> freq(128, 0);

            for (int i = 0; i < n; i++)
                freq[str[i]]++;

            for (int c = 1; c < 128; c++)
                freq[c] += freq[c - 1];

            for (int i = 0; i < n; i++)
                suffix[--freq[str[i]]] = i;
        }

        // Compute the rank of each suffix. Tied suffixes share the same rank.
        rank.resize(n);
        rank[suffix[0]] = 0;

        for (int i = 1; i < n; i++)
            rank[suffix[i]] = str[suffix[i]] == str[suffix[i - 1]] ? rank[suffix[i - 1]] : i;

        vector<int> next_index(n);
        vector<int> values(n);
        bool done = false;

        for (int len = 1; len < n && !done; len *= 2) {
            // next_index[i] = the next index to use for a suffix of rank i. We insert them in order of the rank of the
            // suffix that comes len characters after the current suffix.
            for (int i = 0; i < n; i++)
                next_index[i] = i;

            // Compute the suffix array for 2 * len. Suffixes of length <= len are prioritized first.
            for (int i = n - len; i < n; i++)
                values[next_index[rank[i]]++] = i;

            for (int i = 0; i < n; i++) {
                int prev = suffix[i] - len;

                if (prev >= 0)
                    values[next_index[rank[prev]]++] = prev;
            }

            swap(suffix, values);

            // Compute the rank array for 2 * len.
            values[suffix[0]] = 0;
            done = true;

            for (int i = 1; i < n; i++) {
                int s = suffix[i], prev = suffix[i - 1];

                if (s + len < n && prev + len < n && rank[s] == rank[prev] && rank[s + len] == rank[prev + len]) {
                    values[s] = values[prev];
                    done = false;
                } else {
                    values[s] = i;
                }
            }

            swap(rank, values);
        }

        compute_lcp(str);

        if (build_rmq)
            rmq.build(lcp);
    }

    template<typename T_string>
    void compute_lcp(const T_string &str) {
        lcp.assign(n, 0);
        int match = 0;

        for (int i = 0; i < n; i++) {
            if (rank[i] == 0)
                continue;

            int a = suffix[rank[i]] + match;
            int b = suffix[rank[i] - 1] + match;

            while (a < n && b < n && str[a++] == str[b++])
                match++;

            lcp[rank[i]] = match;
            match = max(match - 1, 0);
        }
    }

    int get_lcp_from_ranks(int a, int b) const {
        if (a == b)
            return n - suffix[a];

        if (a > b)
            swap(a, b);

        return rmq.query(a + 1, b + 1);
    }

    int get_lcp(int a, int b) const {
        if (a == b)
            return n - a;

        if (a >= n || b >= n)
            return 0;

        return get_lcp_from_ranks(rank[a], rank[b]);
    }
};


const int N_MAX = 2e5 + 5;

suffix_array SA;
pair<int, int> stack[2 * N_MAX];
int A[N_MAX], B[N_MAX], combined[2 * N_MAX];

long long solve_all_pairs(int *ranks, int n) {
    long long total = 0;

    // {min, count}
    int S = 0;
    long long stack_sum = 0;

    for (int i = 0; i < n; i++) {
        int lcp = i == 0 ? 0 : SA.get_lcp_from_ranks(ranks[i - 1], ranks[i]);
        int count = 1;

        while (S > 0 && lcp <= stack[S - 1].first) {
            stack_sum -= (long long) stack[S - 1].second * (stack[S - 1].first - lcp);
            count += stack[S - 1].second;
            S--;
        }

        stack[S++] = {lcp, count};
        stack_sum += lcp;
        total += stack_sum;
    }

    return total;
}

int main() {
    IO::init();
    int N, Q;
    string str;
    IO::read_int(N);
    IO::read_int(Q);
    IO::read_str(str);
    SA.build(str);

    for (int q = 0; q < Q; q++) {
        int K, L;
        IO::read_int(K);
        IO::read_int(L);

        for (int i = 0; i < K; i++) {
            IO::read_int(A[i]);
            A[i]--;
        }

        for (int i = 0; i < L; i++) {
            IO::read_int(B[i]);
            B[i]--;
        }

        for (int i = 0; i < K; i++)
            A[i] = SA.rank[A[i]];

        for (int i = 0; i < L; i++)
            B[i] = SA.rank[B[i]];

        ska_sort(A, A + K);
        ska_sort(B, B + L);
        merge(A, A + K, B, B + L, combined);
        IO::write_int(solve_all_pairs(combined, K + L) - solve_all_pairs(A, K) - solve_all_pairs(B, L), '\n');
    }
}