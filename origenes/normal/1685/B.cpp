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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  string s; cin >> s;
  int ca = count(all(s), 'A'), cb = count(all(s), 'B');
  if (ca != a + c + d || cb != b + c + d) {
    cout << "NO\n";
    return;
  }
  vector<int> sa, sb;
  int wildcards = 0;
  for (int i = 0; i < size(s); ) {
    int j;
    for (j = i + 1; j < size(s) && s[j] != s[j - 1]; j++);
    if (s[i] == s[j - 1]) wildcards += (j - i) / 2;
    else {
      if (s[i] == 'A') sa.eb((j - i) / 2);
      else sb.eb((j - i) / 2);
    }
    i = j;
  }
  sort(all(sa), greater<>());
  sort(all(sb), greater<>());
  while (c > 0 && !sa.empty()) {
    if (c >= sa.back()) c -= sa.back();
    else {
      d -= sa.back() - c - 1;
      c = 0;
    }
    sa.pop_back();
  }
  if (c > 0) {
    int mn = min(wildcards, c);
    c -= mn, wildcards -= mn;
  }
  while (d > 0 && !sb.empty()) {
    if (d >= sb.back()) d -= sb.back();
    else {
      c -= sb.back() - d - 1;
      d = 0;
    }
    sb.pop_back();
  }
  if (d > 0) {
    int mn = min(wildcards, d);
    d -= mn, wildcards -= mn;
  }
  while (c > 0 && !sb.empty()) {
    c -= sb.back() - 1;
    sb.pop_back();
  }
  while (d > 0 && !sa.empty()) {
    d -= sa.back() - 1;
    sa.pop_back();
  }
  if (c > 0 || d > 0) cout << "NO\n";
  else cout << "YES\n";
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}