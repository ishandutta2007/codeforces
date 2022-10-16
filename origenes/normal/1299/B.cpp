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

int n;
ll x[maxn], y[maxn];
ll dx[maxn], dy[maxn];

int main() {
  scanf("%d", &n);
  if (n & 1) {
    puts("NO");
    return 0;
  }
  REP(i, n) scanf("%lld%lld", x + i, y + i);
  REP(i, n) {
    dx[i] = x[i] - x[(i + 1) % n];
    dy[i] = y[i] - y[(i + 1) % n];
  }
  bool good = true;
  REP(i, n / 2) if (dx[i] + dx[i + n / 2] != 0 || dy[i] + dy[i + n / 2] != 0) good = false;
  puts(good ? "YES" : "NO");
}