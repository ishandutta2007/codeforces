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

const int maxn = 512345;

int A, B, C, D;
ll way[maxn * 2];

int main() {
  scanf("%d%d%d%d", &A, &B, &C, &D);
  FOR(i, A + B, B + C) {
    int mx = min(i - B, B), mn = max(i - C, A);
    way[i] = mx - mn + 1;
  }
  ROF(i, B + C, 0) way[i] = way[i + 1] + way[i];
  ll ans = 0;
  FOR(i, C, D) ans += way[i + 1];
  printf("%lld", ans);
}