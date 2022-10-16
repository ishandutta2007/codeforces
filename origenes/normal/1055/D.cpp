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

const int maxn = 3123;

string s[maxn], t[maxn];
int n, lo[maxn], hi[maxn];

int pos(const string &s, const string &t) {
  int n = s.length(), m = t.length();
  vector<int> f(maxn);
  FOR(i, 1, m - 1) {
    int j = f[i];
    while (j && t[i] != t[j]) j = f[j];
    f[i + 1] = t[i] == t[j] ? j + 1 : 0;
  }
  int j = 0;
  REP(i, n) {
    while (j && s[i] != t[j]) j = f[j];
    if (s[i] == t[j]) j++;
    if (j == m) return i - m + 1;
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  vector<int> same, diff;
  string need[2];
  FOR(i, 1, n) cin >> s[i];
  FOR(i, 1, n) {
    cin >> t[i];
    if (s[i] == t[i]) same.eb(i);
    else {
      diff.eb(i);
      int len = s[i].length();
      REP(j, len) if (s[i][j] != t[i][j]) {
        lo[i] = j;
        break;
      }
      ROF(j, len - 1, 0) if (s[i][j] != t[i][j]) {
        hi[i] = j;
        break;
      }
    }
  }
  need[0] = s[diff.front()].substr(lo[diff.front()], hi[diff.front()] - lo[diff.front()] + 1);
  need[1] = t[diff.front()].substr(lo[diff.front()], hi[diff.front()] - lo[diff.front()] + 1);
  for (auto it : diff)
    if (s[it].substr(lo[it], hi[it] - lo[it] + 1) != need[0] || t[it].substr(lo[it], hi[it] - lo[it] + 1) != need[1]) {
      cout << "NO";
      return 0;
    }
  int pre = 0, post = 0;
  while (true) {
    if (lo[diff.front()] <= pre) break;
    char good = s[diff.front()][lo[diff.front()] - pre - 1];
    bool bad = false;
    for (auto it : diff) {
      int l = lo[it] - pre - 1;
      if (l < 0 || s[it][l] != good) {
        bad = true;
        break;
      }
    }
    if (bad) break;
    pre++;
  }
  while (true) {
    if (hi[diff.front()] + post + 1 >= s[diff.front()].length()) break;
    char good = s[diff.front()][hi[diff.front()] + post + 1];
    bool bad = false;
    for (auto it : diff) {
      int r = hi[it] + post + 1;
      if (r >= s[it].length() || s[it][r] != good) {
        bad = true;
        break;
      }
    }
    if (bad) break;
    post++;
  }
  need[0] = s[diff.front()].substr(lo[diff.front()] - pre, hi[diff.front()] + post + 1 - lo[diff.front()] + pre);
  need[1] = t[diff.front()].substr(lo[diff.front()] - pre, hi[diff.front()] + post + 1 - lo[diff.front()] + pre);
  for (auto it : diff) if (pos(s[it], need[0]) != lo[it] - pre) {
    cout << "NO";
    return 0;
  }
  for (auto it : same) if (pos(s[it], need[0]) != -1) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n" << need[0] << '\n' << need[1];
}