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

char s[maxn], t[maxn], p[maxn];
int cnt[26];
int ls, lt, lp, q;

int main() {
  scanf("%d", &q);
  while (q--) {
    scanf("%s%s%s", s + 1, t + 1, p + 1);
    reset(cnt, 0);
    ls = strlen(s + 1), lt = strlen(t + 1), lp = strlen(p + 1);
    FOR(i, 1, lp) cnt[p[i] - 'a']++;
    int j = 1;
    bool ans = true;
    FOR(i, 1, ls) {
      while (j <= lt && t[j] != s[i]) j++;
      if (j > lt) {
        ans = false;
        break;
      }
      j++;
    }
    FOR(i, 1, ls) cnt[s[i] - 'a']++;
    FOR(i, 1, lt) cnt[t[i] - 'a']--;
    REP(i, 26) if (cnt[i] < 0) ans = false;
    puts(ans ? "Yes" : "No");
  }
}