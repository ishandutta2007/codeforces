#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <deque>
#include <bitset>
#include <vector>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int INF = 1e9 + 7;

struct Node{
  int max1, max2;
  int max_cnt;
  long long sum;
  Node(int len) {
    max1 = INF;
    max2 = -1;
    max_cnt = len;
    sum = INF * 1ll * len;
  }
  Node(){
  }
};

Node combine(const Node &a, const Node &b) {
  Node ans;
  ans.sum = a.sum + b.sum;
  ans.max1 = max(a.max1, b.max1);
  ans.max_cnt = (ans.max1 == a.max1 ? a.max_cnt : 0) +
                (ans.max1 == b.max1 ? b.max_cnt : 0);
  ans.max2 = max(ans.max1 == a.max1 ? a.max2 : a.max1,
                 ans.max1 == b.max1 ? b.max2 : b.max1);
  return ans;
}

struct JiDriverSegmentTree{
  Node tree[(1 << 19) + 228];
  int mod[(1 << 19) + 228];
  void build(int v, int left, int right) {
    tree[v] = Node(right - left);
    mod[v] = INF;
    if (left + 1 == right)
      return;
    int mid = (left + right) / 2;
    build(2 * v + 1, left, mid);
    build(2 * v + 2, mid, right);
  }
  void push(int v, int left, int right) {
    if (mod[v] == INF)
      return;
    tree[v].sum += (mod[v] - tree[v].max1) * 1ll * tree[v].max_cnt;
    if (left + 1 != right) {
      if (tree[2 * v + 1].max1 > mod[v])
        mod[2 * v + 1] = min(mod[2 * v + 1], mod[v]);
      if (tree[2 * v + 2].max1 > mod[v])
        mod[2 * v + 2] = min(mod[2 * v + 2], mod[v]);
    }
    tree[v].max1 = mod[v];
    mod[v] = INF;
  }
  void minimize(int v, int left, int right, int x, int y, int val) {
    push(v, left, right);
    if (y <= left || right <= x || tree[v].max1 <= val)
      return;
    if (x <= left && right <= y && tree[v].max2 < val) {
      mod[v] = val;
      push(v, left, right);
      return;
    }
    int mid = (left + right) / 2;
    minimize(2 * v + 1, left, mid, x, y, val);
    minimize(2 * v + 2, mid, right, x, y, val);
    tree[v] = combine(tree[2 * v + 1], tree[2 * v + 2]);
  }
  Node get(int v, int left, int right, int x, int y) {
    push(v, left, right);
    if (x <= left && right <= y)
      return tree[v];
    int mid = (left + right) / 2;
    if (y <= mid)
      return get(2 * v + 1, left, mid, x, y);
    if (mid <= x)
      return get(2 * v + 2, mid, right, x, y);
    return combine(get(2 * v + 1, left, mid, x, y), get(2 * v + 2, mid, right, x, y));
  }
};

const int N = 100'100;
JiDriverSegmentTree pos1;
JiDriverSegmentTree pos2;
JiDriverSegmentTree neg1;
JiDriverSegmentTree neg2;

int main() {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int q;
  cin >> q;
  pos1.build(0, 0, N);
  pos2.build(0, 0, N);
  neg1.build(0, 0, N);
  neg2.build(0, 0, N);
  while (q--) {
    int t, l, r;
    cin >> t >> l >> r;
    --l;
    --r;
    if (t == 1) {
      int k;
      cin >> k;
      if (k > 0) {
        pos1.minimize(0, 0, N, l, r, k);
        pos2.minimize(0, 0, N, l, r, k);
        neg2.minimize(0, 0, N, l, r, 0);
      } else {
        k *= -1;
        neg1.minimize(0, 0, N, l, r, k);
        neg2.minimize(0, 0, N, l, r, k);
        pos2.minimize(0, 0, N, l, r, 0);
      }
    } else {
      long long ans = 0;
      auto tmp = pos1.get(0, 0, N, l, r);
      ans += tmp.sum;
      if (tmp.max1 == INF)
        ans -= INF * 1ll * tmp.max_cnt;
      tmp = neg1.get(0, 0, N, l, r);
      ans += tmp.sum;
      if (tmp.max1 == INF)
        ans -= INF * 1ll * tmp.max_cnt;
      tmp = pos2.get(0, 0, N, l, r);
      ans -= tmp.sum;
      if (tmp.max1 == INF)
        ans += INF * 1ll * tmp.max_cnt;
      tmp = neg2.get(0, 0, N, l, r);
      ans -= tmp.sum;
      if (tmp.max1 == INF)
        ans += INF * 1ll * tmp.max_cnt;
      cout << ans << '\n';
    }
  }
  return 0;
}