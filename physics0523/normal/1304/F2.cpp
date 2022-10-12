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
#include <iostream>
#include <vector>
namespace atcoder {

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push(r >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
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

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
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
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

}  // namespace atcoder

using namespace std;
using namespace atcoder;

// https://betrue12.hateblo.jp/entry/2020/09/23/005940#%E5%8C%BA%E9%96%93%E5%8A%A0%E7%AE%97%E5%8C%BA%E9%96%93%E6%9C%80%E5%A4%A7%E5%80%A4%E5%8F%96%E5%BE%97
using S = long long;
using F = long long;

const S INF = 8e18;

S op(S a, S b){ return std::max(a, b); }
S e(){ return -INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

long long a[55][21000]={0};
long long bsum[55][21000]={0};

void prec(){
  for(long long i=0;i<55;i++){
    for(long long j=1;j<21000;j++){
      bsum[i][j]+=bsum[i][j-1];
    }
  }
  for(long long i=1;i<55;i++){
    for(long long j=0;j<21000;j++){
      bsum[i][j]+=bsum[i-1][j];
    }
  }
}

long long cbz(long long fx,long long fy,long long tx,long long ty){
  if(fx>tx || fy>ty){return 0;}
  if(fx==0 && fy == 0){return bsum[tx][ty];}
  else if(fx==0){
    return bsum[tx][ty]-bsum[tx][fy-1];
  }
  else if(fy==0){
    return bsum[tx][ty]-bsum[fx-1][ty];
  }
  else{
    return bsum[tx][ty]-bsum[tx][fy-1]-bsum[fx-1][ty]+bsum[fx-1][fy-1];
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,m,k;
  cin >> n >> m >> k;
  for(long long i=0;i<n;i++){
    for(long long j=0;j<m;j++){
      cin >> a[i][j];
      bsum[i][j]=a[i][j];
    }
  }
  prec();
  long long pat=m-k+1;
  vector<long long> dp(pat);
  for(long long i=0;i<pat;i++){
    dp[i]=cbz(0,i,1,i+k-1);
  }
  //for(auto &nx : dp){cout << nx << ' ';}cout << '\n';
  for(long long i=1;i<n;i++){
    vector<long long> ndp;
    vector<long long> init;
    init.push_back(dp[0]-cbz(i,0,i,k-1));
    for(long long j=1;j<=min(k,pat-1);j++){
      init.push_back(dp[j]-cbz(i,j,i,k-1));
    }
    for(long long j=k+1;j<=pat-1;j++){
      init.push_back(dp[j]);
    }
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(init);
    //for(long long pt=0;pt<pat;pt++){cout << seg.get(pt) << ',';}cout << '\n';
    ndp.push_back(seg.all_prod()+cbz(i,0,i+1,k-1));
    for(long long j=1;j<pat;j++){
      long long pl=a[i][j-1];
      seg.apply(max(0ll,j-k),j,pl);
      if(j+k-1<m){
        long long mn=a[i][j+k-1];
        seg.apply(j,min(j+k,pat),-mn);
      }
      //for(long long pt=0;pt<pat;pt++){cout << seg.get(pt) << ',';}cout << '\n';
      ndp.push_back(seg.all_prod()+cbz(i,j,i+1,j+k-1));
    }
    dp.swap(ndp);
    //for(auto &nx : dp){cout << nx << ' ';}cout << '\n';
  }

  long long res=0;
  for(auto &nx : dp){res=max(res,nx);}
  cout << res << '\n';
  return 0;
}