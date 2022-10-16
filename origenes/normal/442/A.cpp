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

const char *ops = "RGBYW12345";

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n; cin >> n;
  vector<string> cards(n);
  REP(i, n) cin >> cards[i];
  sort(all(cards));
  uni(cards);
  n = cards.size();
  int ans = 10;
  map<char, int> m;
  m['R'] = 0, m['G'] = 1, m['B'] = 2, m['Y'] = 3, m['W'] = 4;
  m['1'] = 5, m['2'] = 6, m['3'] = 7, m['4'] = 8, m['5'] = 9;
  REP(mask, 1 << 10) {
    bool ok = true;
    REP(i, n) FOR(j, i + 1, n - 1) {
      bool good = false;
      if (cards[i][0] != cards[j][0] && ((mask & (1 << m[cards[i][0]])) || (mask & (1 << m[cards[j][0]])))) good = true;
      if (cards[i][1] != cards[j][1] && ((mask & (1 << m[cards[i][1]])) || (mask & (1 << m[cards[j][1]])))) good = true;
      if (!good) ok = false;
    }
    if (ok) chkmin(ans, __builtin_popcount(mask));
  }
  cout << ans;
}