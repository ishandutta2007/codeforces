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

pair<long long, long long> seg_tree[(1 << 20) + 228];

pair<long long, long long> operator +(const pair<long long, long long> &a, const pair<long long, long long> &b) {
  return make_pair(a.first + b.first, a.second + b.second);
}

void add(int v, int left, int right, int x, int y, pair<long long, long long> d) {
  if (y <= left || right <= x)
    return;
  if (x <= left && right <= y) {
    seg_tree[v] = seg_tree[v] + d;
    return;
  }
  int mid = (left + right) / 2;
  add(2 * v + 1, left, mid, x, y, d);
  add(2 * v + 2, mid, right, x, y, d);
}

long long get(int v, int left, int right, int i) {
  long long f = seg_tree[v].first * i + seg_tree[v].second;
  if (left + 1 == right)
    return f;
  int mid = (left + right) / 2;
  if (i < mid)
    return f + get(2 * v + 1, left, mid, i);
  return f + get(2 * v + 2, mid, right, i);
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

  int n, k;
  cin >> n >> k;
  vector<long long> B(n);
  for (int i = 0; i < n; ++i)
    cin >> B[i];
  long long ans = 0;
  for (int i = n - k; i > 0; --i) {
    long long sub = get(0, 0, n, i + k - 1);
    if (sub < B[i + k - 1]) {
      long long cnt = (B[i + k - 1] - sub + k - 1) / k;
      ans += cnt;
      add(0, 0, n, i, i + k, make_pair(cnt, cnt - i * cnt));
    }
  }
  long long mx = 0;
  for (int i = 0; i < k; ++i) {
    long long sub = get(0, 0, n, i);
    if (sub < B[i])
      mx = max(mx, (B[i] - sub + i) / (i + 1));
  }
  cout << ans + mx << '\n';
  return 0;
}