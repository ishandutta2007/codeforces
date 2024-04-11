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

vector<int> find_3412(int n,vector<int> &p){
  vector<int> inv(n);
  for(int i=0;i<n;i++){inv[p[i]]=i;}

  vector<pi> event;
  vector<int> pt4(n); // if A_i is used as 3, A_{pt4[i]} is optimal to use as 4
  segtree<int,op_min,e_min> seg_for4(n);
  for(int i=n-1;i>=0;i--){
    pt4[inv[i]]=seg_for4.prod(inv[i],n);
    if(pt4[inv[i]]!=e_min()){
      event.push_back({2*pt4[inv[i]]+1,i});
    }
    seg_for4.set(inv[i],inv[i]);
  }

  vector<int> pt1(n); // if A_i is used as 2, A_{pt1[i]} is optimal to use as 1
  segtree<int,op_max,e_max> seg_for1(n);
  for(int i=0;i<n;i++){
    pt1[inv[i]]=seg_for1.prod(0,inv[i]);
    if(pt1[inv[i]]!=e_max()){
      event.push_back({2*pt1[inv[i]],i});
    }
    seg_for1.set(inv[i],inv[i]);
  }

  sort(event.begin(),event.end());
  segtree<int,op_max,e_max> seg_final(n);

  vector<int> res(n,0);
  for(auto &nx : event){
    // cout << nx.first << ',' << nx.second << '\n';
    if(nx.first%2){
      // found 4 -> register 3
      seg_final.set(nx.second,inv[nx.second]);
      // cout << "+ " << nx.second << ' ' << inv[nx.second] << '\n';
    }
    else{
      // found 1 -> update about 2
      res[inv[nx.second]]=seg_final.prod(nx.second+1,n)+1;
      // cout << "? " << inv[nx.second] << ' ' << seg_final.prod(nx.second+1,n)+1 << '\n';
    }
  }

  for(int i=1;i<n;i++){res[i]=max(res[i-1],res[i]);}
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> p(n);
  for(auto &nx : p){
    cin >> nx;
    nx--;
  }
  vector<int> lef(n,0);

  vector<int> cur=find_3412(n,p);
  // for(auto &nx : cur){cout << nx << ' ';} cout << '\n';
  for(int i=0;i<n;i++){lef[i]=max(lef[i],cur[i]);}

  for(auto &nx : p){nx=n-1-nx;}

  cur=find_3412(n,p);
  // for(auto &nx : cur){cout << nx << '\n';}
  for(int i=0;i<n;i++){lef[i]=max(lef[i],cur[i]);}

  long long res=0;
  for(int i=0;i<n;i++){res+=(i-lef[i]+1);}

  cout << res << '\n';
  return 0;
}