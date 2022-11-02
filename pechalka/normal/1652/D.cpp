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

const int MOD = 998244353;

int pw(int a, int n) {
  int ans = 1;
  while (n) {
    if (n & 1)
      ans = ans * 1ll * a % MOD;
    n >>= 1;
    a = a * 1ll * a % MOD;
  }
  return ans;
}


const int MAXN = 200'200;
int min_prime[MAXN];
vector<int> primes;

vector<pair<int, pair<int, int>>> G[MAXN];
int cur_cnt[MAXN];
int mn_cnt[MAXN];
int val[MAXN];

void dfs(int v, int p, int tt) {
  val[v] = tt;
  for (auto t : G[v]) {
    if (t.first == p)
      continue;
    int tt2 = tt * 1ll * t.second.first % MOD * pw(t.second.second, MOD - 2) % MOD;
    int tmp = t.second.first;
    while (tmp != 1) {
      ++cur_cnt[min_prime[tmp]];
      tmp /= min_prime[tmp];
    }
    tmp = t.second.second;
    while (tmp != 1) {
      --cur_cnt[min_prime[tmp]];
      mn_cnt[min_prime[tmp]] = min(mn_cnt[min_prime[tmp]], cur_cnt[min_prime[tmp]]);
      tmp /= min_prime[tmp];
    }
    dfs(t.first, v, tt2);
    tmp = t.second.first;
    while (tmp != 1) {
      --cur_cnt[min_prime[tmp]];
      tmp /= min_prime[tmp];
    }
    tmp = t.second.second;
    while (tmp != 1) {
      ++cur_cnt[min_prime[tmp]];
      tmp /= min_prime[tmp];
    }
  }
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

  for (int i = 2; i < MAXN; ++i) {
    if (min_prime[i] == 0) {
      min_prime[i] = i;
      primes.emplace_back(i);
    }
    for (int j = 0; j < primes.size() && primes[j] <= min_prime[i] && primes[j] * i < MAXN; ++j)
      min_prime[primes[j] * i] = primes[j];
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
      int a, b, x, y;
      cin >> a >> b >> x >> y;
      G[a - 1].emplace_back(b - 1, make_pair(y, x));
      G[b - 1].emplace_back(a - 1, make_pair(x, y));
    }
    fill(cur_cnt, cur_cnt + n + 1, 0);
    fill(mn_cnt, mn_cnt + n + 1, 0);
    dfs(0, -1, 1);
    int ans = 0;
    for (int i = 0; i < n; ++i)
      ans = (ans + val[i]) % MOD;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < -mn_cnt[i]; ++j) {
        ans = ans * 1ll * i % MOD;
      }
    }
    cout << ans << '\n';
    for (int i = 0; i < n; ++i)
      G[i].clear();
  }
  return 0;
}