#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <string>
#include <vector>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const int INF = 1e9;

struct SegTree{
  int val[(1 << 19) + 228];
  bool is_max;
  SegTree() {
  }
  void recreate(vector<int> &A, bool _is_max) {
    is_max = _is_max;
    build(0, 0, A.size(), A);
  }
  void build(int v, int left, int right, vector<int> &A) {
    if (left + 1 == right) {
      val[v] = A[left];
      return;
    }
    int mid = (left + right) / 2;
    build(2 * v + 1, left, mid, A);
    build(2 * v + 2, mid, right, A);
    if (is_max)
      val[v] = max(val[2 * v + 1], val[2 * v + 2]);
    else
      val[v] = min(val[2 * v + 1], val[2 * v + 2]);
  }
  void upd(int v, int left, int right, int i, int x) {
    if (left + 1 == right) {
      val[v] = x;
      return;
    }
    int mid = (left + right) / 2;
    if (i < mid)
      upd(2 * v + 1, left, mid, i, x);
    else
      upd(2 * v + 2, mid, right, i, x);
    if (is_max)
      val[v] = max(val[2 * v + 1], val[2 * v + 2]);
    else
      val[v] = min(val[2 * v + 1], val[2 * v + 2]);
  }
  int get(int v, int left, int right, int x, int y) {
    if (y <= left || right <= x)
      return is_max ? -INF : INF;
    if (x <= left && right <= y)
      return val[v];
    int mid = (left + right) / 2;
    if (is_max)
      return max(get(2 * v + 1, left, mid, x, y), get(2 * v + 2, mid, right, x, y));
    return min(get(2 * v + 1, left, mid, x, y), get(2 * v + 2, mid, right, x, y));
  }
  int get_id(int v, int left, int right, int x, int y, int d) {
    if (y <= left || right <= x)
      return -1;
    if (x <= left && right <= y && val[v] != d)
      return -1;
    if (left + 1 == right)
      return left;
     int mid = (left + right) / 2;
     int ans = get_id(2 * v + 1, left, mid, x, y, d);
     if (ans == -1)
       return get_id(2 * v + 2, mid, right, x, y, d);
     return ans;
  }
};

SegTree tree1;
SegTree tree2;

int main() {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    --a;
    --b;
    vector<int> p(n);
    for (int i = 0; i < n; ++i)
      cin >> p[i];
    vector<int> vals(n);
    for (int i = 0; i < n; ++i)
      vals[i] = i + p[i];
    tree1.recreate(vals, true);
    for (int i = 0; i < n; ++i)
      vals[i] = i - p[i];
    tree2.recreate(vals, false);
    vector<int> d(n, n);
    deque<int> Q;
    Q.emplace_back(a);
    d[a] = 0;
    tree1.upd(0, 0, n, a, -INF);
    tree2.upd(0, 0, n, a, INF);
    while (!Q.empty()) {
      int v = Q.front();
      Q.pop_front();
      while (true) {
        int x = tree1.get(0, 0, n, v - p[v], v);
        if (x < v)
          break;
        int i = tree1.get_id(0, 0, n, v - p[v], v, x);
        d[i] = d[v] + 1;
        Q.emplace_back(i);
        tree1.upd(0, 0, n, i, -INF);
        tree2.upd(0, 0, n, i, INF);
      }
      while (true) {
        int x = tree2.get(0, 0, n, v, v + p[v] + 1);
        if (x > v)
          break;
        int i = tree2.get_id(0, 0, n, v, v + p[v] + 1, x);
        d[i] = d[v] + 1;
        Q.emplace_back(i);
        tree1.upd(0, 0, n, i, -INF);
        tree2.upd(0, 0, n, i, INF);
      }
    }
    cout << d[b] << '\n';
  }
  return 0;
}