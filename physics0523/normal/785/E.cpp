#include<bits/stdc++.h>

using namespace std;

// https://nyaannyaan.github.io/library/data-structure-2d/dynamic-binary-indexed-tree-2d.hpp
template <typename Key, typename Val>
struct HashMap {
  using u32 = uint32_t;
  using u64 = uint64_t;

  u32 cap, s;
  vector<Key> keys;
  vector<Val> vals;
  vector<bool> flag;
  u64 r;
  u32 shift;
  Val DefaultValue;

  static u64 rng() {
    u64 m = chrono::duration_cast<chrono::nanoseconds>(
                chrono::high_resolution_clock::now().time_since_epoch())
                .count();
    m ^= m >> 16;
    m ^= m << 32;
    return m;
  }

  void reallocate() {
    cap <<= 1;
    vector<Key> k(cap);
    vector<Val> v(cap);
    vector<bool> f(cap);
    u32 sh = shift - 1;
    for (int i = 0; i < (int)flag.size(); i++) {
      if (flag[i]) {
        u32 hash = (u64(keys[i]) * r) >> sh;
        while (f[hash]) hash = (hash + 1) & (cap - 1);
        k[hash] = keys[i];
        v[hash] = vals[i];
        f[hash] = 1;
      }
    }
    keys.swap(k);
    vals.swap(v);
    flag.swap(f);
    --shift;
  }

  explicit HashMap()
      : cap(8),
        s(0),
        keys(cap),
        vals(cap),
        flag(cap),
        r(rng()),
        shift(64 - __lg(cap)),
        DefaultValue(Val()) {}

  Val& operator[](const Key& i) {
    u32 hash = (u64(i) * r) >> shift;
    while (true) {
      if (!flag[hash]) {
        if (s + s / 4 >= cap) {
          reallocate();
          return (*this)[i];
        }
        keys[hash] = i;
        flag[hash] = 1;
        ++s;
        return vals[hash] = DefaultValue;
      }
      if (keys[hash] == i) return vals[hash];
      hash = (hash + 1) & (cap - 1);
    }
  }

  // exist -> return pointer of Val
  // not exist -> return nullptr
  const Val* find(const Key& i) const {
    u32 hash = (u64(i) * r) >> shift;
    while (true) {
      if (!flag[hash]) return nullptr;
      if (keys[hash] == i) return &(vals[hash]);
      hash = (hash + 1) & (cap - 1);
    }
  }

  // return vector< pair<const Key&, val& > >
  vector<pair<Key, Val>> enumerate() const {
    vector<pair<Key, Val>> ret;
    for (u32 i = 0; i < cap; ++i)
      if (flag[i]) ret.emplace_back(keys[i], vals[i]);
    return ret;
  }

  int size() const { return s; }

  // set default_value
  void set_default(const Val& val) { DefaultValue = val; }
};

template <typename S, typename T>
struct DynamicFenwickTree {
  S N;
  HashMap<S, T> data;
  explicit DynamicFenwickTree() = default;
  explicit DynamicFenwickTree(S size) { N = size + 1; }

  void add(S k, T x) {
    for (++k; k < N; k += k & -k) data[k] += x;
  }

  // [0, k)
  T sum(S k) const {
    if (k < 0) return 0;
    T ret = T();
    for (; k > 0; k -= k & -k) {
      const T* p = data.find(k);
      ret += p ? *p : T();
    }
    return ret;
  }

  // [a, b)
  T sum(S a, S b) const { return sum(b) - sum(a); }

  T operator[](S k) const { return sum(k + 1) - sum(k); }

  S lower_bound(T w) {
    if (w <= 0) return 0;
    S x = 0;
    for (S k = 1 << __lg(N); k; k >>= 1) {
      if (x + k <= N - 1 && data[x + k] < w) {
        w -= data[x + k];
        x += k;
      }
    }
    return x;
  }
};

template <typename T>
struct DynamicFenwickTree2D {
  using BIT = DynamicFenwickTree<int, T>;
  int N, M;
  vector<BIT*> bit;
  DynamicFenwickTree2D() = default;
  DynamicFenwickTree2D(int n, int m) : N(n + 1), M(m) {
    for (int _ = 0; _ < N; ++_) bit.push_back(new BIT(M));
  }

  void add(int i, int j, const T& x) {
    for (++i; i < N; i += i & -i) (*bit[i]).add(j, x);
  }

  // i = [0, n), j = [0, m)
  T sum(int n, int m) const {
    if (n < 0 || m < 0) return T();
    T ret = T();
    for (; n; n -= n & -n) ret += (*bit[n]).sum(m);
    return ret;
  }

  // i = [nl, nr), j = [ml, mr)
  T sum(int nl, int ml, int nr, int mr) const {
    T ret = T();
    while (nl != nr) {
      if (nl < nr) {
        ret += (*bit[nr]).sum(ml, mr);
        nr -= nr & -nr;
      } else {
        ret -= (*bit[nl]).sum(ml, mr);
        nl -= nl & -nl;
      }
    }
    return ret;
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,q;
  cin >> n >> q;
  DynamicFenwickTree2D<int> seg(n,n);
  long long res=0;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    a[i]=i;
    seg.add(i,i,1);
  }
  while(q>0){
    q--;
    int l,r;
    cin >> l >> r;
    l--;r--;
    if(l>r){swap(l,r);}
    if(l!=r){
      res-=(l-seg.sum(l,a[l]));
      res-=seg.sum(l+1,n,0,a[l]);
      res-=(r-seg.sum(r,a[r]));
      res-=seg.sum(r+1,n,0,a[r]);
      seg.add(l,a[l],-1);
      seg.add(r,a[r],-1);
      swap(a[l],a[r]);
      seg.add(l,a[l],1);
      seg.add(r,a[r],1);
      res+=(l-seg.sum(l,a[l]));
      res+=seg.sum(l+1,n,0,a[l]);
      res+=(r-seg.sum(r,a[r]));
      res+=seg.sum(r+1,n,0,a[r]);
      if(a[l]>a[r]){res--;}
      else{res++;}
    }
    cout << res << '\n';
  }
  return 0;
}