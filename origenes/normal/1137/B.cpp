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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 512345;

char s[maxn], t[maxn];
int fail[maxn], cnt[2][2];

int main() {
  scanf("%s%s", s, t);
  int n = strlen(s), m = strlen(t), j = 0;
  FOR(i, 1, m - 1) {
    while (j && t[j] != t[i]) j = fail[j];
    if (t[i] == t[j]) j++;
    fail[i + 1] = j;
  }
  REP(i, n) cnt[0][s[i] - '0']++;
  REP(i, m) cnt[1][t[i] - '0']++;
  if (cnt[0][0] < cnt[1][0] || cnt[0][1] < cnt[1][1]) {
    puts(s);
    return 0;
  }
  cnt[0][0] -= cnt[1][0], cnt[0][1] -= cnt[1][1];
  memcpy(s, t, sizeof(t));
  REP(i, fail[m]) cnt[1][t[i] - '0']--;
  j = m;
  while (cnt[0][0] >= cnt[1][0] && cnt[0][1] >= cnt[1][1]) {
    FOR(i, fail[m], m - 1) s[j++] = t[i];
    cnt[0][0] -= cnt[1][0], cnt[0][1] -= cnt[1][1];
  }
  while (cnt[0][0]--) s[j++] = '0';
  while (cnt[0][1]--) s[j++] = '1';
  puts(s);
}