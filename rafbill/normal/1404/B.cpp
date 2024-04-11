


 #include <stdio.h>
 #include <bits/stdc++.h>






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







using li = long long int;
using lu = long long unsigned;
using ld = long double;


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

struct empty_t {};



namespace tuple_access {

  struct xx_t {} xx;
  struct yy_t {} yy;
  struct zz_t {} zz;
  struct ww_t {} ww;

  template<class T>
  typename tuple_element<0,T>::type& operator^(T& v, xx_t) { return get<0>(v); }
  template<class T>
  typename tuple_element<0,T>::type const& operator^(T const& v, xx_t) { return get<0>(v); }
  template<class T>
  typename tuple_element<0,T>::type&& operator^(T&& v, xx_t) { return get<0>(v); }

  template<class T>
  typename tuple_element<1,T>::type& operator^(T& v, yy_t) { return get<1>(v); }
  template<class T>
  typename tuple_element<1,T>::type const& operator^(T const& v, yy_t) { return get<1>(v); }
  template<class T>
  typename tuple_element<1,T>::type&& operator^(T&& v, yy_t) { return get<1>(v); }

  template<class T>
  typename tuple_element<2,T>::type& operator^(T& v, zz_t) { return get<2>(v); }
  template<class T>
  typename tuple_element<2,T>::type const& operator^(T const& v, zz_t) { return get<2>(v); }
  template<class T>
  typename tuple_element<2,T>::type&& operator^(T&& v, zz_t) { return get<2>(v); }

  template<class T>
  typename tuple_element<3,T>::type& operator^(T& v, ww_t) { return get<3>(v); }
  template<class T>
  typename tuple_element<3,T>::type const& operator^(T const& v, ww_t) { return get<3>(v); }
  template<class T>
  typename tuple_element<3,T>::type&& operator^(T&& v, ww_t) { return get<3>(v); }
}
using namespace tuple_access;


int ilog2(int x){ return 31 - __builtin_clz(x); }

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

void solve(){
  int n, a, b, da, db; cin>>n>>a>>b>>da>>db;
  --a; --b;

  vvi G(n);
  for(li i = 0; i < (li)(n-1); ++i) {
    int u,v ; cin>>u>>v;
    --u; --v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  if(a == b || db <= 2*da) {
    cout << "Alice" << endl;
    return;
  }

  int dd = 0, dab = 0;
  function<int(int,int,int)> dfs = [&](int i, int p, int dp) -> int {
    if(i == b) dab = dp;
    int h = 0;
    vector<int> hs;
    for(int j : G[i]) if(j != p) {
        int hj = dfs(j,i,dp+1);
        hs.push_back(hj+1);
        h = max(h, 1+hj);
      }
    pdqsort(begin(hs), end(hs)); reverse(begin(hs), end(hs));
    if(hs.size() >= 2) dd = max(dd, hs[0]+hs[1]);
    if(hs.size() >= 1) dd = max(dd, hs[0]);
    return h;
  };
  dfs(a, -1, 0);

  if(dd <= 2*da || dab <= da) cout << "Alice" << endl;
  else cout << "Bob" << endl;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  for(li i = 0; i < (li)(t); ++i) solve();

  return 0;
}