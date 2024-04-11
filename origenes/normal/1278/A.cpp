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

char h[maxn], p[maxn];

void solve() {
  scanf("%s%s", p + 1, h + 1);
  int n = strlen(p + 1), m = strlen(h + 1);
  if (m < n) {
    puts("NO");
    return;
  }
  map<char, int> cnt;
  FOR(i, 1, n) cnt[p[i]]++;
  FOR(i, 1, n) if (!--cnt[h[i]]) cnt.erase(h[i]);
  if (cnt.empty()) {
    puts("YES");
    return;
  }
  FOR(en, n + 1, m) {
    int st = en - n;
    if (!++cnt[h[st]]) cnt.erase(h[st]);
    if (!--cnt[h[en]]) cnt.erase(h[en]);
    if (cnt.empty()) {
      puts("YES");
      return;
    }
  }
  puts("NO");
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}