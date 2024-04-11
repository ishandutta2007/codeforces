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

const int MOD = 1e9 + 7;

int add(int a, int b) {
  if (a + b < MOD)
    return a + b;
  return a + b - MOD;
}

int sub(int a, int b) {
  if (a >= b)
    return a - b;
  return a + MOD - b;
}

int mul(int a, int b) {
  return a * 1ll * b % MOD;
}

const int MAXN = 200'200;

int nxt[MAXN];
vector<int> order;
int id[MAXN];

int fenw[MAXN];

void fenw_add(int i, int x) {
  for (; i < MAXN; i = (i | (i + 1)))
    fenw[i] = add(fenw[i], x);
}

int fenw_get(int i) {
  int ans = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1)
    ans = add(ans, fenw[i]);
  return ans;
}

int solve_smart(int n, int m, int k, vector<int> A) {
  vector<int> pref(n + 1);
  for (int i = 0; i < n; ++i)
    pref[i + 1] = (pref[i] + A[i]) % k;
  int sum_all = pref[n];
  if (sum_all == 0) {
    vector<int> cnt(k);
    int ans = 0;
    for(int i = 1; i <= n; ++i)
      cnt[pref[i]] = add(cnt[pref[i]], m);
    for(int i = 0; i < k; ++i)
      ans = add(ans, mul(cnt[i], sub(cnt[i], 1)));
    ans = add(ans, 1);
    return ans;
  }
  for (int i = 0; i < k; ++i)
    nxt[i] = (i + sum_all) % k;
  int cur = 0;
  for (int i = 0; i < k; ++i) {
    order.emplace_back(cur);
    cur = nxt[cur];
  }
  for (int i = 0; i < k; ++i)
    id[order[i]] = i;
  int ans = 0;
  //l % n <= r % n
  fill(fenw, fenw + k, 0);
  for (int i = n - 1; i >= 0; --i) {
    fenw_add(id[pref[i + 1]], 1);
    int current = 0;
    int tmp = m;
    current = mul(fenw_get(k - 1), tmp / k);
    tmp %= k;
    int r = id[pref[i]];
    int l = r - tmp + 1;
    if (l < 0) {
      current = add(current, sub(fenw_get(k - 1), fenw_get(k + l - 1)));
      current = add(current, fenw_get(r));
    } else {
      current = add(current, sub(fenw_get(r), fenw_get(l - 1)));
    }
    ans = add(ans, mul(current, m));
  }
  //l % n > r % n
  fill(fenw, fenw + k, 0);
  for (int i = 1; i < n; ++i) {
    fenw_add(id[pref[i]], 1);
    int tmp = m;
    int current = mul(fenw_get(k - 1), tmp / k);
    tmp %= k;
    int r = id[(pref[i] + k - sum_all) % k];
    int l = r - tmp + 1;
    if (l < 0) {
      current = add(current, sub(fenw_get(k - 1), fenw_get(k + l - 1)));
      current = add(current, fenw_get(r));
    } else {
      current = add(current, sub(fenw_get(r), fenw_get(l - 1)));
    }
    ans = add(ans, mul(current, m));
  }
  if (sum_all * 1ll * m % k == 0)
    ans = sub(ans, sub(mul(n, m), 1));
  order.clear();
  return ans;
}

int solve_dumb(int n, int m, int k, vector<int> A) {
  int N = n * m;
  vector<int> B(N);
  for (int i = 0; i < N; ++i)
    B[i] = A[i % n];
  int ans = 0;
  for (int l = 0; l < N; ++l) {
    int sum = 0;
    for (int r = l; r < N; ++r) {
      sum = (sum + B[r]) % k;
      ans += sum == 0;
    }
  }
  for (int r = 0; r < N; ++r) {
    for (int l = r + 2; l < N; ++l) {
      int sum = 0;
      for (int i = l; i < N; ++i)
        sum = (sum + B[i]) % k;
      for (int i = 0; i <= r; ++i)
        sum = (sum + B[i]) % k;
      ans += sum == 0;
    }
  }
  return ans;
}

//#define STRESS

int main() {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

#ifdef STRESS
  srand(228);
  vector<int> primes = {2, 3, 5};//, 7, 11, 13};
  for (int _ = 0; _ < 100'000; ++_) {
    int n = rand() % 10 + 1;
    int m = rand() % 7 + 1;
    int k = primes[rand() % primes.size()];
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
      A[i] = rand() % k;
    int ans1 = solve_smart(n, m, k, A);
    int ans2 = solve_dumb(n, m, k, A);
    if (ans1 != ans2) {
      cerr << "BUG!!!\n";
      cerr << n << ' ' << m << ' ' << k << '\n';
      for (int x : A)
        cerr << x << ' ';
      cerr << "wrong: " << ans1 << " right: " << ans2 << "\n\n\n";
    }
  }
#else
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> A(n);
  for (int i = 0; i < n; ++i)
    cin >> A[i];
  cout << solve_smart(n, m, k, A) << '\n';
#endif
  return 0;
}