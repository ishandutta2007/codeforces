#ifndef __clang__
#pragma GCC optimize "-O3"
#pragma GCC target "tune=native"
#endif
#ifdef ONLINE_JUDGE
#define NDEBUG 1
#endif
#include <stdio.h>
#include <bits/stdc++.h>

#define FOR(i, n)     for(lli i = 0; i < (lli)(n); ++i)
#define FORU(i, j, k) for(lli i = (j); i <= (lli)(k); ++i)
#define FORD(i, j, k) for(lli i = (j); i >= (lli)(k); --i)

#define SQ(x) ((x)*(x))

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back

using namespace std;

template<typename... As>
struct tpl : public std::tuple<As...> {
  using std::tuple<As...>::tuple;
  tpl(){}
  tpl(std::tuple<As...> const& b) { std::tuple<As...>::operator=(b); }

  template<typename T = tuple<As...> >
  typename tuple_element<0, T>::type const&
  x() const { return get<0>(*this); }
  template<typename T = tuple<As...> >
  typename tuple_element<0, T>::type&
  x() { return get<0>(*this); }

  template<typename T = tuple<As...> >
  typename tuple_element<1, T>::type const&
  y() const { return get<1>(*this); }
  template<typename T = tuple<As...> >
  typename tuple_element<1, T>::type&
  y() { return get<1>(*this); }

  template<typename T = tuple<As...> >
  typename tuple_element<2, T>::type const&
  z() const { return get<2>(*this); }
  template<typename T = tuple<As...> >
  typename tuple_element<2, T>::type&
  z() { return get<2>(*this); }

  template<typename T = tuple<As...> >
  typename tuple_element<3, T>::type const&
  w() const { return get<3>(*this); }
  template<typename T = tuple<As...> >
  typename tuple_element<3, T>::type&
  w() { return get<3>(*this); }
};

using lli   = int;
using llu   = long long unsigned;

using pii   = tpl<lli, lli>;
using piii  = tpl<lli, lli, lli>;
using piiii = tpl<lli, lli, lli, lli>;
using vi    = vector<lli>;
using vii   = vector<pii>;
using viii  = vector<piii>;
using vvi   = vector<vi>;
using vvii  = vector<vii>;
using vviii = vector<viii>;

template<class T>
using min_queue = priority_queue<T, vector<T>, greater<T> >;
template<class T>
using max_queue = priority_queue<T>;

template<size_t... I>
struct my_index_sequence {
  using type = my_index_sequence;
  static constexpr array<size_t, sizeof...(I)> value = { {I...} };
};

namespace my_index_sequence_detail {
  template<typename I, typename J> struct concat;
  template<size_t... I, size_t... J>
  struct concat<my_index_sequence<I...>, my_index_sequence<J...> > :
    my_index_sequence<I..., (sizeof...(I)+J)...> { };
  template<size_t N> struct make_index_sequence :
    concat<typename make_index_sequence<N/2>::type, typename make_index_sequence<N-N/2>::type>::type { };
  template <> struct make_index_sequence<0> : my_index_sequence<>{};
  template <> struct make_index_sequence<1> : my_index_sequence<0>{};
}

template<class... A>
using my_index_sequence_for = typename my_index_sequence_detail::make_index_sequence<sizeof...(A)>::type;

template<class T, size_t... I>
void print_tuple(ostream& s, T const& a, my_index_sequence<I...>){
  using swallow = int[];
  (void)swallow{0, (void(s << (I == 0? "" : ", ") << get<I>(a)), 0)...};
}

template<class T>
ostream& print_collection(ostream& s, T const& a);
template<class... A>
ostream& operator<<(ostream& s, tpl<A...> const& a);
template<class... A>
ostream& operator<<(ostream& s, tuple<A...> const& a);
template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a);

template<class T, size_t I>
ostream& operator<<(ostream& s, array<T, I> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, vector<T> const& a) { return print_collection(s, a); }
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
ostream& operator<<(ostream& s, tpl<A...> const& a){
  s << '(';
  print_tuple(s, a, my_index_sequence_for<A...>{});
  return s << ')';
}

template<class... A>
ostream& operator<<(ostream& s, tuple<A...> const& a){
  s << '(';
  print_tuple(s, a, my_index_sequence_for<A...>{});
  return s << ')';
}

template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a){
  return s << "(" << get<0>(a) << ", " << get<1>(a) << ")";
}

//------------------------------------------------------------------------------

// --- BEGIN SNIPPET SUFFIX AUTOMATON ---


const int BSIZE = 300;
struct SuffixAutomaton {
  int edges[26][1+BSIZE * 2], link[1+BSIZE * 2], length[1+BSIZE * 2], isTerminal[1+BSIZE * 2], dp1[1+BSIZE * 2], last;
  int sz;
  SuffixAutomaton() {
    last = 0;
    sz = 0;
  }

  void set(int k) {
    for(int i = 0; i < 26; ++i) edges[i][k] = -1;
  }

  void build(char *s, int size) {
    link[0] = -1;
    length[0] = 0;
    last = 0;
    sz = 1;
    set(0);

    for(int i=0;i<size;i++) {
      set(sz);
      length[sz] = i+1;
      link[sz] = 0;
      int r = sz;
      ++sz;

      int p = last;
      while(p >= 0 && edges[s[i]-'a'][p] == -1) {
        edges[s[i] - 'a'][p] = r;
        p = link[p];
      }
      if(p != -1) {
        int q = edges[s[i] - 'a'][p];
        if(length[p] + 1 == length[q]) {
          link[r] = q;
        } else {
          for(int i = 0; i < 26; ++i) {
            edges[i][sz] = edges[i][q];
          }
          length[sz] = length[p] + 1;
          link[sz] = link[q];
          int qq = sz;
          ++sz;
          link[q] = qq;
          link[r] = qq;
          while(p >= 0 && edges[s[i] - 'a'][p] == q) {
            edges[s[i] - 'a'][p] = qq;
            p = link[p];
          }
        }
      }
      last = r;
    }
    for(int i = 0; i < sz; ++i) isTerminal[i] = 0, dp1[i] = -1;
    int p = last;
    while(p > 0) {
      isTerminal[p] = 1;
      p = link[p];
    }
  }

  int solve(int pos) {
    if(dp1[pos] != -1) return dp1[pos];
    dp1[pos] = isTerminal[pos];
    for(int i=0; i<26; ++i){
      if(edges[i][pos] != -1) dp1[pos] += solve(edges[i][pos]);
    }
    return dp1[pos];
  }

  int run(char const* sq) {
    int cur = 0;
    for(int i=0; sq[i] != '\0'; ++i) {
      auto it = edges[sq[i] - 'a'][cur];
      if(it == -1) return 0;
      else cur = it;
    }
    return solve(cur);
  }
};

// struct SuffixAutomaton {
//   using Key = char;
//   using Map = map<Key, int>;
//   vector<Map> edges;  // edges[i]  : the labeled edges from node i
//   vi link;            // link[i]   : the parent of i
//   vi length;          // length[i] : the length of the longest string in the ith class
//   int last;           // the index of the equivalence class of the whole string
//   vi terminals;
//   set<int> isT;
//   vi sol;

//   SuffixAutomaton(){}

//   void make(char const* s, int size) {
//     edges.clear(); link.clear(); length.clear(); terminals.clear(); isT.clear(); sol.clear();
//     // add the initial node
//     edges.pb(Map()); link.pb(-1); length.pb(0);
//     last = 0;

//     FOR(i, size) {
//       // construct r
//       edges.pb(Map()); length.pb(i+1); link.pb(0);
//       int r = edges.size() - 1;

//       // add edges to r and find p with link to q
//       int p = last;
//       while(p >= 0 && edges[p].find(s[i]) == edges[p].end()) {
//         edges[p][s[i]] = r;
//         p = link[p];
//       }
//       if(p != -1) {
//         int q = edges[p][s[i]];
//         if(length[p] + 1 == length[q]) {
//           // we do not have to split q, just set the correct suffix link
//           link[r] = q;
//         } else {
//           // we have to split, add q'
//           edges.pb(edges[q]); // copy edges of q
//           length.pb(length[p] + 1);
//           link.pb(link[q]); // copy parent of q
//           int qq = edges.size()-1;
//           // add qq as the new parent of q and r
//           link[q] = qq;
//           link[r] = qq;
//           // move short classes pointing to q to point to q'
//           while(p >= 0 && edges[p][s[i]] == q) {
//             edges[p][s[i]] = qq;
//             p = link[p];
//           }
//         }
//       }
//       last = r;
//     }

//     int p = last;
//     while(p > 0) {
//       terminals.push_back(p);
//       isT.insert(p);
//       p = link[p];
//     }
//     sol.assign(edges.size(),0);
//     FOR(i,edges.size()) {
//       if(isT.count(i)) sol[i] += 1;
//       for(auto p : edges[i]) sol[i] += sol[p.second];
//     }
//   }

//   int next(int s, Key c) {
//     if(s==-1) return -1;
//     auto it = edges[s].find(c);
//     return it!=edges[s].end()?it->second:-1;
//   }

//   lli get(int s) {
//     if(s == -1) return 0;
//     return sol[s];
//     // if(sol[s] == -1) {
//     //   sol[s] = 0;
//     //   if(isT.count(s)) sol[s] += 1;
//     //   for(auto p : edges[s]) sol[s] += get(p.second);
//     // }
//     // return sol[s];
//   }
// };

// --- END SNIPPET SUFFIX AUTOMATON ---

vi kmp_build(string const& s){
  int n = s.size();
  vi T(n+1);
  T[0] = -1;
  FOR(i, n) {
    int b = T[i];
    while(b != -1 && s[i] != s[b]) b = T[b];
    T[i+1] = b+1;
  }
  return T;
}

int kmp_next(string const& s, vi const& T, int i, int x){
  while(i != -1 && x != s[i]) i = T[i];
  return i+1;
}


SuffixAutomaton B[100000/BSIZE+10];
int clean[100000/BSIZE+10];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
#ifdef LOCAL
  FOR(i,100000) s += (rand()&1)?'a':'a';
#else
  cin>>s;
#endif

  int n = s.size();
  int nblock = (n+BSIZE-1)/BSIZE;
  int q; cin>>q;
  FOR(q_,q) {
    int ty;
#ifdef LOCAL
    ty = rand()%2 + 1;
#else
    cin>>ty;
#endif

    if(ty == 1) {
      int i; char c;
#ifdef LOCAL
      i = rand()%n;
      c = (rand()&1)?'a':'b';
#else
      cin>>i>>c;
      --i;
#endif
      if(s[i] == c) continue;
      s[i] = c;
      clean[i/BSIZE] = 0;


    }else{
      lli l,r; string y;
#ifdef LOCAL
      l = rand()%n, r = rand()%n;
      if(l>r) swap(l,r);
      FOR(i,50) y += (rand()&1)?'a':'a';
#else
      cin>>l>>r>>y;
      --l; --r;
#endif
      lli ans = 0;
      if(y.size() > 150) {
        auto T = kmp_build(y);
        lli S = 0;
        FORU(i,l,r) {
          S = kmp_next(y,T,S,s[i]);
          if(S == (int)y.size()) ans += 1;
        }
      }else{
        lli bl = l/BSIZE;
        lli br = r/BSIZE;
        auto T = kmp_build(y);
        { lli S = 0;
          FORU(i,l,min(r,(bl+1)*BSIZE-1)) {
            S = kmp_next(y,T,S,s[i]);
            if(S == (int)y.size()) ans += 1;
          }
        }
        if(bl != br) {
          lli S = 0;
          FORU(i,br*BSIZE,r) {
            S = kmp_next(y,T,S,s[i]);
            if(S == (int)y.size()) ans += 1;
          }
        }
        FORU(b, bl+1, br-1) {
          if(!clean[b]) {
            clean[b] = 1;
            B[b].build(&s[b*BSIZE], min<int>(BSIZE, s.size()-b*BSIZE));
          }
          ans += B[b].run(y.c_str());
        }
        FORU(b,bl,br-1) {
          int S = 0;
          int from = max<int>(l,(b+1)*BSIZE - y.size() + 1);
          int to = min<int>(r, (b+1)*BSIZE + y.size() - 2);
          FORU(i, from, to) {
            S = kmp_next(y,T,S,s[i]);
            if(S == (int)y.size()) ans += 1;
          }
        }
      }
      cout << ans << '\n';
    }
  }
  return 0;
}