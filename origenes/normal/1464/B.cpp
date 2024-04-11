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
  string s;
  ll x, y;
  cin >> s >> x >> y;
  if (x > y) {
    reverse(all(s));
    swap(x, y);
  }
  ll sum = 0;
  int pre[2] = {}, suf[2] = {};
  for (auto ch : s) {
    if (ch == '0' || ch == '?') {
      sum += y * pre[1];
      pre[0]++;
    } else {
      sum += x * pre[0];
      pre[1]++;
    }
  }
  ll ans = sum;
  ROF(i, s.length() - 1, 0) {
    if (s[i] == '?') {
      pre[0]--;
      sum -= x * suf[1] + y * pre[1];
      sum += x * pre[0] + y * suf[0];
      chkmin(ans, sum);
      suf[1]++;
    } else if (s[i] == '0') {
      pre[0]--;
      suf[0]++;
    } else {
      pre[1]--;
      suf[1]++;
    }
  }
  cout << ans;
}