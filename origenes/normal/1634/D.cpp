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

int ask(int i, int j, int k) {
  cout << "? " << i << ' ' << j << ' ' << k << endl;
  int ret; cin >> ret;
  return ret;
}

void answer(int i, int j) {
  cout << "! " << i << ' ' << j << endl;
}

void solve() {
  int n; cin >> n;
  int X = ask(1, 2, 3);
  int x = 1, y = 2, z = 3;
  FOR(i, 4, n) {
    int Y = ask(x, y, i), Z = ask(x, z, i);
    if (Y < Z) {
      if (X < Z) {
        y = i;
        X = Z;
      }
    } else {
      if (X < Y) {
        z = i;
        X = Y;
      }
    }
  }
  int id = 1;
  while (id == x || id == y || id == z) id++;
  int c[3] = {ask(id, y, z), ask(x, id, z), ask(x, y, id)};
  if (X == c[0]) answer(y, z);
  else if (X == c[1]) answer(x, z);
  else answer(x, y);
}

int main() {
  int T; cin >> T;
  while (T--) solve();
}