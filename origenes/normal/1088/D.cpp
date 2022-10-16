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

int ask(int c, int d) {
  cout << "? " << c << ' ' << d << endl;
  int ret;
  cin >> ret;
  return ret;
}

void answer(int a, int b) {
  cout << "! " << a << ' ' << b << endl;
}

int bit[30];

int main() {
  REP(i, 30) bit[i] = 1 << i;
  int now = ask(0, 0), a = 0, b = 0;
  ROF(i, 29, 0) {
    int ans1 = ask(a | bit[i], b), ans2 = ask(a, b | bit[i]);
    if (ans1 == ans2) {
      if (now > 0) a |= bit[i];
      else b |= bit[i];
      now = ans1;
    } else if (ans1 < 0) {
      a |= bit[i];
      b |= bit[i];
    }
  }
  answer(a, b);
}