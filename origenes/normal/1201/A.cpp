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

const int maxn = 1123;

char s[maxn][maxn];
int a, n, m, ans, cnt[5];

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%s", s[i] + 1);
  FOR(i, 1, m) {
    scanf("%d", &a);
    reset(cnt, 0);
    FOR(j, 1, n) cnt[s[j][i] - 'A']++;
    ans += a * (*max_element(cnt, cnt + 5));
  }
  printf("%d", ans);
}