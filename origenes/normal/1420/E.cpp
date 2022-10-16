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

const int maxn = 85;

int f[maxn][maxn][maxn * maxn / 2], cnt[2], p[maxn], ans[maxn * maxn / 2];
int n;

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    int a; scanf("%d", &a);
    cnt[a]++;
    if (a == 1) p[cnt[1]] = i;
  }
  reset(f, 0xc0);
  f[0][0][0] = 0;
  FOR(i, 1, n) FOR(j, 1, cnt[1]) FOR(c, abs(p[j] - i), n * (n - 1) / 2) REP(ni, i)
    chkmax(f[i][j][c], f[ni][j - 1][c - abs(p[j] - i)] + (i - ni - 1) * (cnt[0] - i + j));
  REP(c, n * (n - 1) / 2 + 1) FOR(i, 1, n) chkmax(ans[c], f[i][cnt[1]][c]);
  FOR(c, 1, n * (n - 1) / 2) chkmax(ans[c], ans[c - 1]);
  REP(c, n * (n - 1) / 2 + 1) printf("%d ", ans[c]);
}