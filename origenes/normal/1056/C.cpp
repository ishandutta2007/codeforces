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

const int maxn = 2123;

int n, m, lis[maxn];
int a[maxn], b[maxn];

int main() {
  cin >> n >> m;
  set<pii, greater<>> p;
  FOR(i, 1, 2 * n) {
    cin >> lis[i];
    p.emplace(lis[i], i);
  }
  set<int> pp;
  map<int, int> mmap;
  FOR(i, 1, m) {
    cin >> a[i] >> b[i];
    if (lis[a[i]] < lis[b[i]]) swap(a[i], b[i]);
    pp.emplace(i);
    mmap[a[i]] = mmap[b[i]] = i;
    p.erase(mp(lis[a[i]], a[i]));
    p.erase(mp(lis[b[i]], b[i]));
  }
  int turn;
  cin >> turn;
  if (turn == 1) {
    for (auto it : pp) {
      cout << a[it] << endl;
      int now;
      cin >> now;
      assert(now == b[it]);
    }
    while (!p.empty()) {
      cout << p.begin()->_2 << endl;
      p.erase(p.begin());
      int now;
      cin >> now;
      p.erase({lis[now], now});
    }
  } else {
    int now;
    while (true) {
      cin >> now;
      if (p.count({lis[now], now})) {
        p.erase({lis[now], now});
        break;
      }
      int i = mmap[now];
      cout << (a[i] == now ? b[i] : a[i]) << endl;
      pp.erase(i);
      if (pp.empty() && p.empty()) break;
    }
    for (auto it : pp) {
      cout << a[it] << endl;
      cin >> now;
      assert(now == b[it]);
    }
    while (!p.empty()) {
      cout << p.begin()->_2 << endl;
      p.erase(p.begin());
      if (p.empty()) break;
      cin >> now;
      p.erase({lis[now], now});
    }
  }
}