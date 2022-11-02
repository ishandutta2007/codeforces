#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <bitset>
#include <random>
#include <string>
#include <vector>
#include <complex>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

int tree[(1 << 19) + 228];
long long tree_sum[(1 << 19) + 228];

void build(int v, int left, int right) {
  tree[v] = 0;
  tree_sum[v] = 0;
  if (left + 1 == right)
    return;
  int mid = (left + right) / 2;
  build(2 * v + 1, left, mid);
  build(2 * v + 2, mid, right);
}

void reset(int v, int left, int right, int i, int x) {
  if (left + 1 == right) {
    tree[v] = 1;
    tree_sum[v] = x;
    return;
  }
  int mid = (left + right) / 2;
  if (i < mid)
    reset(2 * v + 1, left, mid, i, x);
  else
    reset(2 * v + 2, mid, right, i, x);
  tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
  tree_sum[v] = tree_sum[2 * v + 1] + tree_sum[2 * v + 2];
}

long long get_sum(int v, int left, int right, int k) {
  if (tree[v] <= k)
    return tree_sum[v];
  if (k == 0)
    return 0;
  int mid = (left + right) / 2;
  long long ans = get_sum(2 * v + 1, left, mid, k);
  if (k >= tree[2 * v + 1])
    ans += get_sum(2 * v + 2, mid, right, k - tree[2 * v + 1]);
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

  int c;
  cin >> c;
  while (c--) {
    int n, m;
    long long t;
    cin >> n >> m >> t;
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
      cin >> A[i];
    vector<int> order(n);
    for (int i = 0; i < n; ++i)
      order[i] = i;
    sort(order.begin(), order.end(), [&A](int a, int b) {
      return A[a] < A[b];
    });
    int ans = 0;
    long long ans_d = 1;
    build(0, 0, n);
    for (int i = 0; i < n; ++i) {
      reset(0, 0, n, order[i], A[order[i]]);
      if (i + 1 < n && A[order[i + 1]] == A[order[i]])
        continue;
      int left = 0, right = i + 2;
      while (right - left > 1) {
        int mid = (left + right) / 2;
        if (get_sum(0, 0, n, (mid - 1) / m * m) + get_sum(0, 0, n, mid) <= t)
          left = mid;
        else
          right = mid;
      }
      if (ans < left) {
        ans = left;
        ans_d = A[order[i]];
      }
    }
    cout << ans << ' ' << ans_d << '\n';
  }
  return 0;
}