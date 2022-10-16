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
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1), cnt(n + 1);
  FOR(i, 1, n) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int need = (n + k + 1) / 2, x, y, now = 0;
  x = 1, y = 0;
  while (now < need) now += cnt[++y];
  int j = y;
  FOR(i, 2, n) {
    now -= cnt[i - 1];
    while (j < n && now < need) now += cnt[++j];
    if (now >= need && j - i < y - x) {
      x = i;
      y = j;
    }
  }
  cout << x << ' ' << y << '\n';
  int l = 1, r = 0, c;
  FOR(i, 1, k - 1) {
    c = 0;
    while (c <= 0) {
      r++;
      if (x <= a[r] && a[r] <= y) c++;
      else c--;
    }
    cout << l << ' ' << r << '\n';
    l = r + 1;
  }
  cout << l << ' ' << n << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}