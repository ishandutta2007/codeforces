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
  int n, k;
  string s;
  cin >> n >> k >> s;
  auto nex = [&](char c) {
    return c == 'a' || c == 'a' + k - 1 ? 'a' : c - 1;
  };
  REP(i, n) {
    if (i && i + 1 < n && s[i] > s[i + 1] && s[i - 1] > s[i + 1]) {
      swap(s[i], s[i + 1]);
      swap(s[i - 1], s[i]);
      i++;
    } else if (i && s[i - 1] > s[i]) {
      swap(s[i - 1], s[i]);
    } else if (i + 2 < n && s[i + 2] < min(nex(s[i]), nex(s[i + 1]))) {
      s[i] = nex(s[i]);
    } else if (i + 1 < n && nex(s[i + 1]) < nex(s[i])) {
      if (s[i + 1] == 'a') s[i] = nex(s[i]);
      swap(s[i], s[i + 1]);
      s[i] = nex(s[i]);
      i++;
    } else {
      s[i] = nex(s[i]);
    }
  }
  cout << s << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}