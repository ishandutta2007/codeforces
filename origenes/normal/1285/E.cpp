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

const int maxn = 212345;

int n;
pii seg[maxn];

void solve() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%d%d", &seg[i]._1, &seg[i]._2);
    seg[i]._1 *= 2, seg[i]._2 *= 2;
  }
  sort(seg + 1, seg + n + 1);
  int inc = -1, ans = 0, j;
  FOR(i, 1, n) {
    j = i + 1;
    int en = seg[i]._2;
    while (j <= n && seg[j]._1 <= en) {
      chkmax(en, seg[j]._2);
      j++;
    }
    j--;
    ans++;
    if (i == j) continue;
    if (j >= i + 1) chkmax(inc, 0);
    map<int, int> cnt;
    FOR(k, i, j) {
      cnt[seg[k]._1]++;
      cnt[seg[k]._2 + 1]--;
    }
    int tot = 0, pre = -2e9 - 20;
    vector<pii> consider;
    for (auto it : cnt) {
      int now = it._1 - 1;
      if (tot == 1 && pre != seg[i]._1 && now != en) consider.eb(pre, now);
      tot += it._2;
      pre = now + 1;
    }
    map<int, int> rec;
    int k = i;
    for (auto it : consider) {
      while (k <= j && seg[k]._2 <= it._1) k++;
      rec[k]++;
    }
    for (auto it : rec) chkmax(inc, it._2);
    i = j;
  }
  printf("%d\n", ans + inc);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}