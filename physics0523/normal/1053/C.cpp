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

long long op(long long a,long long b) { return a+b; }

long long e() { return 0; }

long long target;

bool f(long long v) { return v <= target; }

#define mod 1000000007

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,q;
  cin >> n >> q;
  vector<long long> a(n+1);
  vector<long long> w(n+1);
  vector<long long> sinit(n+1,0);
  segtree<long long, op, e> segcnt(sinit),segres(sinit);

  for(int i=1;i<=n;i++){
    cin >> a[i];
    a[i]-=i;
  }
  for(int i=1;i<=n;i++){
    cin >> w[i];
    segcnt.set(i,w[i]);
    segres.set(i,(w[i]*a[i])%mod);
  }
  while(q>0){
    q--;
    long long x,y;
    cin >> x >> y;
    if(x<0){
      x*=-1;
      target-=w[x];
      w[x]=y;
      target+=w[x];
      segcnt.set(x,w[x]);
      segres.set(x,(w[x]*a[x])%mod);
    }
    else{
      long long lc=segcnt.prod(0,x);
      long long rc=segcnt.prod(0,y+1);
      target=(lc+rc)/2;
      long long grv=segcnt.max_right<f>(0);
      long long lnum=segcnt.prod(x,grv);
      long long rnum=segcnt.prod(grv,y+1);
      long long res=0;
      //cout << a[grv] << ':';
      res+=((lnum%mod)*a[grv]);res%=mod;
      //cout << res << ' ';
      res+=(mod-(segres.prod(x,grv)%mod));res%=mod;
      //cout << res << ' ';
      res+=((rnum%mod)*(mod-a[grv]));res%=mod;
      //cout << res << ' ';
      res+=segres.prod(grv,y+1);res%=mod;
      cout << res << '\n';
    }
  }
  return 0;
}