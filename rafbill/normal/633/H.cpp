#pragma GCC optimize ("-O3")
#define _GLIBCXX_USE_CXX11_ABI 0
#include <bits/stdc++.h>

#define FOR(i, n)     for(lli i = 0; i < (lli)(n); ++i)
#define FORU(i, j, k) for(lli i = (j); i <= (lli)(k); ++i)
#define FORD(i, j, k) for(lli i = (j); i >= (lli)(k); --i)

#define X(A) get<0>(A)
#define Y(A) get<1>(A)
#define Z(A) get<2>(A)
#define W(A) get<3>(A)

#define all(x) begin(x),end(x)

#define mp make_pair
#define mt make_tuple
#define pb push_back

#ifdef DEBUG
#define DB(x) x
#else
#define DB(x)
#endif

//------------------------------------------------------------------------------

using namespace std;
using lli = int;

using pii   = tuple<lli, lli>;
using ppii  = tuple<pii, pii>;
using piii  = tuple<lli, lli, lli>;
using vi    = vector<lli>;
using vii   = vector<pii>;
using viii  = vector<piii>;
using vvi   = vector<vi>;
using vvii  = vector<vii>;
using vviii = vector<viii>;

//------------------------------------------------------------------------------

template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a){
  return s << "(" << X(a) << "," << Y(a) << ")";
}

template<class A, class B>
ostream& operator<<(ostream& s, tuple<A, B> const& a){
  return s << "(" << X(a) << "," << Y(a) << ")";
}

template<class A, class B, class C>
ostream& operator<<(ostream& s, tuple<A, B, C> const& a){
  return s << "(" << X(a) << "," << Y(a) << "," << Z(a) << ")";
}

template<class T>
ostream& print_collection(ostream& s, T const& a){
  s << '[';
  for(auto it = begin(a); it != end(a); ++it){
    s << *it;
    if(it != prev(end(a))) s << " ";
  }
  return s << ']';
}

template<class T, size_t I>
ostream& operator<<(ostream& s, array<T, I> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, vector<T> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, multimap<T, U> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, map<T, U> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, set<T> const& a) { return print_collection(s, a); }

//------------------------------------------------------------------------------

lli n, m;
lli F[100000];

//------------------------------------------------------------------------------

struct node {
  node() { }
  lli v  = 0;
  lli s1 = 0, s2 = 0;
  lli shiftBy = 0;
};

struct tree {
  lli n;
  vector<node> A;
  tree(lli n_) : n((lli)1<<(lli)(log2(n_)+1)), A(2*n) { }

  void print_tree_(lli i, lli a, lli b, lli in){
    push(i, a, b);
    lli c = (a+b)/2;
    if(i<n) print_tree_(2*i, a, c, in+1);
    FOR(i, in) cout << "  ";
    cout << "| " << i << " " << A[i].v; // << " " << A[i].s1 << " " << A[i].s2;
    cout << endl;
    if(i<n) print_tree_(2*i+1, c+1, b, in+1);
  }

  void print_tree(){
    print_tree_(1, 0, n-1, 0);
  }

  void push(lli i, lli a, lli b){
    if(i < n){
      lli c = (a+b)/2;
      if(A[i].shiftBy){
        shift__(2*i  , a  , c, A[i].shiftBy);
        shift__(2*i+1, c+1, b, A[i].shiftBy);
        A[i].shiftBy = 0;
      }
    }
  }

  void build(){
    FORD(i, n-1, 0) update(i);
  }

  void update(lli i){
    A[i].s1 = (A[2*i].s1 + A[2*i+1].s1)%m;
    A[i].s2 = (A[2*i].s2 + A[2*i+1].s2)%m;
  }

  void shift__(lli i, lli a, lli b, lli v){
    if(v){
      A[i].shiftBy += v;
      A[i].v += v;
      lli ns1 = F[49999+v] * A[i].s1 + F[50000+v] * A[i].s2;
      lli ns2 = F[50000+v] * A[i].s1 + F[50001+v] * A[i].s2;
      A[i].s1 = ns1%m;
      A[i].s2 = ns2%m;
    }
  }

  void shift_(lli i, lli a, lli b, lli l, lli r, lli v, lli x){
    if(l > b) return;
    if(r < a) return;
    if(l <= a && b <= r){
      if(l == a) insert_(i, a, b, l, x);
      shift__(i, a, b, v);
      return;
    }
    push(i, a, b);
    lli c = (a+b)/2;
    shift_(2*i  , a  , c, l, r, v, x);
    shift_(2*i+1, c+1, b, l, r, v, x);
    update(i);
  }

  void shift(lli l, lli r, lli v, lli x){
    shift_(1, 0, n-1, l, r, v, x);
  }

  void insert_(lli i, lli a, lli b, lli l, lli v){
    if(l > b) return;
    if(l < a) return;
    push(i, a, b);
    if(l <= a && b <= l){
      A[i].s1 = (F[50000+A[i].v] * v)%m;
      A[i].s2 = (F[50001+A[i].v] * v)%m;
      return;
    }
    lli c = (a+b)/2;
    insert_(2*i  , a  , c, l, v);
    insert_(2*i+1, c+1, b, l, v);
    update(i);
  }

  lli query(){
    return A[1].s1%m;
  }
};


//------------------------------------------------------------------------------

int main(int, char**){
  srand(time(0));
  ios::sync_with_stdio(false);

#ifdef RAND
  n = 30000;
  m = 5000; // < n : duplicates
#else
  scanf("%d%d", &n, &m);
#endif

  F[50000] = 0; F[50001] = 1;
  FORU(i, 50002, 99999) F[i] = (F[i-2]+F[i-1])%m;
  FORD(i, 49999, 0) F[i] = (F[i+2]-F[i+1]+m+m)%m;

  vi A(n);
#ifdef RAND
  FOR(i, n) A[i] = rand()%100000000;
#else
  FOR(i, n) scanf("%d", &A[i]);
#endif

  set<lli> AS;
  FOR(i, n) AS.insert(A[i]);
  lli ni = 0;
  unordered_map<lli, lli> TOI;
  for(auto x : AS) { TOI[x] = ni; ni += 1; }

  tree t(ni);

  lli q;
#ifdef RAND
  q = 30000;
#else
  scanf("%d", &q);
#endif
  vii Q(q);
#ifdef RAND
  FOR(i, q) {
    lli x = rand()%n;
    lli y = rand()%n;
    if(y < x) swap(x, y);
    Q[i] = mt(x, y);
  }
#else
  FOR(i, q) scanf("%d%d", &X(Q[i]), &Y(Q[i]));
  FOR(i, q) X(Q[i]) -= 1;
  FOR(i, q) Y(Q[i]) -= 1;
#endif

  lli bsize = 250;
  vi I(q); FOR(i, q) I[i] = i;
  sort(all(I), [&](lli a, lli b){
      return pii(X(Q[a])/bsize, Y(Q[a])) < mt(X(Q[b])/bsize, Y(Q[b]));
    });
  vi ANS(q);

  unordered_map<lli, lli> M;
  auto mo_add = [&](lli x) {
    if(M[x] == 0) {
      t.shift(TOI[x], ni-1, 1, x%m);
      // t.insert(TOI[x], x%m);
    }
    M[x] += 1;
  };
  auto mo_remove = [&](lli x){
    M[x] -= 1;
    if(M[x] == 0){
      // t.insert(TOI[x], 0);
      t.shift(TOI[x], ni-1, -1, 0);
    }
  };

  lli cl = 0, cr = -1;
  FOR(i, q){
#ifdef RAND
    if(i%500==0) cout << i << endl;
#endif
    lli l = X(Q[I[i]]), r = Y(Q[I[i]]);
    while(cr < r) { cr += 1; mo_add(A[cr]); }
    while(cl > l) { cl -= 1; mo_add(A[cl]); }
    while(cr > r) { mo_remove(A[cr]); cr -= 1; }
    while(cl < l) { mo_remove(A[cl]); cl += 1; }
    ANS[I[i]] = t.query();
  }
#ifndef RAND
  FOR(i, q) cout << ANS[i] << '\n';
  cout << flush;
#endif
  return 0;
}