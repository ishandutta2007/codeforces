#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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

long long opx(long long a,long long b){return (a^b);}
long long ex(){return 0;}

long long op(long long a,long long b){return (a+b);}
long long e(){return 0;}

typedef struct{
  int typ;
  int l,r;
  int k;
}query;

long long get_rand(long long lim,mt19937_64 &eg){
  return (long long)(eg()%lim);
}

int main(){
  std::random_device seed_gen;
  std::mt19937_64 engine(seed_gen());
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,q;
  cin >> n >> q;
  vector<int> a(n);
  map<int,int> mp;
  for(auto &nx : a){
    cin >> nx;
    mp[nx]=1;
  }
  vector<query> qv(q);
  for(int i=0;i<q;i++){
    cin >> qv[i].typ;
    if(qv[i].typ==1){
      cin >> qv[i].l >> qv[i].r;
      qv[i].l--;
      mp[qv[i].r]=1;
    }
    else{
      cin >> qv[i].l >> qv[i].r >> qv[i].k;
      qv[i].l--;
      qv[i].r--;
    }
  }

  int id=0;
  for(auto &nx : mp){
    nx.second=id;
    id++;
  }

  for(auto &nx : a){nx=mp[nx];}
  for(auto &nx : qv){
    if(nx.typ==1){
      nx.r=mp[nx.r];
    }
  }

  vector<int> res(q,1);
  // for k=2;
  for(int tr=0;tr<5;tr++){
    vector<long long> val(id);
    for(auto &nx : val){nx=get_rand((1ll<<60),engine);}
    vector<long long> init(n,0);
    for(int i=0;i<n;i++){
      init[i]=val[a[i]];
    }

    segtree<long long,opx,ex> seg(init);
    for(int i=0;i<q;i++){
      if(qv[i].typ==1){
        seg.set(qv[i].l,val[qv[i].r]);
      }
      else if(qv[i].k==2){
        if(seg.prod(qv[i].l,qv[i].r+1)){res[i]=0;}
      }
    }
  }

  for(int tr=0;tr<30;tr++){
    vector<long long> val(id);
    for(auto &nx : val){nx=get_rand((1ll<<40),engine);}
    vector<long long> init(n,0);
    for(int i=0;i<n;i++){
      init[i]=val[a[i]];
    }

    segtree<long long,op,e> seg(init);
    for(int i=0;i<q;i++){
      if(qv[i].typ==1){
        seg.set(qv[i].l,val[qv[i].r]);
      }
      else{
        if(seg.prod(qv[i].l,qv[i].r+1)%qv[i].k){res[i]=0;}
      }
    }
  }

  for(int i=0;i<q;i++){
    if(qv[i].typ==2){
      if(res[i]==1){cout << "YES\n";}
      else{cout << "NO\n";}
    }
  }
  return 0;
}