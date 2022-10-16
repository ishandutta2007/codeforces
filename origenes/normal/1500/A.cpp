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
const int maxa = 2512345;

int n;
int a[maxn];
vector<int> G[maxa];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) {
    cin >> a[i];
    G[a[i]].eb(i);
  }
  vector<int> two;
  FOR(i, 1, 25e5) if (G[i].size() > 2) two.eb(i);
  if (two.size() >= 2) {
    cout << "YES\n";
    REP(i, 2) REP(j, 2) cout << G[two[j]][i] << ' ';
    return 0;
  }
  if (two.size() == 1 && G[two[0]].size() >= 4) {
    cout << "YES\n";
    REP(i, 4) cout << G[two[0]][i] << ' ';
    return 0;
  }
  vector<pii> pos(maxa * 2);
  chkmin(n, 5000);
  FOR(i, 1, n) FOR(j, i + 1, n) {
    if (pos[a[i] + a[j]] == mp(0, 0)) pos[a[i] + a[j]] = {i, j};
    else if (pos[a[i] + a[j]]._1 == i || pos[a[i] + a[j]]._2 == i || pos[a[i] + a[j]]._2 == j) continue;
    else {
      cout << "YES\n";
      cout << pos[a[i] + a[j]]._1 << ' ' << pos[a[i] + a[j]]._2;
      cout << ' ' << i << ' ' << j;
      return 0;
    }
  }
  cout << "NO";
}