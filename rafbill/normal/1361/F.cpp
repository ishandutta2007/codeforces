#include <bits/stdc++.h>
#include <stdio.h>

#define FOR(i, n)     for(li i = 0; i < (li)(n); ++i)
#define FORU(i, j, k) for(li i = (j); i <= (li)(k); ++i)
#define FORD(i, j, k) for(li i = (j); i >= (li)(k); --i)

#define all(x) begin(x), end(x)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back

using namespace std;



#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>

#if WITHOUT_LI
using li = int;
using lu = unsigned;
using ld = double;
#else
using li = long long int;
using lu = long long unsigned;
using ld = long double;
#endif

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

using namespace std;
using namespace __gnu_pbds;

typedef tree<
  int,
  null_type,
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;


// --- BEGIN SNIPPET BINARY INDEXED TREE ---

struct BIT {
  vi A;
  BIT(){ }
  BIT(li n) : A(n+1){ }

  void reset(li n) { A.assign(n+1, 0); }

  li get(li i){
    i += 1;
    li r = 0;
    for(; i > 0; i -= i &-i){
      r += A[i];
    }
    return r;
  }

  li getR(li l, li r) {
    li ans = get(r);
    if(l) ans -= get(l-1);
    return ans;
  }

  void add(li i, li v){
    i += 1;
    for(; i < (li)A.size(); i += i & -i){
      A[i] += v;
    }
  }
};

// --- END SNIPPET BINARY INDEXED TREE ---

const li N = 250'000;
li to[2*N], ix[2*N];
li parent[2*N];
li S[2*N], M[2*N], E[2*N];
vi cs[2*N];
ordered_set L[2*N], R[2*N];
li total[2*N];
li bal[2*N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  li n; cin>>n;

#ifdef GEN
  srand(time(0));
  vi P(n); iota(all(P), 0); random_shuffle(all(P));
  vi W(n-1); iota(all(W), 0); random_shuffle(all(W));

  li q; cin>>q;
  vii QS(q);
  FOR(i, q) {
    li x = 0, y = 0;
    while(x == y) { x = rand()%n; y = rand()%n; }
    QS[i] = mt(x,y);
  }


#else
  vi P(n); FOR(i, n) { cin>>P[i]; P[i]--; }
  vi W(n-1); FOR(i, n-1) { cin>>W[i]; W[i]--; }

  li q; cin>>q;
  vii QS(q);
  FOR(i, q) {
    li x, y; cin>>x>>y;
    --x; --y;
    QS[i] = mt(x, y);
  }
#endif

  vi IW(n-1); FOR(i, n-1) IW[W[i]] = i;

  li cur_ans = 0;
  li nv = n;

  FOR(i, 2*n) {
    to[i] = i;
    ix[i] = i;
    parent[i] = -1;
  }

  FORD(j_, n-2, 0) {
    li j = IW[j_];
    li a = to[j];
    li b = to[j+1];
    S[nv] = a;
    M[nv] = j;
    E[nv] = b;
    total[nv] = (li)(j-a+1) * (li)(b-j);

    //cout << j << " : " << a << " .. " << b << endl;

    FORU(i, a, j) {
      L[nv].insert(-P[i]);
    }
    FORU(i, j+1, b) {
      R[nv].insert(P[i]);
    }

    bal[nv] = 0;
    FORU(i, a, j) {
      bal[nv] += R[nv].order_of_key(P[i]);
    }

    cur_ans += min(bal[nv], total[nv]-bal[nv]);

    parent[ix[a]] = nv;
    parent[ix[b]] = nv;
    cs[nv] = {ix[a], ix[b]};
    to[a] = b; ix[a] = nv;
    to[b] = a; ix[b] = nv;
    nv += 1;
  }

  //cout << "base_ans = " << cur_ans << endl;
  FOR(q_, q) {
    li x, y; tie(x,y) = QS[q_];
    if(x == y) {
      cout << cur_ans << '\n';
      continue;
    }
    if(x > y) swap(x,y);
    li ix = x;
    while(1) {
      ix = parent[ix];
      li a = S[ix], b = E[ix];
      li j = M[ix];
      if(a <= y && y <= b) break;
      cur_ans -= min(bal[ix], total[ix]-bal[ix]);
      if(x <= j) {
        bal[ix] -= R[ix].order_of_key(P[x]);
        bal[ix] += R[ix].order_of_key(P[y]);
        L[ix].erase(-P[x]);
        L[ix].insert(-P[y]);
      } else {
        bal[ix] -= L[ix].order_of_key(-P[x]);
        bal[ix] += L[ix].order_of_key(-P[y]);
        R[ix].erase(P[x]);
        R[ix].insert(P[y]);
      }
      //cout << "x " << bal[ix] << endl;
      cur_ans += min(bal[ix], total[ix]-bal[ix]);
    }
    li iy = y;
    while(1) {
      iy = parent[iy];
      li a = S[iy], b = E[iy];
      li j = M[iy];
      if(a <= x && x <= b) break;
      cur_ans -= min(bal[iy], total[iy]-bal[iy]);
      if(y <= j) {
        bal[iy] -= R[iy].order_of_key(P[y]);
        bal[iy] += R[iy].order_of_key(P[x]);
        L[iy].erase(-P[y]);
        L[iy].insert(-P[x]);
      } else {
        bal[iy] -= L[iy].order_of_key(-P[y]);
        bal[iy] += L[iy].order_of_key(-P[x]);
        R[iy].erase(P[y]);
        R[iy].insert(P[x]);
      }
      //cout << "y " << bal[iy] << endl;
      cur_ans += min(bal[iy], total[iy]-bal[iy]);
    }
    assert(ix == iy);
    {
      li a = S[ix], b = E[ix];
      li j = M[ix];
      //cout << a << " " << j << " " << b << " " << x << " " << y << endl;
      assert(x <= j);
      cur_ans -= min(bal[ix], total[ix]-bal[ix]);

      bal[ix] -= R[ix].order_of_key(P[x]);
      bal[ix] -= L[ix].order_of_key(-P[y]);

      L[ix].erase(-P[x]);
      L[ix].insert(-P[y]);
      R[ix].erase(P[y]);
      R[ix].insert(P[x]);

      bal[ix] += R[ix].order_of_key(P[y]);
      bal[ix] += L[ix].order_of_key(-P[x]);

      if(P[x] > P[y]) bal[ix] += 1;
      else bal[ix] -= 1;
      // if(P[x] < P[y]) bal[ix] += 1;
      // else bal[ix] -= 1;

      //cout << L[ix] << " " << R[ix] << " " << bal[ix] << endl;

      cur_ans += min(bal[ix], total[ix]-bal[ix]);
    }
    swap(P[x], P[y]);
    cout << cur_ans << '\n';
  }
  cout << flush;

  return 0;
}