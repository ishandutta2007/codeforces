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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

string s;
vector<string> ok;

string go(const string &s) {
  int i = 0;
  while (i + 1 < int(s.length()) && s[i] == '0') i++;
  return s.substr(i);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> s;
  int rem = 0;
  for (auto it : s) rem += it - '0';
  rem %= 3;
  if (rem) {
    ROF(i, int(s.length()) - 1, 0) {
      if ((s[i] - '0') % 3 == rem) {
        string now = s.substr(0, i) + s.substr(i + 1);
        now = go(now);
        if (!now.empty()) ok.eb(now);
        break;
      }
    }
    int pre = -1;
    ROF(i, int(s.length()) - 1, 0) if ((s[i] - '0') % 3 == 3 - rem) {
        if (pre == -1) {
          pre = i;
          continue;
        }
        string now = s.substr(0, i) + s.substr(i + 1, pre - i - 1) + s.substr(pre + 1);
        now = go(now);
        if (!now.empty()) ok.eb(now);
        break;
      }
  } else ok.eb(s);
  if (ok.empty()) {
    cout << -1;
    return 0;
  }
  string ans;
  for (const auto &it : ok) if (it.length() > ans.length()) ans = it;
  cout << ans;
}