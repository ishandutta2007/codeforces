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

const int maxn = 212345;

int fen[maxn], n, q, lis[maxn];
int ans[maxn][9];

inline int lowbit(int x) {
  return x & -x;
}

void inc(int x) {
  while (x <= n) {
    fen[x]++;
    x += lowbit(x);
  }
}

int sum(int x) {
  int ret = 0;
  while (x > 0) {
    ret += fen[x];
    x -= lowbit(x);
  }
  return ret;
}

struct Event {
  int y, id, pt;

  Event(int y, int id, int pt) : y(y), id(id), pt(pt) {}
};

vector<Event> qry[maxn];

int main() {
  scanf("%d%d", &n, &q);
  FOR(i, 1, n) scanf("%d", lis + i);
  FOR(i, 1, q) {
    int l, r, u, d;
    scanf("%d%d%d%d", &l, &d, &r, &u);
    qry[l - 1].eb(d - 1, i, 0);
    qry[l - 1].eb(u, i, 3);
    qry[l - 1].eb(n, i, 6);
    qry[r].eb(d - 1, i, 1);
    qry[r].eb(u, i, 4);
    qry[r].eb(n, i, 7);
    qry[n].eb(d - 1, i, 2);
    qry[n].eb(u, i, 5);
    qry[n].eb(n, i, 8);
  }
  FOR(i, 1, n) {
    inc(lis[i]);
    for (const auto &it : qry[i]) ans[it.id][it.pt] = sum(it.y);
  }
  FOR(i, 1, q) {
    int cnt[9] = {};
    cnt[0] = ans[i][0];
    cnt[1] = ans[i][1] - ans[i][0];
    cnt[2] = ans[i][2] - ans[i][1];
    cnt[3] = ans[i][3] - ans[i][0];
    cnt[4] = ans[i][4] + ans[i][0] - ans[i][3] - ans[i][1];
    cnt[5] = ans[i][5] + ans[i][1] - ans[i][4] - ans[i][2];
    cnt[6] = ans[i][6] - ans[i][3];
    cnt[7] = ans[i][7] + ans[i][3] - ans[i][6] - ans[i][4];
    cnt[8] = ans[i][8] + ans[i][4] - ans[i][7] - ans[i][5];
    ll res = ll(cnt[0]) * (cnt[4] + cnt[5] + cnt[7] + cnt[8]);
    res += ll(cnt[1]) * (cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8]);
    res += ll(cnt[2]) * (cnt[3] + cnt[4] + cnt[6] + cnt[7]);
    res += ll(cnt[3]) * (cnt[4] + cnt[5] + cnt[7] + cnt[8]);
    res += ll(cnt[4]) * (cnt[5] + cnt[6] + cnt[7] + cnt[8]);
    res += ll(cnt[5]) * (cnt[6] + cnt[7]);
    res += ll(cnt[4]) * (cnt[4] - 1) / 2;
    printf("%lld\n", res);
  }
}