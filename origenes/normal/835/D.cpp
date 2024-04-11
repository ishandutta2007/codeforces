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

const int maxn = 5123;

int n;
char s[maxn];
int f[maxn][maxn], ans[maxn];

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  FOR(i, 1, n) f[i][i] = f[i][i - 1] = 1;
  ans[1] = n;
  // i: len
  FOR(i, 1, n - 1) FOR(j, 1, n - i) if (s[j] == s[i + j] && f[j + 1][i + j - 1]) {
    f[j][i + j] = f[j][j + (i - 1) / 2] + 1;
    FOR(k, 1, f[j][i + j]) ans[k]++;
  }
  FOR(i, 1, n) printf("%d ", ans[i]);
}