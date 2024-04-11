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

const int maxn = 1123456;

int n;
ll h[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%lld", h + i);
  ll extra = 0;
  FOR(i, 1, n) extra += h[i] - h[1] - i + 1;
  ll each = extra / n, rem = extra % n;
  ROF(i, n, 1) h[i] = h[1] + i - 1 + each + (i <= rem);
  FOR(i, 1, n) printf("%lld ", h[i]);
}