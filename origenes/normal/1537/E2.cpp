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
  int n, k;
  string s;
  cin >> n >> k;
  cin >> s;
  while (s.size() > k) s.pop_back();
  for (int i = 1; i < s.size(); i++) {
    if (s[i] > s[0]) {
      s = s.substr(0, i);
      break;
    }
    int j = 0;
    while (j <= i - 1) {
      if (s[j] < s[(i + j) % s.size()]) {
        s = s.substr(0, i);
        j++;
        break;
      }
      if (s[j] > s[(i + j) % s.size()]) {
        j++;
        break;
      }
      j++;
    }
    i += j - 1;
  }
  while (s.size() < k) {
    for (int i = 1; i < s.size(); i++) {
      if (s[i] > s[0]) {
        s = s.substr(0, i);
        break;
      }
      int j = 0;
      while (j <= i - 1) {
        if (s[j] < s[(i + j) % s.size()]) {
          s = s.substr(0, i);
          j++;
          break;
        }
        if (s[j] > s[(i + j) % s.size()]) {
          j++;
          break;
        }
        j++;
      }
      i += j - 1;
    }
    s += s;
  }
  while (s.size() > k) s.pop_back();
  cout << s;
}