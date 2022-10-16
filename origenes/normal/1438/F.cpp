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

int n, h;
int cnt[1 << 18];

int ask(int u, int v, int w) {
  cout << "? " << u << ' ' << v << ' ' << w << endl;
  int a;
  cin >> a;
  return a;
}

int main() {
  cin >> h;
  n = (1 << h) - 1;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<> rand_int(1, n);
  REP(i, 420) {
    int u, v, w;
    do {
      u = rand_int(rng);
      v = rand_int(rng);
      w = rand_int(rng);
    } while (u == v || v == w || u == w);
    int a = ask(u, v, w);
    cnt[a]++;
  }
  int best[2] = {};
  FOR(i, 1, n) {
    if (cnt[i] > cnt[best[0]]) {
      best[1] = best[0];
      best[0] = i;
    } else if (cnt[i] > cnt[best[1]]) best[1] = i;
  }
  FOR(i, 1, n) if (i != best[0] && i != best[1]) {
    int r = ask(best[0], best[1], i);
    if (r == i) {
      cout << "! " << r << endl;
      return 0;
    }
  }
}