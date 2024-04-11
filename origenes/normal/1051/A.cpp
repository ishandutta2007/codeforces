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

int T;
string s;

int main() {
  cin >> T;
  while (T--) {
    cin >> s;
    int cnt_d = 0, cnt_u = 0, cnt_l = 0;
    for (auto it : s) {
      if (isdigit(it)) cnt_d++;
      else if (isupper(it)) cnt_u++;
      else cnt_l++;
    }
    if (cnt_d && cnt_u && cnt_l) {
      cout << s << '\n';
      continue;
    }
    if (cnt_d) {
      if (cnt_u) {
        if (cnt_d > 1) {
          for (auto &it : s) if (isdigit(it)) {
            it = 'a';
            break;
          }
        } else {
          for (auto &it : s) if (isupper(it)) {
            it = 'a';
            break;
          }
        }
      } else if (cnt_l) {
        if (cnt_d > 1) {
          for (auto &it : s) if (isdigit(it)) {
              it = 'A';
              break;
            }
        } else {
          for (auto &it : s) if (islower(it)) {
              it = 'A';
              break;
            }
        }
      } else {
        s[0] = 'a', s[1] = 'A';
      }
    } else if (cnt_u) {
      if (cnt_l) {
        if (cnt_u > 1) {
          for (auto &it : s) if (isupper(it)) {
            it = '0';
            break;
          }
        } else {
          for (auto &it : s) if (islower(it)) {
            it = '0';
            break;
          }
        }
      } else {
        s[0] = '0';
        s[1] = 'a';
      }
    } else s[0] = '0', s[1] = 'A';
    cout << s << '\n';
  }
}