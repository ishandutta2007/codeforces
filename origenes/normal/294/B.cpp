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

const int maxn = 112;

int n, s;
int f[maxn * 2], t[maxn], w[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d%d", t + i, w + i);
  s = accumulate(t + 1, t + n + 1, 0);
  reset(f, 0x3f);
  f[0] = 0;
  FOR(i, 1, n) ROF(j, s, t[i]) chkmin(f[j], f[j - t[i]] + w[i]);
  ROF(i, s, 0) if (s - i >= f[i]) {
    printf("%d", s - i);
    return 0;
  }
}