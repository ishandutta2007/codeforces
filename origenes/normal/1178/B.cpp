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
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string s;
  cin >> s;
  int n = s.length();
  vector<char> t;
  REP(i, n) {
    if (s[i] == 'o') t.eb('o');
    else {
      if (!i || s[i - 1] != 'v') continue;
      t.eb('w');
    }
  }
  n = t.size();
  vector<int> pre(n), suf(n);
  if (!n) {
    cout << 0;
    return 0;
  }
  pre[0] = t[0] == 'w';
  FOR(i, 1, n - 1) pre[i] = pre[i - 1] + (t[i] == 'w');
  suf[n - 1] = t[n - 1] == 'w';
  ROF(i, n - 2, 0) suf[i] = suf[i + 1] + (t[i] == 'w');
  ll ans = 0;
  REP(i, n) if (t[i] == 'o') ans += ll(pre[i]) * suf[i];
  cout << ans;
}