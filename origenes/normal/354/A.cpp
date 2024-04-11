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

int w[maxn], ql, qr, n, l, r;
int pre[maxn], suf[maxn];

int main() {
  scanf("%d%d%d%d%d", &n, &l, &r, &ql, &qr);
  FOR(i, 1, n) scanf("%d", w + i);
  FOR(i, 1, n) pre[i] = pre[i - 1] + w[i] * l;
  ROF(i, n, 1) suf[i] = suf[i + 1] + w[i] * r;
  int ans = pre[n] + ql * (n - 1);
  ROF(i, n - 1, 0) {
    int now = pre[i] + suf[i + 1], j = n - i;
    if (n > 2 * j + 1) now += ql * (n - 2 * j - 1);
    else if (2 * j - 1 > n) now += qr * (2 * j - 1 - n);
    chkmin(ans, now);
  }
  printf("%d", ans);
}