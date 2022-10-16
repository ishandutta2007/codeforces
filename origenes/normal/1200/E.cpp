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

vector<int> get_fail(const string &s) {
  int n = s.length();
  vector<int> f(n);
  int j = 0;
  FOR(i, 1, n - 1) {
    while (j && s[i] != s[j]) j = f[j - 1];
    if (s[i] == s[j]) j++;
    f[i] = j;
  }
  return f;
}

string ans, s;
int T;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> T;
  while (T--) {
    cin >> s;
    auto f = get_fail(s);
    int n = ans.length(), m = s.length(), d = max(0, n - m), j = 0;
    FOR(i, d, n - 1) {
      while (j && ans[i] != s[j]) j = f[j - 1];
      if (ans[i] == s[j]) j++;
    }
    ans += s.substr(j);
  }
  cout << ans;
}