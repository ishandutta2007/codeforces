



 #include <stdio.h>
 #include <bits/stdc++.h>
 #include <ext/pb_ds/assoc_container.hpp>






using namespace std;





template<class T, size_t... I>
void print_tuple(ostream& s, T const& a, index_sequence<I...>){
  using swallow = int[];
  (void)swallow{0, (void(s << (I == 0? "" : ", ") << get<I>(a)), 0)...};
}

template<class T>
ostream& print_collection(ostream& s, T const& a);
template<class... A>
ostream& operator<<(ostream& s, tuple<A...> const& a);
template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a);

template<class T, size_t I>
ostream& operator<<(ostream& s, array<T, I> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, vector<T> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, deque<T> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, multimap<T, U> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, multiset<T> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, map<T, U> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, set<T> const& a) { return print_collection(s, a); }

template<class T>
ostream& print_collection(ostream& s, T const& a){
  s << '[';
  for(auto it = begin(a); it != end(a); ++it){
    s << *it;
    if(it != prev(end(a))) s << " ";
  }
  return s << ']';
}

template<class... A>
ostream& operator<<(ostream& s, tuple<A...> const& a){
  s << '(';
  print_tuple(s, a, index_sequence_for<A...>{});
  return s << ')';
}

template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a){
  return s << "(" << get<0>(a) << ", " << get<1>(a) << ")";
}


static inline void debug_impl_seq() {
  cerr << "}";
}

template <class T, class... V>
void debug_impl_seq(T const& t, V const&... v) {
  cerr << t;
  if(sizeof...(v)) { cerr << ", "; }
  debug_impl_seq(v...);
}




using li = int;
using lu = unsigned;
using ld = double;






using pii = tuple<li, li>;
using piii = tuple<li, li, li>;
using piiii = tuple<li, li, li, li>;
using vi = vector<li>;
using vii = vector<pii>;
using viii = vector<piii>;
using vvi = vector<vi>;
using vvii = vector<vii>;
using vviii = vector<viii>;

template<class T>
using min_queue = priority_queue<T, vector<T>, greater<T> >;
template<class T>
using max_queue = priority_queue<T>;

struct uint64_hash {
  static inline uint64_t rotr(uint64_t x, unsigned k) {
    return (x >> k) | (x << (8U * sizeof(uint64_t) - k));
  }

  static inline uint64_t hash_int(uint64_t x) noexcept {
    auto h1 = x * (uint64_t)(0xA24BAED4963EE407);
    auto h2 = rotr(x, 32U) * (uint64_t)(0x9FB21C651E98DF25);
    auto h = rotr(h1 + h2, 32U);
    return h;
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
    return hash_int(x + FIXED_RANDOM);
  }
};

template <typename K, typename V, typename Hash = uint64_hash>
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;
template <typename K, typename Hash = uint64_hash>
using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;

struct empty_t {};

namespace tuple_access {
  struct xx_t {} xx;
  struct yy_t {} yy;
  struct zz_t {} zz;
  struct ww_t {} ww;

  template<class T>
  auto operator%(T&& v, xx_t) -> decltype(get<0>(forward<T>(v))) { return get<0>(forward<T>(v)); }
  template<class T>
  auto operator%(T&& v, yy_t) -> decltype(get<1>(forward<T>(v))) { return get<1>(forward<T>(v)); }
  template<class T>
  auto operator%(T&& v, zz_t) -> decltype(get<2>(forward<T>(v))) { return get<2>(forward<T>(v)); }
  template<class T>
  auto operator%(T&& v, ww_t) -> decltype(get<3>(forward<T>(v))) { return get<3>(forward<T>(v)); }
}
using namespace tuple_access;


template<class Fun>
class letrec_result {
  Fun fun_;
  public:
    template<class T>
    explicit letrec_result(T &&fun): fun_(forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
      return fun_(ref(*this), forward<Args>(args)...);
    }
};

template<class Fun>
decltype(auto) letrec(Fun &&fun) {
  return letrec_result<decay_t<Fun>>(forward<Fun>(fun));
}

template<class Fun>
class letrec_memo_result {
  Fun fun_;
  public:
    template<class T>
    explicit letrec_memo_result(T &&fun): fun_(forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args const&... args) {
      static map<tuple<Args...>, decltype(fun_(ref(*this), args...))> M;
      auto key = make_tuple(args...);
      auto it = M.find(key);
      if(it != M.end()) return it->second;
      auto r = fun_(ref(*this), args...);
      M[key] = r;
      return r;
    }
};

template<class Fun>
decltype(auto) letrec_memo(Fun &&fun) {
  return letrec_memo_result<decay_t<Fun>>(forward<Fun>(fun));
}

int ilog2(int x){ return 31 - __builtin_clz(x); }



li ctz(li x) { return __builtin_ctzll(x); }
li clz(li x) { return __builtin_clzll(x); }
li popcount(li x) { return __builtin_popcountll(x); }
li getbit(li x, li i){ return (x>>i)&1; }
li setbit(li x, li i) { return x|(1ll<<i); }
li unsetbit(li x, li i) { return x&~(1ll<<i); }

template <class T>
struct identity : std::unary_function <T, T> {
  T operator() (const T& x) const {return x;}
};

template<class T>
T& smin(T& x, T const& y) { x = min(x,y); return x; }

template <class T>
T& smax(T& x, T const& y) { x = max(x, y); return x; }

template<typename T>
T isqrt(T const&x){
  static_assert(is_integral<T>::value, "is_integral<T>::value");
  assert(x>=T(0));
  T ret = static_cast<T>(sqrtl(x));
  while(ret>0 && ret*ret>x) --ret;
  while(x-ret*ret>2*ret) ++ret;
  return ret;
}

template<typename T>
T icbrt(T const&x) {
  static_assert(is_integral<T>::value, "is_integral<T>::value");
  assert(x>=T(0));
  T ret = static_cast<T>(cbrt(x));
  while(ret>0 && ret*ret*ret>x) --ret;
  while(x-ret*ret*ret>3*ret*(ret+1)) ++ret;
  return ret;
}
namespace pdqsort_detail {
    enum {

        insertion_sort_threshold = 24,


        ninther_threshold = 128,



        partial_insertion_sort_limit = 8,


        block_size = 64,


        cacheline_size = 64

    };


    template<class T> struct is_default_compare : std::false_type { };
    template<class T> struct is_default_compare<std::less<T>> : std::true_type { };
    template<class T> struct is_default_compare<std::greater<T>> : std::true_type { };



    template<class T>
    inline int log2(T n) {
        int log = 0;
        while (n >>= 1) ++log;
        return log;
    }


    template<class Iter, class Compare>
    inline void insertion_sort(Iter begin, Iter end, Compare comp) {
        typedef typename std::iterator_traits<Iter>::value_type T;
        if (begin == end) return;

        for (Iter cur = begin + 1; cur != end; ++cur) {
            Iter sift = cur;
            Iter sift_1 = cur - 1;


            if (comp(*sift, *sift_1)) {
                T tmp = std::move(*sift);

                do { *sift-- = std::move(*sift_1); }
                while (sift != begin && comp(tmp, *--sift_1));

                *sift = std::move(tmp);
            }
        }
    }



    template<class Iter, class Compare>
    inline void unguarded_insertion_sort(Iter begin, Iter end, Compare comp) {
        typedef typename std::iterator_traits<Iter>::value_type T;
        if (begin == end) return;

        for (Iter cur = begin + 1; cur != end; ++cur) {
            Iter sift = cur;
            Iter sift_1 = cur - 1;


            if (comp(*sift, *sift_1)) {
                T tmp = std::move(*sift);

                do { *sift-- = std::move(*sift_1); }
                while (comp(tmp, *--sift_1));

                *sift = std::move(tmp);
            }
        }
    }




    template<class Iter, class Compare>
    inline bool partial_insertion_sort(Iter begin, Iter end, Compare comp) {
        typedef typename std::iterator_traits<Iter>::value_type T;
        if (begin == end) return true;

        int limit = 0;
        for (Iter cur = begin + 1; cur != end; ++cur) {
            if (limit > partial_insertion_sort_limit) return false;

            Iter sift = cur;
            Iter sift_1 = cur - 1;


            if (comp(*sift, *sift_1)) {
                T tmp = std::move(*sift);

                do { *sift-- = std::move(*sift_1); }
                while (sift != begin && comp(tmp, *--sift_1));

                *sift = std::move(tmp);
                limit += cur - sift;
            }
        }

        return true;
    }

    template<class Iter, class Compare>
    inline void sort2(Iter a, Iter b, Compare comp) {
        if (comp(*b, *a)) std::iter_swap(a, b);
    }


    template<class Iter, class Compare>
    inline void sort3(Iter a, Iter b, Iter c, Compare comp) {
        sort2(a, b, comp);
        sort2(b, c, comp);
        sort2(a, b, comp);
    }

    template<class T>
    inline T* align_cacheline(T* p) {



        std::size_t ip = reinterpret_cast<std::size_t>(p);

        ip = (ip + cacheline_size - 1) & -cacheline_size;
        return reinterpret_cast<T*>(ip);
    }

    template<class Iter>
    inline void swap_offsets(Iter first, Iter last,
                             unsigned char* offsets_l, unsigned char* offsets_r,
                             int num, bool use_swaps) {
        typedef typename std::iterator_traits<Iter>::value_type T;
        if (use_swaps) {


            for (int i = 0; i < num; ++i) {
                std::iter_swap(first + offsets_l[i], last - offsets_r[i]);
            }
        } else if (num > 0) {
            Iter l = first + offsets_l[0]; Iter r = last - offsets_r[0];
            T tmp(std::move(*l)); *l = std::move(*r);
            for (int i = 1; i < num; ++i) {
                l = first + offsets_l[i]; *r = std::move(*l);
                r = last - offsets_r[i]; *l = std::move(*r);
            }
            *r = std::move(tmp);
        }
    }






    template<class Iter, class Compare>
    inline std::pair<Iter, bool> partition_right_branchless(Iter begin, Iter end, Compare comp) {
        typedef typename std::iterator_traits<Iter>::value_type T;


        T pivot(std::move(*begin));
        Iter first = begin;
        Iter last = end;



        while (comp(*++first, pivot));



        if (first - 1 == begin) while (first < last && !comp(*--last, pivot));
        else while ( !comp(*--last, pivot));



        bool already_partitioned = first >= last;
        if (!already_partitioned) {
            std::iter_swap(first, last);
            ++first;
        }



        unsigned char offsets_l_storage[block_size + cacheline_size];
        unsigned char offsets_r_storage[block_size + cacheline_size];
        unsigned char* offsets_l = align_cacheline(offsets_l_storage);
        unsigned char* offsets_r = align_cacheline(offsets_r_storage);
        int num_l, num_r, start_l, start_r;
        num_l = num_r = start_l = start_r = 0;

        while (last - first > 2 * block_size) {

            if (num_l == 0) {
                start_l = 0;
                Iter it = first;
                for (unsigned char i = 0; i < block_size;) {
                    offsets_l[num_l] = i++; num_l += !comp(*it, pivot); ++it;
                    offsets_l[num_l] = i++; num_l += !comp(*it, pivot); ++it;
                    offsets_l[num_l] = i++; num_l += !comp(*it, pivot); ++it;
                    offsets_l[num_l] = i++; num_l += !comp(*it, pivot); ++it;
                    offsets_l[num_l] = i++; num_l += !comp(*it, pivot); ++it;
                    offsets_l[num_l] = i++; num_l += !comp(*it, pivot); ++it;
                    offsets_l[num_l] = i++; num_l += !comp(*it, pivot); ++it;
                    offsets_l[num_l] = i++; num_l += !comp(*it, pivot); ++it;
                }
            }
            if (num_r == 0) {
                start_r = 0;
                Iter it = last;
                for (unsigned char i = 0; i < block_size;) {
                    offsets_r[num_r] = ++i; num_r += comp(*--it, pivot);
                    offsets_r[num_r] = ++i; num_r += comp(*--it, pivot);
                    offsets_r[num_r] = ++i; num_r += comp(*--it, pivot);
                    offsets_r[num_r] = ++i; num_r += comp(*--it, pivot);
                    offsets_r[num_r] = ++i; num_r += comp(*--it, pivot);
                    offsets_r[num_r] = ++i; num_r += comp(*--it, pivot);
                    offsets_r[num_r] = ++i; num_r += comp(*--it, pivot);
                    offsets_r[num_r] = ++i; num_r += comp(*--it, pivot);
                }
            }


            int num = std::min(num_l, num_r);
            swap_offsets(first, last, offsets_l + start_l, offsets_r + start_r,
                         num, num_l == num_r);
            num_l -= num; num_r -= num;
            start_l += num; start_r += num;
            if (num_l == 0) first += block_size;
            if (num_r == 0) last -= block_size;
        }

        int l_size = 0, r_size = 0;
        int unknown_left = (last - first) - ((num_r || num_l) ? block_size : 0);
        if (num_r) {

            l_size = unknown_left;
            r_size = block_size;
        } else if (num_l) {
            l_size = block_size;
            r_size = unknown_left;
        } else {

            l_size = unknown_left/2;
            r_size = unknown_left - l_size;
        }


        if (unknown_left && !num_l) {
            start_l = 0;
            Iter it = first;
            for (unsigned char i = 0; i < l_size;) {
                offsets_l[num_l] = i++; num_l += !comp(*it, pivot); ++it;
            }
        }
        if (unknown_left && !num_r) {
            start_r = 0;
            Iter it = last;
            for (unsigned char i = 0; i < r_size;) {
                offsets_r[num_r] = ++i; num_r += comp(*--it, pivot);
            }
        }

        int num = std::min(num_l, num_r);
        swap_offsets(first, last, offsets_l + start_l, offsets_r + start_r, num, num_l == num_r);
        num_l -= num; num_r -= num;
        start_l += num; start_r += num;
        if (num_l == 0) first += l_size;
        if (num_r == 0) last -= r_size;


        if (num_l) {
            offsets_l += start_l;
            while (num_l--) std::iter_swap(first + offsets_l[num_l], --last);
            first = last;
        }
        if (num_r) {
            offsets_r += start_r;
            while (num_r--) std::iter_swap(last - offsets_r[num_r], first), ++first;
            last = first;
        }


        Iter pivot_pos = first - 1;
        *begin = std::move(*pivot_pos);
        *pivot_pos = std::move(pivot);

        return std::make_pair(pivot_pos, already_partitioned);
    }






    template<class Iter, class Compare>
    inline std::pair<Iter, bool> partition_right(Iter begin, Iter end, Compare comp) {
        typedef typename std::iterator_traits<Iter>::value_type T;


        T pivot(std::move(*begin));

        Iter first = begin;
        Iter last = end;



        while (comp(*++first, pivot));



        if (first - 1 == begin) while (first < last && !comp(*--last, pivot));
        else while ( !comp(*--last, pivot));



        bool already_partitioned = first >= last;




        while (first < last) {
            std::iter_swap(first, last);
            while (comp(*++first, pivot));
            while (!comp(*--last, pivot));
        }


        Iter pivot_pos = first - 1;
        *begin = std::move(*pivot_pos);
        *pivot_pos = std::move(pivot);

        return std::make_pair(pivot_pos, already_partitioned);
    }





    template<class Iter, class Compare>
    inline Iter partition_left(Iter begin, Iter end, Compare comp) {
        typedef typename std::iterator_traits<Iter>::value_type T;

        T pivot(std::move(*begin));
        Iter first = begin;
        Iter last = end;

        while (comp(pivot, *--last));

        if (last + 1 == end) while (first < last && !comp(pivot, *++first));
        else while ( !comp(pivot, *++first));

        while (first < last) {
            std::iter_swap(first, last);
            while (comp(pivot, *--last));
            while (!comp(pivot, *++first));
        }

        Iter pivot_pos = last;
        *begin = std::move(*pivot_pos);
        *pivot_pos = std::move(pivot);

        return pivot_pos;
    }


    template<class Iter, class Compare, bool Branchless>
    inline void pdqsort_loop(Iter begin, Iter end, Compare comp, int bad_allowed, bool leftmost = true) {
        typedef typename std::iterator_traits<Iter>::difference_type diff_t;


        while (true) {
            diff_t size = end - begin;


            if (size < insertion_sort_threshold) {
                if (leftmost) insertion_sort(begin, end, comp);
                else unguarded_insertion_sort(begin, end, comp);
                return;
            }


            diff_t s2 = size / 2;
            if (size > ninther_threshold) {
                sort3(begin, begin + s2, end - 1, comp);
                sort3(begin + 1, begin + (s2 - 1), end - 2, comp);
                sort3(begin + 2, begin + (s2 + 1), end - 3, comp);
                sort3(begin + (s2 - 1), begin + s2, begin + (s2 + 1), comp);
                std::iter_swap(begin, begin + s2);
            } else sort3(begin + s2, begin, end - 1, comp);






            if (!leftmost && !comp(*(begin - 1), *begin)) {
                begin = partition_left(begin, end, comp) + 1;
                continue;
            }


            std::pair<Iter, bool> part_result =
                Branchless ? partition_right_branchless(begin, end, comp)
                           : partition_right(begin, end, comp);
            Iter pivot_pos = part_result.first;
            bool already_partitioned = part_result.second;


            diff_t l_size = pivot_pos - begin;
            diff_t r_size = end - (pivot_pos + 1);
            bool highly_unbalanced = l_size < size / 8 || r_size < size / 8;


            if (highly_unbalanced) {

                if (--bad_allowed == 0) {
                    std::make_heap(begin, end, comp);
                    std::sort_heap(begin, end, comp);
                    return;
                }

                if (l_size >= insertion_sort_threshold) {
                    std::iter_swap(begin, begin + l_size / 4);
                    std::iter_swap(pivot_pos - 1, pivot_pos - l_size / 4);

                    if (l_size > ninther_threshold) {
                        std::iter_swap(begin + 1, begin + (l_size / 4 + 1));
                        std::iter_swap(begin + 2, begin + (l_size / 4 + 2));
                        std::iter_swap(pivot_pos - 2, pivot_pos - (l_size / 4 + 1));
                        std::iter_swap(pivot_pos - 3, pivot_pos - (l_size / 4 + 2));
                    }
                }

                if (r_size >= insertion_sort_threshold) {
                    std::iter_swap(pivot_pos + 1, pivot_pos + (1 + r_size / 4));
                    std::iter_swap(end - 1, end - r_size / 4);

                    if (r_size > ninther_threshold) {
                        std::iter_swap(pivot_pos + 2, pivot_pos + (2 + r_size / 4));
                        std::iter_swap(pivot_pos + 3, pivot_pos + (3 + r_size / 4));
                        std::iter_swap(end - 2, end - (1 + r_size / 4));
                        std::iter_swap(end - 3, end - (2 + r_size / 4));
                    }
                }
            } else {


                if (already_partitioned && partial_insertion_sort(begin, pivot_pos, comp)
                                        && partial_insertion_sort(pivot_pos + 1, end, comp)) return;
            }



            pdqsort_loop<Iter, Compare, Branchless>(begin, pivot_pos, comp, bad_allowed, leftmost);
            begin = pivot_pos + 1;
            leftmost = false;
        }
    }
}


template<class Iter, class Compare>
inline void pdqsort(Iter begin, Iter end, Compare comp) {
    if (begin == end) return;


    pdqsort_detail::pdqsort_loop<Iter, Compare,
        pdqsort_detail::is_default_compare<typename std::decay<Compare>::type>::value &&
        std::is_arithmetic<typename std::iterator_traits<Iter>::value_type>::value>(
        begin, end, comp, pdqsort_detail::log2(end - begin));




}

template<class Iter>
inline void pdqsort(Iter begin, Iter end) {
    typedef typename std::iterator_traits<Iter>::value_type T;
    pdqsort(begin, end, std::less<T>());
}

template<class Iter, class Compare>
inline void pdqsort_branchless(Iter begin, Iter end, Compare comp) {
    if (begin == end) return;
    pdqsort_detail::pdqsort_loop<Iter, Compare, true>(
        begin, end, comp, pdqsort_detail::log2(end - begin));
}

template<class Iter>
inline void pdqsort_branchless(Iter begin, Iter end) {
    typedef typename std::iterator_traits<Iter>::value_type T;
    pdqsort_branchless(begin, end, std::less<T>());
}


static struct xorshift128_t {
  uint32_t x, y, z, w;

  xorshift128_t() {
    reset(1);
  }

  inline void reset(uint64_t seed) {

    struct splitmix64_state {
      uint64_t s;

      uint64_t splitmix64() {
        uint64_t result = (s += 0x9E3779B97f4A7C15);
        result = (result ^ (result >> 30)) * 0xBF58476D1CE4E5B9;
        result = (result ^ (result >> 27)) * 0x94D049BB133111EB;
        return result ^ (result >> 31);
      }
    };

    splitmix64_state s { seed };

    x = (uint32_t)s.splitmix64();
    y = (uint32_t)s.splitmix64();
    z = (uint32_t)s.splitmix64();
    w = (uint32_t)s.splitmix64();
  }

  inline uint32_t xorshift128() {
    uint32_t t = x;
    t ^= t << 11;
    t ^= t >> 8;
    x = y; y = z; z = w;
    w ^= w >> 19;
    w ^= t;
    return w;
  }
} xorshift128_s;

void random_reset(li seed = chrono::steady_clock::now().time_since_epoch().count()) { xorshift128_s.reset(seed); }

uint32_t randomInt32() {
  return xorshift128_s.xorshift128();
}

uint64_t randomInt64() {
  return (((uint64_t)randomInt32())<<32ll) | ((uint64_t)randomInt32());
}

li random(li r) {
  return xorshift128_s.xorshift128()%r;
}

li random(li l, li r) {
  return l + random(r-l+1);
}

ld randomDouble() {
  return (ld)random(2147483648) / 2147483648.0;
}



struct BIT {
  vector<li> A;
  BIT(li n) : A(n+1, 0ll){ }

  li get(li i){
    i += 1;
    li r = 0;
    for(; i > 0; i -= i&-i) {
      r += A[i];
    }
    return r;
  }

  li getRange(li l, li r) {
    li ans = get(r);
    if(l) ans = ans - get(l-1);
    return ans;
  }

  void add(li i, li v){
    i += 1;
    for(; i < (li)A.size(); i += i&-i){
      A[i] += v;
    }
  }
};



template<typename T = string>
struct suffix_array {
  T &S;
  int N;
  vector<int> sa, isa, pos, tmp, lcp;

  suffix_array(T &S_) : S(S_), N(S_.size()), sa(N), pos(N+1), tmp(N+1), lcp(N) {
    for(li i = 0; i < (li)(N); ++i) sa[i] = i, pos[i] = S[i];
    for(int gap = 1;; gap *= 2) {
      auto sufCmp = [&](int i, int j) {
        if(pos[i] != pos[j]) return pos[i] < pos[j];
        i += gap;
        j += gap;
        return (i<N && j<N) ? pos[i]<pos[j] : i>j;
      };
      pdqsort(begin(sa), end(sa), sufCmp);
      for(li i = 0; i < (li)(N-1); ++i) tmp[i+1] = tmp[i] + sufCmp(sa[i], sa[i+1]);
      for(li i = 0; i < (li)(N); ++i) pos[sa[i]] = tmp[i];
      if(tmp[N-1] == N-1) break;
    }
    isa.resize(N);
    for(li i = 0; i < (li)(N); ++i) isa[sa[i]] = i;
    for(int i = 0, k = 0; i < N; ++i) if(pos[i] != N-1) {
        for(int j = sa[pos[i]+1]; i+k<(int)S.size() && j+k<(int)S.size() && S[i+k] == S[j+k];) k += 1;
        lcp[pos[i]] = k;
        if(k) k -= 1;
      }
  }
};


template<typename T = int, typename O = less<T> >
struct rmq {
  static int ilog2(int x){ return 31 - __builtin_clz(x); }

  vector<T> const& IN;
  int n;
  int ln;
  vector<T> A;
  vi B;

  T& getA(int i, int j) { return A[ln*i+j]; }
  li& getB(int i, int j) { return B[ln*i+j]; }

  rmq(vector<T> const& IN_) : IN(IN_) {
    n = IN.size();
    ln = ilog2(n)+1;
    A.resize(n*ln);
    B.resize(n*ln);
    for(li i = 0; i < (li)(n); ++i) getA(i, 0) = IN[i];
    for(li i = 0; i < (li)(n); ++i) getB(i, 0) = i;
    for(li j = 0; j < (li)(ln-1); ++j) for(li i = 0; i < (li)(n+1-(1<<(j+1))); ++i) {
      if(O()(getA(i, j), getA(i+(1<<j), j))){
        getA(i, j+1) = getA(i, j);
        getB(i, j+1) = getB(i, j);
      }else{
        getA(i, j+1) = getA(i+(1<<j), j);
        getB(i, j+1) = getB(i+(1<<j), j);
      }
    }
  }


  int query(int a, int b){
    int d = b-a+1;
    int ld = ilog2(d);
    if(O()(getA(a, ld), getA(b+1-(1<<ld), ld))){
      return getB(a, ld);
    }else{
      return getB(b+1-(1<<ld), ld);
    }
  }



  int queryLowR(int a, int x) {
    int lo = a, hi = query(a, n-1);
    if(IN[hi] >= x) { return n; }
    while(lo != hi) {
      int mi = (lo+hi)/2;
      if(IN[query(lo, mi)] < x) hi = mi;
      else lo = mi+1;
    }
    return lo;
  }


  int queryLowL(int a, int x) {
    int lo = -1, hi = a-1;
    if(IN[hi] < x) return a;
    while(lo != hi) {
      int mi = (lo+hi+1)/2;
      if(IN[query(mi, hi)] < x) lo = mi;
      else hi = mi-1;
    }
    return lo+1;
  }



};


int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  li n,m,q;
  cin>>n>>m>>q;

  vvi G(n);
  vector<tuple<int,int,char>> ES;
  for(li i = 0; i < (li)(n-1); ++i) {
    li u,v;
    char c;





    cin>>u>>v;
    cin>>c;
    --u; --v;

    G[u].emplace_back(v);
    G[v].emplace_back(u);
    ES.emplace_back(u,v,c);
  }

  vi par(n);
  vi sz(n,0);
  vector<char> label(n, '0');
  vi depth(n);
  auto dfs0 = letrec([&](auto dfs0, int i, int p) -> void {
    sz[i]=1;
    par[i]=p;
    depth[i] = p==-1?1:depth[p]+1;
    for(int j : G[i]) if(j != p) {
        dfs0(j,i);
        sz[i]+=sz[j];
      }
  });
  dfs0(0,-1);

  for(auto p : ES){
    int u,v,c; tie(u,v,c) = p;
    if(u==par[v]) label[v]=c;
    else label[u]=c;
  }

  vvi chains;
  vi chainOf(n);
  vi chainIx(n);
  vi chroot;
  vvi chainString;
  auto addChain = [&](int i) -> int{
    chains.emplace_back();
    chroot.emplace_back(i);
    chainString.emplace_back();
    chainString.back().emplace_back(label[i]);
    return chains.size()-1;
  };

  auto dfs1 = letrec([&](auto dfs1, int i, int p, int c) -> void {
    chains[c].emplace_back(i);
    chainOf[i] = c;
    chainIx[i] = chains[c].size()-1;
    for(int j : G[i]) if(j != p) {
        bool heavy = sz[j]>=(sz[i]+1)/2;
        if(heavy) {
          chainString[c].emplace_back(label[j]);
        }
        dfs1(j,i, heavy?c:addChain(j));
      }
  });
  dfs1(0,-1,addChain(0));

  vector<string> SS(m);
  for(li i = 0; i < (li)(m); ++i) {
    string s;



    cin>>s;

    SS[i].resize(s.size());
    for(li j = 0; j < (li)(s.size()); ++j) SS[i][j] = s[j];
  }

  vi stringAt(m);
  vi chainStringAt(chains.size());
  vi chainRevStringAt(chains.size());

  string alls;
  for(li i = 0; i < (li)(m); ++i) {
    stringAt[i] = alls.size();
    alls.insert(end(alls), begin(SS[i]), end(SS[i]));
    alls.push_back('$');
  }
  for(li i = 0; i < (li)(chains.size()); ++i) {
    chainStringAt[i] = alls.size();
    alls.insert(end(alls), begin(chainString[i]), end(chainString[i]));
    alls.push_back('+');
    vi revs; revs = chainString[i];
    reverse(begin(revs), end(revs));
    chainRevStringAt[i] = alls.size();
    alls.insert(end(alls), begin(revs), end(revs));
    alls.push_back('-');
  }



  suffix_array<string> SA(alls);
  rmq R(SA.lcp);

  vector<vector<tuple<int,int>>> events(m+1);

  struct query{
    vii dec;
  };

  vector<query> queries(q);
  vi bans(q, 0);
  vector<string> bstr(q);
  for(li qi = 0; qi < (li)(q); ++qi) {
    li i,j,l,r;




    cin>>i>>j>>l>>r;
    --i; --j; --l; --r;

    int i0=i,j0=j;

    { vii a,b;
      while(chainOf[i] != chainOf[j]) {
        if(depth[chroot[chainOf[i]]] > depth[chroot[chainOf[j]]]) {
          a.emplace_back(chainRevStringAt[chainOf[i]] + (chains[chainOf[i]].size()-1-chainIx[i]), chainIx[i]+1);

          i = par[chroot[chainOf[i]]];
        }else{
          b.emplace_back(chainStringAt[chainOf[j]], chainIx[j]+1);

          j = par[chroot[chainOf[j]]];
        }
      }

      if(chainIx[i] < chainIx[j]) {
        a.emplace_back(chainStringAt[chainOf[i]] + chainIx[i]+1, chainIx[j]-chainIx[i]);
      }else if(chainIx[i] > chainIx[j]) {
        a.emplace_back(chainRevStringAt[chainOf[i]] + (chains[chainOf[i]].size()-1-chainIx[i]), chainIx[i]-chainIx[j]);
      }
      reverse(begin(b), end(b));
      queries[qi].dec.insert(end(queries[qi].dec), begin(a), end(a));
      queries[qi].dec.insert(end(queries[qi].dec), begin(b), end(b));
    }

    events[l].emplace_back(qi,-1);
    events[r+1].emplace_back(qi,1);
  }

  auto cmp = [&](int i, int cnt, int j, int sz) -> bool {
    i = SA.isa[SA.sa[i] + cnt];
    j = SA.isa[j];
    return i < j;
  };

  auto cmplcp = [&](int i, int cnt, int j, int sz) -> int {
    i = SA.isa[SA.sa[i] + cnt];
    j = SA.isa[j];
    if(i == j) return 1;
    return SA.lcp[R.query(min(i,j),max(i,j)-1)] >= sz;
  };

  BIT bit(alls.size()+16);
  vi L(q),RR(q);
  vi ans(q);

  for(li qi = 0; qi < (li)(q); ++qi) {
    int l=0,r=alls.size()-1;
    int cnt=0;
    for(auto q : queries[qi].dec) {
      int j,sz; tie(j,sz) = q;


      int x = -1;
      { li lo=l, hi=r;
        while(lo != hi) {
          li mi = (lo+hi)/2;
          if(cmp(mi,cnt,j,sz)) lo = mi+1;
          else hi = mi;
        }
        if(cmplcp(lo,cnt,j,sz)) x = lo;
        else if(lo+1 <= r && cmplcp(lo+1,cnt,j,sz)) x = lo+1;
        else if(lo-1 >= l && cmplcp(lo-1,cnt,j,sz)) x = lo-1;
      }
      if(x == -1) goto lfail;
      l = R.queryLowL(x, sz+cnt);
      r = R.queryLowR(x, sz+cnt);
      cnt += sz;
      if(qi == 12) {
    }
    }
    L[qi] = l; RR[qi] = r;
    continue;
  lfail:;
    L[qi] = 1;
    RR[qi] = 0;
  }





  for(li i = 0; i < (li)(m+1); ++i) {
    for(auto p : events[i]) {
      int qi,mult; tie(qi,mult) = p;
      if(L[qi]<=RR[qi]) ans[qi] += mult * (bit.get(RR[qi]+1)-bit.get(L[qi]));
    }
    if(i != m) {
      for(li j = 0; j < (li)(SS[i].size()); ++j) {
        bit.add(SA.isa[stringAt[i]+j]+1, 1);
      }
    }
  }






  for(li i = 0; i < (li)(q); ++i) cout << ans[i] << '\n';
  cout << flush;

  return 0;
}