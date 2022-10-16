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
  int l = 0, r = s.length() - 1;
  string ans;
  while (r - l + 1 > 3) {
    if (s[l] == s[r]) {
      ans += s[l];
      l++, r--;
    } else if (s[l] == s[r - 1]) {
      ans += s[l];
      l++, r -= 2;
    } else if (s[l + 1] == s[r]) {
      ans += s[l + 1];
      l += 2, r--;
    } else {
      ans += s[l + 1];
      l += 2, r -= 2;
    }
  }
  cout << ans;
  if (l <= r) cout << s[l];
  reverse(all(ans));
  cout << ans;
}