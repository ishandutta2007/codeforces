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

const int maxn = 1123456;

int n;
char s[maxn];
int len[maxn][2];
vector<int> G[maxn][2];

int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  ROF(i, n, 1) {
    if (s[i] != '0') len[i][1] = len[i + 1][1] + 1;
    if (s[i] != '1') len[i][0] = len[i + 1][0] + 1;
  }
  REP(j, 2) {
    int i = 1;
    while (i <= n) {
      if (s[i] == j + '0') {
        i++;
        continue;
      }
      int en = i + 1;
      while (en <= n && s[en] != '0' + j) en++;
      FOR(k, 1, en - i) G[k][j].eb(i);
      i = en;
    }
  }
  FOR(i, 1, n) {
    int now = 1, ans = 0;
    int pos[2] = {};
    while (now <= n) {
      int nxt = 1e9;
      REP(j, 2) {
        if (len[now][j] >= i) chkmin(nxt, now + i);
        while (pos[j] < G[i][j].size() && now > G[i][j][pos[j]]) pos[j]++;
        if (pos[j] < G[i][j].size()) chkmin(nxt, G[i][j][pos[j]] + i);
      }
      if (nxt < 5e8) ans++;
      now = nxt;
    }
    printf("%d ", ans);
  }
}