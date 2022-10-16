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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    string s, e, o;
    cin >> s;
    for (auto it : s) {
      if (it & 1) o += it;
      else e += it;
    }
    sort(all(e));
    sort(all(o));
    if (e.empty() || o.empty()) {
      cout << e + o << '\n';
      continue;
    }
    if (abs(e.back() - o.front()) != 1) {
      cout << e + o << '\n';
      continue;
    }
    if (abs(o.back() - e.front()) != 1) {
      cout << o + e << '\n';
      continue;
    }
    cout << "No answer\n";
  }
}