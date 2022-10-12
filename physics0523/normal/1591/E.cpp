#include<bits/stdc++.h>

#include<bits/stdc++.h>

#include <algorithm>

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder

#include <cassert>
#include <vector>

namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    segtree(int n) : segtree(std::vector<S>(n, e())) {}
    segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder


using namespace std;
using namespace atcoder;

using Graph=vector<vector<int>>;

int op(int a, int b) { return (a+b); }

int e() { return 0; }

int target;

bool f(int v) { return v < target; }

typedef struct{
  int l,k,id;
}query;

int n;
vector<vector<int>> cd;
vector<int> a,res;
vector<int> cnt;
void rep(int v,segtree<int, op, e> &seg,vector<vector<query>> &qv,Graph &g){
  seg.set(cnt[a[v]],seg.get(cnt[a[v]])-1);
  cnt[a[v]]++;
  cd[cnt[a[v]]].push_back(a[v]);
  seg.set(cnt[a[v]],seg.get(cnt[a[v]])+1);

  // for(int i=0;i<=n;i++){
  //   cerr << seg.get(i) << ' ';
  // }cerr << '\n';
  // for(int i=0;i<=n;i++){
  //   cerr << cnt[i] << ' ';
  // }cerr << '\n';

  for(auto &nx : qv[v]){
    target=seg.prod(0,nx.l)+nx.k;
    if(target>n){res[nx.id]=-2;continue;}
    int cc=seg.max_right<f>(0);
    while(cnt[cd[cc].back()]!=cc){cd[cc].pop_back();}
    res[nx.id]=cd[cc].back();
  }
  for(auto &nx : g[v]){rep(nx,seg,qv,g);}

  seg.set(cnt[a[v]],seg.get(cnt[a[v]])-1);
  cnt[a[v]]--;
  cd[cnt[a[v]]].push_back(a[v]);
  seg.set(cnt[a[v]],seg.get(cnt[a[v]])+1);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int q;
    cin >> n >> q;
    a.resize(n);
    vector<int> p(n+2);
    for(auto &nx : a){
      cin >> nx;
      nx--;
    }
    cnt.resize(n+2);
    for(int i=0;i<n;i++){cnt[i]=0;}

    p[0]=-1;
    Graph g(n+2);
    for(int i=1;i<n;i++){
      cin >> p[i];
      p[i]--;
      g[p[i]].push_back(i);
    }

    vector<vector<query>> qv(n+2);
    for(int i=0;i<q;i++){
      int v,l,k;
      cin >> v >> l >> k;
      qv[v-1].push_back({l,k,i});
    }
    res.resize(q+2);

    cd.resize(n+2);
    for(auto &nx : cd){nx.clear();}

    vector<int> init(n+2,0);
    init[0]=n;
    init[n+1]=1e9;
    segtree<int, op, e> seg(init);
    rep(0,seg,qv,g);
    for(int i=0;i<q;i++){
      if(i){cout << ' ';}
      cout << res[i]+1;
    }cout << '\n';
  }
  return 0;
}