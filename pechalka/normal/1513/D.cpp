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

int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

int tree[(1 << 20) + 228];

void build(int v, int left, int right, vector<int> &A) {
  if (left + 1 == right) {
    tree[v] = A[left];
    return;
  }
  int mid = (left + right) / 2;
  build(2 * v + 1, left, mid, A);
  build(2 * v + 2, mid, right, A);
  tree[v] = gcd(tree[2 * v + 1], tree[2 * v + 2]);
}

int right_not_div(int v, int left, int right, int x, int d) {
  if (right <= x || tree[v] % d == 0)
    return right;
  if (left + 1 == right)
    return left;
  int mid = (left + right) / 2;
  int ans = right_not_div(2 * v + 1, left, mid, x, d);
  if (ans == mid)
    return right_not_div(2 * v + 2, mid, right, x, d);
  return ans;
}

int left_not_div(int v, int left, int right, int x, int d) {
  if (x < left || tree[v] % d == 0)
    return left - 1;
  if (left + 1 == right)
    return left;
  int mid = (left + right) / 2;
  int ans = left_not_div(2 * v + 2, mid, right, x, d);
  if (ans == mid - 1)
    return left_not_div(2 * v + 1, left, mid, x, d);
  return ans;
}

int par[200'200];
int mx[200'200];
int mn[200'200];

int get(int v) {
  if (par[v] == v)
    return v;
  return par[v] = get(par[v]);
}

bool merge(int v, int u) {
  v = get(v);
  u = get(u);
  if (v == u)
    return false;
  par[v] = u;
  mn[u] = min(mn[u], mn[v]);
  mx[u] = max(mx[u], mx[v]);
  return true;
}

void solve() {
  int n, p;
  cin >> n >> p;
  vector<int> A(n);
  for (int i = 0; i < n; ++i)
    cin >> A[i];
  build(0, 0, n, A);
  vector<int> left_less(n);
  vector<int> stack;
  for (int i = 0; i < n; ++i) {
    while (!stack.empty() && A[stack.back()] >= A[i])
      stack.pop_back();
    left_less[i] = (stack.empty() ? -1 : stack.back());
  }
  vector<int> right_less(n);
  stack.clear();
  for (int i = n - 1; i >= 0; --i) {
    while (!stack.empty() && A[stack.back()] >= A[i])
      stack.pop_back();
    right_less[i] = (stack.empty() ? n : stack.back());
  }
  for (int i = 0; i < n; ++i) {
    left_less[i] = max(left_less[i], left_not_div(0, 0, n, i, A[i]));
    right_less[i] = min(right_less[i], right_not_div(0, 0, n, i, A[i]));
  }
  vector<int> order(n);
  for (int i = 0; i < n; ++i)
    order[i] = i;
  sort(order.begin(), order.end(), [&A](int a, int b) {
    return A[a] < A[b];
  });
  for (int i = 0; i < n; ++i)
    par[i] = mx[i] = mn[i] = i;
  long long ans = 0;
  for (int i : order) {
    if (A[i] >= p)
      break;
    while (true) {
      int j = mn[get(i)] - 1;
      if (j > left_less[i]) {
        merge(j, i);
        ans += A[i];
      } else
        break;
    }
    while (true) {
      int j = mx[get(i)] + 1;
      if (j < right_less[i]) {
        merge(j, i);
        ans += A[i];
      } else
        break;
    }
  }
  for (int i = 0; i + 1 < n; ++i) {
    if (merge(i, i + 1))
      ans += p;
  }
  cout << ans << '\n';
}

int main () {
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
    solve();
  }
  return 0;
}