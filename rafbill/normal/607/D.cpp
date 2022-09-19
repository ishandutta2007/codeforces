#include <bits/stdc++.h>

#define FOR(i, n)     for(lli i = 0; i < (lli)(n); ++i)
#define FORU(i, j, k) for(lli i = (j); i <= (lli)(k); ++i)
#define FORD(i, j, k) for(lli i = (j); i >= (lli)(k); --i)

#define X(A) get<0>(A)
#define Y(A) get<1>(A)
#define Z(A) get<2>(A)

#define mp make_pair
#define mt make_tuple
#define pb push_back

//------------------------------------------------------------------------------

using namespace std;
using lli = long long int;
using llu = long long unsigned;

using pii   = tuple<lli, lli>;
using ppii  = tuple<pii, pii>;
using piii  = tuple<lli, lli, lli>;
using vi    = vector<lli>;
using vii   = vector<pii>;
using viii  = vector<piii>;
using vvi   = vector<vi>;
using vvii  = vector<vii>;
using vviii = vector<viii>;
using pt    = complex<lli>;

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
ostream& operator<<(ostream& s, vector<T> const& a){
  s << '[';
  FOR(i, a.size()){
    s << a[i];
    if(i != (lli)a.size()-1) s << " ";
  }
  return s << ']';
}

//------------------------------------------------------------------------------

const lli MOD = 1e9+7;

lli fexp(lli a, lli b){
  lli r = 1;
  while (b){
    if (b%2==1){
      r = (r*a)%MOD;
    }
    b /= 2;
    a = (a*a)%MOD;
  }
  return r;
}

struct tnode {
  tnode() : sum(0), dsum(0), dmult(1){ }
  lli sum, dsum, dmult;
};

ostream& operator<<(ostream& s, tnode const& a){
  return s << mt(a.sum, a.dsum, a.dmult);
}

struct tree {
  lli n;
  vector<tnode> A;
  tree(lli n_) : n((lli)1<<(lli)(log2(n_)+1)), A(2*n) { }

  void push(lli i, lli a, lli b){
    if(i < n){
      lli c = (a+b)/2;
      if(A[i].dsum){
        add__(2*i  , a  , c, A[i].dsum);
        add__(2*i+1, c+1, b, A[i].dsum);
        A[i].dsum = 0;
      }
      if(A[i].dmult != 1){
        mult__(2*i  , a  , c, A[i].dmult);
        mult__(2*i+1, c+1, b, A[i].dmult);
        A[i].dmult = 1;
      }
    }
  }

  void update(lli i){
    A[i].sum = (A[2*i].sum + A[2*i+1].sum) % MOD;
  }

  void add__(lli i, lli a, lli b, lli v){
    (A[i].dsum += v) %= MOD;
    (A[i].sum += (b-a+1) * v) %= MOD;
  }

  void add_(lli i, lli a, lli b, lli l, lli r, lli v){
    if(l > b) return;
    if(r < a) return;
    push(i, a, b);
    if(l <= a && b <= r){
      add__(i, a, b, v);
      return;
    }
    lli c = (a+b)/2;
    add_(2*i  , a  , c, l, r, v);
    add_(2*i+1, c+1, b, l, r, v);
    update(i);
  }

  void add(lli l, lli r, lli v){
    add_(1, 0, n-1, l, r, v);
  }

  void mult__(lli i, lli, lli, lli v){
    (A[i].dmult *= v) %= MOD;
    (A[i].sum *= v) %= MOD;
  }

  void mult_(lli i, lli a, lli b, lli l, lli r, lli v){
    if(l > b) return;
    if(r < a) return;
    push(i, a, b);
    if(l <= a && b <= r){
      mult__(i, a, b, v);
      return;
    }
    lli c = (a+b)/2;
    mult_(2*i  , a  , c, l, r, v);
    mult_(2*i+1, c+1, b, l, r, v);
    update(i);
  }

  void mult(lli l, lli r, lli v){
    mult_(1, 0, n-1, l, r, v);
  }

  lli query_(lli i, lli a, lli b, lli l, lli r){
    if(l > b) return 0;
    if(r < a) return 0;
    push(i, a, b);
    if(l <= a && b <= r){
      return A[i].sum;
    }
    lli c = (a+b)/2;
    return (query_(2*i  , a  , c, l, r)
            + query_(2*i+1, c+1, b, l, r)) % MOD;
  }

  lli query(lli l, lli r){
    return query_(1, 0, n-1, l, r);
  }
};

struct query {
  lli type;
  lli vertex;
};

int main(int, char**){
  ios::sync_with_stdio(false);

  lli v1, q; cin >> v1 >> q;

  vvi A(1);
  vi  V(1); V[0] = v1;
  vi  P(1); P[0] = -1;
  vi  W(1); W[0] = 1;

  vector<query> Q;

  { query q0; q0.type = 1; q0.vertex = 0; Q.pb(q0); }

  FOR(i, q){
    query qu; cin >> qu.type;
    if(qu.type == 1) {
      lli p, v; cin >> p >> v; p -= 1;
      qu.vertex = A.size();
      A.pb(vi());
      V.pb(v);
      A[p].pb(qu.vertex);
      P.pb(p);
      W.pb(1);
    } else {
      lli u; cin >> u; u -= 1;
      qu.vertex = u;
    }
    Q.pb(qu);
  }

  lli n = A.size();

  vi F(n), T(n);
  lli cpos = 0;
  function<void(lli)> dfs_size = [&](lli i) {
    F[i] = cpos; cpos += 1;
    for(auto j : A[i]) { dfs_size(j); }
    T[i] = cpos - 1;
  };
  dfs_size(0);

  tree t(cpos);

  for(auto q : Q){
    if(q.type == 1){
      auto u = q.vertex;
      auto p = P[u];
      if(p != -1){
        W[p] += 1;
        t.mult(F[p], T[p], (W[p]*fexp(W[p]-1, MOD-2))%MOD);
        auto m = t.query(F[p], F[p]);
        (m *= fexp(V[p], MOD-2)) %= MOD;
        (m *= V[u]) %= MOD;
        t.add(F[u], F[u], m);
      }else{
        t.add(F[u], F[u], V[u]);
      }
    }else{
      auto u = q.vertex;
      auto v = t.query(F[u], T[u]);
      (v *= fexp(t.query(F[u], F[u]), MOD-2)) %= MOD;
      (v *= V[u]) %= MOD;
      (v *= W[u]) %= MOD;
      cout << v << endl;
    }
  }

  return 0;
}