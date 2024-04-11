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

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  int tot = count(all(s), '1');
  if (tot == 0 || tot % 2 == 1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  int st = find(all(s), '1') - s.begin();
  st = (st + 1) % n;
  for (int i = (st + 1) % n; i != st; ) {
    int j = i, pre = st;
    while (j != st) {
      cout << pre + 1 << ' ' << j + 1 << '\n';
      pre = j;
      j = (j + 1) % n;
      if (s[pre] == '1') break;
    }
    i = j;
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}