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

const char str[] = "RGB";

int q, n, k;

bool ok(int x, char ch) {
  return str[x] == ch;
}

int main() {
  cin >> q;
  while (q--) {
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = n + 1;
    REP(i, n - k + 1) {
      int p[3] = {};
      int tab[3] = {0, 1, 2};
      FOR(j, i, i + k - 1) {
        REP(ii, 3) {
          if (!ok(tab[ii], s[j])) p[ii]++;
          tab[ii] = (tab[ii] + 1) % 3;
        }
      }
      REP(ii, 3) chkmin(ans, p[ii]);
    }
    cout << ans << '\n';
  }
}