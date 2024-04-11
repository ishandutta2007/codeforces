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

const int maxn = 212345;

char s[maxn], t[maxn];
int pre[26][maxn], need[26];
int n, T, m;

int main() {
  scanf("%d%s", &n, s + 1);
  FOR(i, 1, n) {
    REP(j, 26) pre[j][i] = pre[j][i - 1];
    pre[s[i] - 'a'][i]++;
  }
  scanf("%d", &T);
  while (T--) {
    reset(need, 0);
    scanf("%s", t + 1);
    m = strlen(t + 1);
    FOR(i, 1, m) need[t[i] - 'a']++;
    int ans = 0;
    REP(i, 26) chkmax(ans, int(lower_bound(pre[i], pre[i] + n + 1, need[i]) - pre[i]));
    printf("%d\n", ans);
  }
}