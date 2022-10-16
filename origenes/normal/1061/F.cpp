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

int n, k, dep = 1;

int main() {
  cin >> n >> k;
  int now = 1;
  while (now < n) {
    now = now * k + 1;
    dep ++;
  }
  srand(time(NULL));
  vector<int> vec;
  int u, v;
  while (true) {
    u = rand() % n + 1, v = rand() % n + 1;
    while (u == v) v = rand() % n + 1;
    FOR(i, 1, n) {
      cout << "? " << u << ' ' << i << ' ' << v << endl;
      string tmp;
      cin >> tmp;
      if (tmp[0] == 'Y') vec.eb(i);
    }
    if (vec.size() == dep * 2 - 1) break;
    vec.clear();
  }
  shuffle(all(vec), default_random_engine(rand()));
  for (auto w : vec) {
    int cnt = 0;
    FOR(i, 1, n) {
      cout << "? " << u << ' ' << i << ' ' << w << endl;
      string tmp;
      cin >> tmp;
      cnt += tmp[0] == 'Y';
    }
    if (cnt == dep) {
      cout << "! " << w << endl;
      return 0;
    }
  }
}