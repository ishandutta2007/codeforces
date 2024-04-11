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

const int maxn = 1123;

int n, a[maxn * 2];

void solve() {
  scanf("%d", &n);
  FOR(i, 1, 2 * n) scanf("%d", a + i);
  vector<int> even, odd;
  FOR(i, 1, 2 * n) {
    if (a[i] % 2 == 1) odd.eb(i);
    else even.eb(i);
  }
  if (odd.size() % 2 == 1) {
    odd.pop_back();
    even.pop_back();
  } else {
    if (!odd.empty()) odd.pop_back(), odd.pop_back();
    else even.pop_back(), even.pop_back();
  }
  for (int i = 0; i < odd.size(); i += 2) printf("%d %d\n", odd[i], odd[i + 1]);
  for (int i = 0; i < even.size(); i += 2) printf("%d %d\n", even[i], even[i + 1]);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}