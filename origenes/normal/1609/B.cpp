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
  int n, q;
  cin >> n >> q;
  string s; cin >> s;
  int cnt = 0;
  REP(i, n - 2) if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') cnt++;
  while (q--) {
    int p; string ch;
    cin >> p >> ch;
    p--;
    char c = ch[0];
    if (s[p] == 'a' && p < n - 2) {
      if (s[p + 1] == 'b' && s[p + 2] == 'c') cnt--;
    }
    if (s[p] == 'b' && p < n - 1 && p > 0) {
      if (s[p - 1] == 'a' && s[p + 1] == 'c') cnt--;
    }
    if (s[p] == 'c' && p > 1) {
      if (s[p - 2] == 'a' && s[p - 1] == 'b') cnt--;
    }
    s[p] = c;
    if (s[p] == 'a' && p < n - 2) {
      if (s[p + 1] == 'b' && s[p + 2] == 'c') cnt++;
    }
    if (s[p] == 'b' && p < n - 1 && p > 0) {
      if (s[p - 1] == 'a' && s[p + 1] == 'c') cnt++;
    }
    if (s[p] == 'c' && p > 1) {
      if (s[p - 2] == 'a' && s[p - 1] == 'b') cnt++;
    }
    cout << cnt << '\n';
  }
}