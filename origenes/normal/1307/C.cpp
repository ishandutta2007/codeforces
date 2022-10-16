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

char s[maxn];
int suf[maxn][26];
ll c1[26], c2[26][26];

int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  ROF(i, n, 1) {
    int ch = s[i] - 'a';
    c1[ch]++;
    REP(j, 26) suf[i][j] = suf[i + 1][j];
    suf[i][ch]++;
    REP(j, 26) c2[ch][j] += suf[i + 1][j];
  }
  ll ans = *max_element(c1, c1 + 26);
  REP(i, 26) chkmax(ans, *max_element(c2[i], c2[i] + 26));
  printf("%lld", ans);
}