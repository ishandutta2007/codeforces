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

const int maxn = 112345;

inline bool vowel(char ch) {
  return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int n;
string s[maxn];
map<pair<int, char>, vector<int>> tab;
map<int, vector<int>> rem;
vector<pii> ans[2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  REP(i, n) {
    cin >> s[i];
    int cnt = 0;
    char last;
    for (auto now : s[i]) if (vowel(now)) {
      cnt++;
      last = now;
    }
    tab[mp(cnt, last)].eb(i);
  }
  int cnt[2] = {};
  for (const auto &it : tab) {
    cnt[0] += it._2.size() / 2;
    int last = -1;
    for (auto i : it._2) {
      if (last == -1) last = i;
      else {
        ans[0].eb(last, i);
        last = -1;
      }
    }
    if (last != -1) rem[it._1._1].eb(last);
  }
  for (const auto &it : rem) {
    cnt[1] += it._2.size() / 2;
    int last = -1;
    for (auto i : it._2) {
      if (last == -1) last = i;
      else {
        ans[1].eb(last, i);
        last = -1;
      }
    }
  }
  cout << min(cnt[0], cnt[0] + cnt[1] >> 1) << '\n';
  while (ans[0].size() > ans[1].size() + 1) {
    ans[1].eb(ans[0].back());
    ans[0].pop_back();
  }
  if (ans[0].size() > ans[1].size()) ans[0].pop_back();
  REP(i, int(ans[0].size())) {
    cout << s[ans[1][i]._1] << ' ' << s[ans[0][i]._1] << '\n';
    cout << s[ans[1][i]._2] << ' ' << s[ans[0][i]._2] << '\n';
  }
}