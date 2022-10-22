#include <bits/stdc++.h>
#include <variant>

#define rep2(i,k,n) for(i64 i=(i64)(k);i<(i64)(n);i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) begin(x),end(x)

using namespace std;
using namespace std::string_literals;

using i32 = int32_t;
using i64 = int64_t;
using f64 = double;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;

struct UnionFind {
  vector<int> parent;
  UnionFind (int n) : parent(n, -1) {}
  int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
  bool merge(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (parent[y] < parent[x]) swap(x, y);
    if (parent[x] == parent[y]) --parent[x];
    parent[y] = x;
    return true;
  }
};

struct Trie {
  Trie() : zero(nullptr), one(nullptr), cnt(0) {}
  unique_ptr<Trie> zero;
  unique_ptr<Trie> one;
  i32 cnt;
};

void insert(Trie& trie, i32 v, i32 i = 29) {
  ++trie.cnt;
  if (i < 0) return;
  i32 bit = 1 << i;
  if (v & bit) {
    if (trie.one == nullptr) {
      trie.one = make_unique<Trie>();
    }
    insert(*trie.one, v, i-1);
  } else {
    if (trie.zero == nullptr) {
      trie.zero = make_unique<Trie>();
    }
    insert(*trie.zero, v, i-1);
  }
}

i32 max_rem(Trie& trie, i32 i = 29) {
  if (i < 0) return 1;
  i32 z, o;
  if (trie.zero != nullptr) {
    z = max_rem(*trie.zero, i-1);
  } else {
    z = 0;
  }
  if (trie.one != nullptr) {
    o = max_rem(*trie.one, i-1);
  } else {
    o = 0;
  }
  if (z && o) {
    return max(z, o) + 1;
  } else {
    return max(z, o);
  }
}

void show(Trie& trie, i32 v = 0, i32 i = 29) {
  cerr<<string(29-i,' ')<<trie.cnt<<endl;
  if (i < 0) {
    cerr<<string(30,' ')<<"* "<<v<<endl;
    return;
  }
  if (trie.zero != nullptr) {
    show(*trie.zero, v, i-1);
  }
  if (trie.one != nullptr) {
    show(*trie.one, v|(1<<i), i-1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i32 n;
  cin>>n;
  vi32 a(n);
  rep(i,n)cin>>a[i];
  Trie root;
  map<i32,i32> m;
  rep(i,n) {
    m[a[i]] = i;
    insert(root, a[i]);
  }
  i32 ans = n - max_rem(root);
  cout<<ans<<endl;
  return 0;
}