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

struct Node{
  int val;
  int left, right;
  Node(int _val = 0) {
    val = _val;
    left = right = -1;
  }
};

Node nodes[10'000'000];
int nodes_cnt = 0;

int node(int val) {
  nodes[nodes_cnt] = Node(val);
  ++nodes_cnt;
  return nodes_cnt - 1;
}

int build(int left, int right) {
  int ans = node(0);
  if (left + 1 == right)
    return ans;
  int mid = (left + right) / 2;
  nodes[ans].left = build(left, mid);
  nodes[ans].right = build(mid, right);
  return ans;
}

int get(int v, int left, int right, int x, int y) {
  if (y <= left || right <= x)
    return 0;
  if (x <= left && right <= y)
    return nodes[v].val;
  int mid = (left + right) / 2;
  return get(nodes[v].left, left, mid, x, y) + get(nodes[v].right, mid, right, x, y);
}

int add(int v, int left, int right, int i, int d) {
  int ans = node(nodes[v].val + d);
  if (left + 1 == right)
    return ans;
  int mid = (left + right) / 2;
  if (i < mid) {
    nodes[ans].left = add(nodes[v].left, left, mid, i, d);
    nodes[ans].right = nodes[v].right;
  } else {
    nodes[ans].left = nodes[v].left;
    nodes[ans].right = add(nodes[v].right, mid, right, i, d);
  }
  return ans;
}

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
    nodes_cnt = 0;

    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
      cin >> A[i];
    vector<int> order(n);
    for (int i = 0; i < n; ++i)
      order[i] = i;
    sort(order.begin(), order.end(), [&A](int a, int b) {
      return A[a] < A[b];
    });
    vector<int> id(n);
    for (int i = 0; i < n; ++i)
      id[order[i]] = i;
    vector<int> trees(n + 1);
    trees[0] = build(0, n);
    for (int i = 0; i < n; ++i)
      trees[i + 1] = add(trees[i], 0, n, id[i], 1);
    int q;
    cin >> q;
    vector<pair<int, int>> segms;
    vector<pair<int, int>> segms_even;
    vector<pair<int, int>> segms_odd;
    while (q--) {
      int l, r;
      cin >> l >> r;
      --l;
      int ans = 0;
      segms.emplace_back(0, n);
      for (int k = 29; k >= 0; --k) {
        int cnt = 0;
        for (auto t : segms) {
          int left = t.first - 1, right = t.second;
          while (right - left > 1) {
            int mid = (left + right) / 2;
            if (A[order[mid]] & (1 << k))
              right = mid;
            else
              left = mid;
          }
          if (t.first < right) {
            int val = get(trees[r], 0, n, t.first, right) - get(trees[l], 0, n, t.first, right);
            cnt += val;
            if (val)
              segms_even.emplace_back(t.first, right);
          }
          if (right < t.second)
            segms_odd.emplace_back(right, t.second);
        }
        if (cnt >= 2) {
          swap(segms, segms_even);
          segms_odd.clear();
          segms_even.clear();
        } else {
          ans += 1 << k;
          swap(segms, segms_odd);
          segms_odd.clear();
          for (auto t : segms_even)
            segms.emplace_back(t);
          segms_even.clear();
        }
      }
      segms.clear();
      cout << ans << '\n';
    }
  }
  return 0;
}