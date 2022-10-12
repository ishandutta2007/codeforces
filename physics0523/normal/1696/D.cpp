#pragma GCC optimize("Ofast")

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

int op_max(int a, int b) { return max(a, b); }
int e_max() { return -1e9; }
int op_min(int a, int b) { return min(a, b); }
int e_min() { return 1e9; }

using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> p(n);
    for(auto &nx : p){
      cin >> nx;
      nx--;
    }
    vector<int> inv(n);
    for(int i=0;i<n;i++){inv[p[i]]=i;}

    vector<int> maxpot(n);
    {
      segtree<int,op_max,e_max> seg(n);
      for(int i=n-1;i>=0;i--){
        maxpot[inv[i]]=max(0,seg.prod(0,inv[i]));
        seg.set(inv[i],inv[i]+1);
      }
    }
    vector<int> minpot(n);
    {
      segtree<int,op_max,e_max> seg(n);
      for(int i=0;i<n;i++){
        minpot[inv[i]]=max(0,seg.prod(0,inv[i]));
        seg.set(inv[i],inv[i]+1);
      }
    }

    // for(auto &nx : maxpot){cerr << nx << ' ';}cerr << '\n';
    // for(auto &nx : minpot){cerr << nx << ' ';}cerr << '\n';
    segtree<int,op_min,e_min> segmax(n);
    segtree<int,op_min,e_min> segmin(n);
    segmax.set(0,0);
    segmin.set(0,0);
    stack<pi> slmin,slmax;
    slmin.push({p[0],0});
    slmax.push({p[0],0});

    for(int i=1;i<n;i++){
      int cur=e_min();
      cur=min(cur,segmax.prod(maxpot[i],i)+1);
      cur=min(cur,segmin.prod(minpot[i],i)+1);
      // cout << cur << ' ';
      segmax.set(i,cur);
      segmin.set(i,cur);
      pi cp={p[i],i};

      while(!slmin.empty()){
        if(slmin.top().first>p[i]){
          pi od=slmin.top();slmin.pop();
          segmax.set(od.second,e_min());
        }
        else{break;}
      }
      slmin.push(cp);

      while(!slmax.empty()){
        if(slmax.top().first<p[i]){
          pi od=slmax.top();slmax.pop();
          segmin.set(od.second,e_min());
        }
        else{break;}
      }
      slmax.push(cp);
    }

    cout << min(segmax.get(n-1),segmin.get(n-1)) << '\n';
  }
  return 0;
}