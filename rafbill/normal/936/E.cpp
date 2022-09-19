// #pragma GCC optimize "-Ofast,unroll-loops"
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define NDEBUG 1
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


// --- BEGIN SNIPPET SEGMENT TREE ---

const lli inf = (1ll<<20);

// struct node {
//   node(){}
//   lli bestL = inf, bestR = inf;

//   inline void combine(lli sz, node &a, node& b) {
//     bestL = min(a.bestL, sz+b.bestL);
//     bestR = min(b.bestR, sz+a.bestR);
//   }

//   inline void add(lli v) {
//     bestL = min(bestL,v);
//     bestR = min(bestR,v);
//   }
// };

// --- BEGIN SNIPPET BINARY INDEXED TREE ---

struct BIT {
  vi A;
  BIT() = default;
  BIT(lli n) : A(n+1,1<<25){ }

  lli get(lli i){
    i += 1;
    lli r = 1<<25;
    for(; i > 0; i -= i &-i){
      r = min(r,A[i]);
    }
    return r;
  }

  void add(lli i, lli v){
    i += 1;
    for(; i < (lli)A.size(); i += i & -i){
      A[i] = min(v,A[i]);
    }
  }
};



// struct segment_tree {
//   int n;
//   node* A;
//   segment_tree(int n_) : n(1) {
//     while(n<n_) n+=n;
//     if(n<1000) {
//       A = pool+pnxt;
//       pnxt += (2*n);
//     }else{
//       A = new node[2*n];
//     }
//   }

//   void add_(int i, int a, int b, int l, lli v) {
//     if(a == b){
//       A[i].add(v);
//       return;
//     }
//     int c = (a+b)/2;
//     if(l <= c) add_(2*i  , a  , c, l, v);
//     else add_(2*i+1, c+1, b, l, v);
//     A[i].combine((b-a+1)/2, A[2*i],A[2*i+1]);
//   }

//   void add(int l, lli v){
//     add_(1, 0, n-1, l, v);
//   }

//   // node get_(int i, int a, int b, int l, int r) {
//   //   if(l <= a && b <= r){
//   //     return A[i];
//   //   }
//   //   int c = (a+b)/2;
//   //   if(r <= c) return get_(2*i,a,c,l,r);
//   //   if(l >= c+1) return get_(2*i+1,c+1,b,l,r);
//   //   node ar = get_(2*i  , a  , c, l, r);
//   //   node br = get_(2*i+1, c+1, b, l, r);
//   //   node res;
//   //   res.combine(ar,br);
//   //   return res;
//   // }

//   // node get(int l, int r){
//   //   return get_(1, 0, n-1, l, r);
//   // }


//   int getL_(int i, int a, int b, int l, int r) {
//     if(l <= a && b <= r){
//       return A[i].bestL;
//     }
//     int c = (a+b)/2;
//     if(r <= c) return getL_(2*i,a,c,l,r);
//     if(l >= c+1) return getL_(2*i+1,c+1,b,l,r);
//     return min(getL_(2*i  , a  , c, l, r), (c-max(l,a)+1)+getL_(2*i+1, c+1, b, l, r));
//   }

//   int getL(int l, int r){
//     return getL_(1, 0, n-1, l, r);
//   }

//   int getR_(int i, int a, int b, int l, int r) {
//     if(l <= a && b <= r){
//       return A[i].bestR;
//     }
//     int c = (a+b)/2;
//     if(r <= c) return getR_(2*i,a,c,l,r);
//     if(l >= c+1) return getR_(2*i+1,c+1,b,l,r);
//     return min((min(b,r)-(c+1)+1)+getR_(2*i  , a  , c, l, r), getR_(2*i+1, c+1, b, l, r));
//   }

//   int getR(int l, int r){
//     return getR_(1, 0, n-1, l, r);
//   }


// };


// --- END SNIPPET SEGMENT TREE ---


const int N = 3e5+16;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin>>n;
  vvi X(N);
  FOR(i,n){
    int x,y;
    cin>>x>>y;
    // x=1+i; y=1+j;
    X[x].pb(y);
  }


  map<pii,int> color;
  vvi G;
  vi GX, GF, GT;
  int ncolor = 0;
  vi lastX(N+2,-2);
  FOR(x,N) {
    sort(all(X[x]));
    int last = -1;
    for(int y : X[x]) {
      if(last == y-1) {
        color[mt(x,y)] = ncolor-1;
        GT.back() = y;
      }else{
        color[mt(x,y)] = ncolor;
        G.emplace_back();
        GX.emplace_back(x);
        GF.emplace_back(y);
        GT.emplace_back(y);
        ncolor += 1;
      }

      if(lastX[y]==x-1  && (last!=y-1|| !color.count(mt(x-1,y-1)))) {
        int u = ncolor-1;
        int v = color[mt(x-1,y)];
        G[u].pb(v);
        G[v].pb(u);
      }
      last = y;
      lastX[y] = x;
    }
  }

  vector<vector<array<int,2>>> CC(ncolor);
  FOR(i,ncolor) {
    CC[i].resize(GT[i]-GF[i]+1);
    FORU(y,GF[i],GT[i]) {
      FOR(d,2) {
        int x_ = GX[i]+(d?1:-1);
        auto it = color.find(mt(x_,y));
        if(it == color.end()) CC[i][y-GF[i]][d] = -1;
        else CC[i][y-GF[i]][d] = it->second;
      }
    }
  }

  // vector<map<pii,pii>> dists(ncolor);
  vector<vector<vector<pii>>> dists(ncolor);
  FOR(i,ncolor) dists[i].resize(GT[i]-GF[i]+1);

  vector<vector<tpl<int,tpl<int,int>>>> dist(ncolor);
  FOR(i,ncolor) dist[i].assign(GT[i]-GF[i]+1, mt(-1,pii(-1,-1)));
  int date = 0;

  vi  A(ncolor,0);
  vi  CP(ncolor,-1);
  int root;
  while(1) {
    vi E = A;
    vi P(ncolor);
    vi S(ncolor,1);
    function<void(vi&, int,int)> dfs0 = [&](vi& C, int i,int p){
      E[i]=1; P[i]=p; C.pb(i);
      for(int j : G[i]) if(!A[j] && j!=p) {
          dfs0(C,j,i);
          S[i]+=S[j];
        }
    };
    vi C;
    FOR(i,ncolor) if(!E[i]) {
      C.clear();
      dfs0(C, i, -1);
      auto f = [&](int j){
        int r=0;
        for(auto k : G[j]) if(!A[k] && k!=P[j]) r=max<int>(r,S[k]);
        r=max<int>(r,S[i]-S[j]);
        return r;
      };
      int centroid=i; int best=f(i);
      for(int j : C) {
        int v=f(j); if(v<best) { centroid=j; best=v; }
      }
      // do a dfs on this centroid subtree here :

      // map<pii,pii> dist;
      date += 1;
      FORU(y,GF[centroid],GT[centroid]) {
        dist[centroid][y-GF[centroid]] = mt(date,mt(0,y));
      }

      function<void(int,int)> dfs1 = [&](int i, int p) {
        { queue<int> Q;
          vi E(GT[i]-GF[i]+1,0);
          FORU(y, GF[i], GT[i]) if(dist[i][y-GF[i]].x() == date) {
            Q.push(y);
            E[y-GF[i]] = 1;
          }
          while(!Q.empty()) {
            int j = Q.front(); Q.pop();
            lli di,v; tie(di,v) = dist[i][j-GF[i]].y();
            if(j-1 >= GF[i] && !E[j-1-GF[i]]) {
              E[j-1-GF[i]] = 1;
              dist[i][j-1-GF[i]] = mt(date,mt(di+1,v));
              Q.push(j-1);
            }
            if(j+1 <= GT[i] && !E[j+1-GF[i]]) {
              E[j+1-GF[i]] = 1;
              dist[i][j+1-GF[i]] = mt(date,mt(di+1,v));
              Q.push(j+1);
            }
          }
        }

        FORU(y, GF[i], GT[i]) {
          lli di, v; tie(di,v) = dist[i][y-GF[i]].y();
          dists[i][y-GF[i]].pb(mt(di,v));
          FOR(d,2) {
            int c = CC[i][y-GF[i]][d];
            if(c == -1) continue;
            if(A[c]) continue;
            if(dist[c][y-GF[c]].x() != date) {
              dist[c][y-GF[c]] = mt(date,mt(di+1,v));
            }
          }
        }

        for(int j : G[i]) if(!A[j] && j != p) {
            dfs1(j,i);
          }
      };
      dfs1(centroid,-1);

      // dists[centroid] = dist;

      A[centroid]=1;
      if(CP[centroid]==-1) root=centroid;
      for(int j : C) if(j!=centroid) CP[j]=centroid;
    }
    FOR(i,ncolor) if(!A[i]) goto l_beg;
    break;
  l_beg:;
  }

  vector<BIT> L,R; L.reserve(ncolor); R.reserve(ncolor);
  FOR(i,ncolor) {
    L.emplace_back(GT[i]-GF[i]+1);
    R.emplace_back(GT[i]-GF[i]+1);
  }
  // vector<segment_tree> st;
  // FOR(i,ncolor) {
  //   st.emplace_back(GT[i]-GF[i]+1);
  // }

  int q; cin>>q;
  int niqea = 0;
  FOR(q_,q) {
    int t,x,y; cin>>t>>x>>y;
    if(t == 1) {
      niqea++;
      int c0 = color[mt(x,y)];
      int ix = dists[c0][y-GF[c0]].size()-1;
      for(int c = c0; c != -1; c = CP[c], ix--) {
        lli di,dy; tie(di,dy) = dists[c0][y-GF[c0]][ix];
        L[c].add(GT[c]-dy, di+(dy-GF[c]));
        R[c].add(dy-GF[c], di+(GT[c]-dy));
        // st[c].add(dy-GF[c], di);
      }
    }else{
      if(!niqea) {
        cout << -1 << '\n';
        continue;
      }
      lli ans = inf;
      int c0 = color[mt(x,y)];
      int ix = dists[c0][y-GF[c0]].size()-1;
      for(int c = c0; c != -1; c = CP[c], ix--) {
        lli di,dy; tie(di,dy) = dists[c0][y-GF[c0]][ix];
        ans = min(ans, di + L[c].get(GT[c]-dy) - (dy-GF[c]));
        ans = min(ans, di + R[c].get(dy-GF[c]) - (GT[c]-dy));
        // ans = min(ans, di + R[c].get(dy-GF[c]) - (GT[c]-GF[c]));
        // ans = min(ans, di+st[c].getR(0,dy-GF[c]));
        // ans = min(ans, di+st[c].getL(dy-GF[c],GT[c]-GF[c]));
      }
      cout << ans << '\n';
    }
  }

  return 0;
}