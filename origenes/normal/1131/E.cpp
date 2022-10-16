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

const int maxn = 1123456;

ll ans[26], tmp[26];
int n, pcnt[maxn], scnt[maxn];
string p[maxn];
char pref[maxn], suf[maxn];
bool same[maxn];

inline int idx(char ch) {
  return ch - 'a';
}

void get_cnt(ll *ans, const string &p) {
  memset(ans, 0, 26 * sizeof(ll));
  int sz = p.size();
  for (int i = 0; i < sz; ) {
    int now = 0;
    while (i + now < sz && p[i] == p[i + now]) now++;
    chkmax(ans[idx(p[i])], ll(now));
    i += now;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  FOR(i, 1, n) {
    cin >> p[i];
    same[i] = true;
    int sz = p[i].size();
    REP(j, sz) if (p[i][j] != p[i][0]) {
        same[i] = false;
        break;
      }
    if (!same[i]) {
      REP(j, sz) if (p[i][j] != p[i][0]) {
          pcnt[i] = j;
          break;
        }
      FOR(j, 1, sz) if (p[i][sz - j] != p[i][sz - 1]) {
          scnt[i] = j - 1;
          break;
        }
      pref[i] = p[i][0], suf[i] = p[i].back();
    }
  }
  get_cnt(ans, p[1]);
  FOR(i, 2, n) {
    if (same[i]) {
      int ch = idx(p[i][0]);
      if (ans[ch] > 1e9) ans[ch] = 1e9 + 5;
      else ans[ch] = ans[ch] + ll(p[i].size()) * (ans[ch] + 1);
      REP(j, 26) if (j != ch) chkmin(ans[j], 1LL);
    } else {
      if (pref[i] == suf[i]) {
        int ch = idx(pref[i]);
        if (!ans[ch]) {
          get_cnt(tmp, p[i]);
          REP(j, 26) ans[j] = max(ll(ans[j] > 0), tmp[j]);
        } else {
          get_cnt(tmp, p[i]);
          REP(j, 26) ans[j] = max(ll(ans[j] > 0), tmp[j]);
          chkmax(ans[ch], ll(pcnt[i] + scnt[i] + 1));
        }
      } else {
        int ch1 = idx(pref[i]), ch2 = idx(suf[i]), t1 = ans[ch1] > 0, t2 = ans[ch2] > 0;
        get_cnt(tmp, p[i]);
        REP(j, 26) ans[j] = max(ll(ans[j] > 0), tmp[j]);
        chkmax(ans[ch1], ll(pcnt[i] + t1));
        chkmax(ans[ch2], ll(scnt[i] + t2));
      }
    }
  }
  ll res = 0;
  REP(i, 26) chkmax(res, ans[i]);
  assert(res < 1e9 + 1);
  cout << res;
}