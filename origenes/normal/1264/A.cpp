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
  int n; scanf("%d", &n);
  map<int, int> cnt;
  FOR(i, 1, n) {
    int p;
    scanf("%d", &p);
    cnt[p]++;
  }
  int allowed = n / 2, g = 0, s = 0, b = 0;
  auto it = cnt.rbegin(); g = it->_2;
  it++;
  while (it != cnt.rend() && g + s < allowed) {
    s += it->_2;
    it++;
    if (s > g) break;
  }
  while (it != cnt.rend() && g + s + b <= allowed) {
    if (g + s + b + it->_2 <= allowed) b += it->_2;
    else break;
    it++;
  }
  if (g && s && b && s > g && b > g && g + s + b <= allowed) printf("%d %d %d\n", g, s, b);
  else puts("0 0 0");
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}