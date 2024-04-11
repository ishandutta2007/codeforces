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

const long long INF = 1e18;

pair<long long, int> combine(const pair<long long, int> &a, const pair<long long, int> &b) {
  if (a.first == b.first)
    return make_pair(a.first, a.second + b.second);
  return min(a, b);
}

struct seg_tree{
  vector<long long> val;
  vector<long long> mod;
  vector<int> cnt;
  int N;
  seg_tree(int n, vector<long long> &A) {
    N = n;
    val.resize(4 * n);
    mod.resize(4 * n);
    cnt.resize(4 * n);
    build(0, 0, n, A);
  }
  void build(int v, int left, int right, vector<long long> &A) {
    if (left + 1 == right) {
      val[v] = A[left];
      cnt[v] = 1;
      return;
    }
    int mid = (left + right) / 2;
    build(2 * v + 1, left, mid, A);
    build(2 * v + 2, mid, right, A);
    val[v] = min(val[2 * v + 1], val[2 * v + 2]);
    cnt[v] = (val[2 * v + 1] == val[v] ? cnt[2 * v + 1] : 0) + (val[2 * v + 2] == val[v] ? cnt[2 * v + 2] : 0);
  }
  void add(int v, int left, int right, int x, int y, long long d) {
    if (y <= left || right <= x)
      return;
    if (x <= left && right <= y) {
      mod[v] += d;
      return;
    }
    int mid = (left + right) / 2;
    add(2 * v + 1, left, mid, x, y, d);
    add(2 * v + 2, mid, right, x, y, d);
    val[v] = min(val[2 * v + 1] + mod[2 * v + 1], val[2 * v + 2] + mod[2 * v + 2]);
    cnt[v] = (val[v] == val[2 * v + 1] + mod[2 * v + 1] ? cnt[2 * v + 1] : 0) +
        (val[v] == val[2 * v + 2] + mod[2 * v + 2] ? cnt[2 * v + 2] : 0);
  }
  pair<long long, int> get(int v, int left, int right, int x, int y) {
    if (y <= left || right <= x)
      return make_pair(INF, 0);
    if (x <= left && right <= y)
      return make_pair(val[v] + mod[v], cnt[v]);
    int mid = (left + right) / 2;
    auto ans = combine(get(2 * v + 1, left, mid, x, y), get(2 * v + 2, mid, right, x, y));
    return make_pair(ans.first + mod[v], ans.second);
  }
  int first_less(int v, int left, int right, int x, long long d) {
    if (right <= x || val[v] + mod[v] >= d)
      return right;
    if (left + 1 == right)
      return left;
    int mid = (left + right) / 2;
    int ans = first_less(2 * v + 1, left, mid, x, d - mod[v]);
    if (ans == mid)
      return first_less(2 * v + 2, mid, right, x, d - mod[v]);
    return ans;
  }
};

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
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
      cin >> A[i];
    if (n == 1) {
      cout << (A[0] == 0 ? 1 : 0) << '\n';
      continue;
    }
    vector<long long> vals1((n + 1) / 2);
    vals1[0] = A[0];
    for (int i = 1; i < (n + 1) / 2; ++i)
      vals1[i] = vals1[i - 1] + A[2 * i] - A[2 * i - 1];
    seg_tree even((n + 1) / 2, vals1);
    vector<long long> vals2(n / 2);
    vals2[0] = A[1] - A[0];
    for (int i = 1; i < n / 2; ++i)
      vals2[i] = vals2[i - 1] + A[2 * i + 1] - A[2 * i];
    seg_tree odd(n / 2, vals2);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      if (i % 2) {
        int bad = min(2 * even.first_less(0, 0, (n + 1) / 2, (i + 1) / 2, 0),
                      2 * odd.first_less(0, 0, n / 2, (i - 1) / 2, 0) + 1);
        auto tmp = even.get(0, 0, (n + 1) / 2, (i + 1) / 2, (bad + 1) / 2);
        ans += tmp.first == 0 ? tmp.second : 0;
        tmp = odd.get(0, 0, n / 2, (i - 1) / 2, bad / 2);
        ans += tmp.first == 0 ? tmp.second : 0;

        even.add(0, 0, (n + 1) / 2, (i + 1) / 2, (n + 1) / 2, A[i]);
        odd.add(0, 0, n / 2, (i - 1) / 2, n / 2, -A[i]);
      } else {
        int bad = min(2 * even.first_less(0, 0, (n + 1) / 2, i / 2, 0),
                      2 * odd.first_less(0, 0, n / 2, i / 2, 0) + 1);
        auto tmp = even.get(0, 0, (n + 1) / 2, i / 2, (bad + 1) / 2);
        ans += tmp.first == 0 ? tmp.second : 0;
        tmp = odd.get(0, 0, n / 2, i / 2, bad / 2);
        ans += tmp.first == 0 ? tmp.second : 0;
        even.add(0, 0, (n + 1) / 2, i / 2, (n + 1) / 2, -A[i]);
        odd.add(0, 0, n / 2, i / 2, n / 2, A[i]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}