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
  int n;
  cin >> n;
  vector<int> a(n), cnt(n + 1);
  REP(i, n) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int mx = max_element(all(cnt)) - cnt.begin();
  if (cnt[mx] > (n + 1) / 2) {
    cout << "-1\n";
    return;
  }
  int s = 0;
  fill(all(cnt), 0);
  for (int i = 0; i < n; ) {
    int j = i + 1;
    while (j < n && a[j] != a[j - 1]) j++;
    cnt[a[i]]++;
    cnt[a[j - 1]]++;
    s++;
    i = j;
  }
  mx = *max_element(all(cnt));
  cout << s - 1 + max(mx - s - 1, 0) << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}