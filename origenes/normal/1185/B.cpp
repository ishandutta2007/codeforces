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
  int n;
  cin >> n;
  while (n--) {
    string s, t;
    cin >> s >> t;
    if (s.length() > t.length()) {
      cout << "NO\n";
      continue;
    }
    int x = 0, y = 0;
    bool good = true;
    while (x != s.length() && y != t.length()) {
      int i = 0, j = 0;
      while (x + i != s.length() && s[x + i] == s[x]) i++;
      while (y + j != t.length() && t[y + j] == t[y]) j++;
      if (s[x] != t[y] || i > j) {
        good = false;
        break;
      }
      x = x + i, y = y + j;
    }
    if (x != s.length() || y != t.length()) good = false;
    cout << (good ? "YES" : "NO") << '\n';
  }
}