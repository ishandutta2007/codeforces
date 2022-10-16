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

const ll LIM = 1LL << 32;

int l, n;
stack<pair<int, bool>> s;
string op;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> l;
  ll now = 1, tot = 0;
  while (l--) {
    cin >> op;
    if (op[0] == 'f') {
      cin >> n;
      if (now < LIM) {
        now *= n;
        s.emplace(n, true);
      } else {
        s.emplace(n, false);
      }
    } else if (op[0] == 'e') {
      assert(s.size());
      auto cur = s.top(); s.pop();
      if (cur._2) now /= cur._1;
    } else {
      if (now >= LIM) {
        cout << "OVERFLOW!!!";
        return 0;
      }
      tot += now;
      if (tot >= LIM) {
        cout << "OVERFLOW!!!";
        return 0;
      }
    }
  }
  cout << tot;
}