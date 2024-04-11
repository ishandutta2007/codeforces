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

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n;
  ll T;
  string s;
  cin >> n >> T;
  cin >> s;
  T = T - (1 << s[n - 1] - 'a') + (1 << s[n - 2] - 'a');
  vector<int> cnt(26);
  REP(i, n - 2) {
    T += (1 << s[i] - 'a');
    cnt[s[i] - 'a']++;
  }
  ROF(i, 25, 0) {
    ll need = 0;
    if (T > 0) need = T >> (i + 1);
    T -= min(need, ll(cnt[i])) << (i + 1);
  }
  cout << (T == 0 ? "Yes" : "No");
}