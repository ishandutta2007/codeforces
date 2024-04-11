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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 1123;

int n, m;
vector<int> G[maxn];
int cnt[maxn];
ll ans;

int main() {
  scanf("%d%d", &n, &m);
  REP(i, m) {
    G[i * i % m].eb(i);
    cnt[i] = (n - i) / m + 1;
    if (!i) cnt[i]--;
    if (i > n) cnt[i] = 0;
  }
  REP(i, m) {
    ll fi = 0, se = 0;
    for (auto it : G[i]) fi += cnt[it];
    for (auto it : G[(m - i) % m]) se += cnt[it];
    ans += fi * se;
  }
  printf("%lld", ans);
}