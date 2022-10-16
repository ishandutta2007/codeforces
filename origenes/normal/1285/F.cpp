#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 112345;

vector<int> fac[maxn];
bool vis[maxn];
int n;
int mu[maxn], cnt[maxn];

int good(int x) {
  int ret = 0;
  for (auto i : fac[x]) ret += cnt[i] * mu[i];
  return ret;
}

int main() {
  FOR(i, 1, 1e5) {
    for (int j = i; j <= 1e5; j += i) fac[j].eb(i);
    if (i == 1) mu[i] = 1;
    else if ((i / fac[i][1]) % fac[i][1]) mu[i] = -mu[i / fac[i][1]];
  }
  scanf("%d", &n);
  ll ans = 0;
  FOR(i, 1, n) {
    int a;
    scanf("%d", &a);
    chkmax(ans, ll(a));
    vis[a] = true;
  }
  FOR(i, 1, 1e5) for (int j = i + i; j <= 1e5; j += i) vis[i] |= vis[j];
  stack<int> s;
  ROF(i, 1e5, 1) if (vis[i]) {
    while (good(i)) {
      chkmax(ans, ll(i) * s.top());
      for (auto j : fac[s.top()]) cnt[j]--;
      s.pop();
    }
    for (auto j : fac[i]) cnt[j]++;
    s.emplace(i);
  }
  printf("%lld", ans);
}