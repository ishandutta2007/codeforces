#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, (n)-1)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)
#define reset(a, b) memset(a, b, sizeof(a))
typedef long long ll;
using namespace std;

const int maxn = 123;

int n, k, lis[maxn], ans;
bool vis[maxn];

int main() {
  cin >> n >> k;
  FOR(i, 1, n)
    cin >> lis[i];
  REP(b, k) {
    reset(vis, 0);
    REP(i, n + 1) {
      if (b + i * k > n) break;
      vis[b + i * k] = true;
    }
    int now = 0;
    FOR(i, 1, n) if (!vis[i]) now += lis[i];
    ans = max(ans, abs(now));
  }
  cout << ans;
}