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

const int maxq = 13;

ll ask(const vector<int> &v) {
  cout << "? " << v.size();
  for (auto x : v) cout << ' ' << x + 1;
  cout << endl;
  ll ret;
  cin >> ret;
  return ret;
}

vector<int> q[maxq];
int n;
ll ret[maxq];

int main() {
  cin >> n;
  vector<int> mask(n);
  int tail = 0;
  REP(i, 1 << maxq) if (__builtin_popcount(i) == 6) {
    mask[tail] = i;
    REP(j, maxq) if ((i & (1 << j)) == 0) q[j].eb(tail);
    if (++tail == n) break;
  }
  REP(i, maxq) if (!q[i].empty()) ret[i] = ask(q[i]);
  vector<ll> ans(n);
  REP(i, n) REP(j, maxq) if (mask[i] & (1 << j)) ans[i] |= ret[j];
  cout << "!";
  for (auto x : ans) cout << ' ' << x;
  cout << endl;
}