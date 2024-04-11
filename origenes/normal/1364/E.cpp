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

const int maxn = 2123;

int n, p[maxn];

int ask(int i, int j) {
  cout << "? " << i << ' ' << j << endl;
  int ret;
  cin >> ret;
  return ret;
}

void answer() {
  cout << '!';
  FOR(i, 1, n) cout << ' ' << p[i];
  cout << endl;
}

int main() {
  cin >> n;
  vector<int> perm(n);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  iota(all(perm), 1);
  shuffle(all(perm), rng);
  int x = perm[0], y = perm[1], v = ask(x, y);
  FOR(i, 2, n - 1) {
    int now = ask(y, perm[i]);
    if (now < v) {
      x = perm[i];
      v = now;
    } else if (now == v) {
      y = perm[i];
      v = ask(x, y);
    }
  }
  int zero;
  while (true) {
    int idx = uniform_int_distribution<int>(1, n)(rng);
    if (idx != x && idx != y) {
      int ax = ask(x, idx), ay = ask(y, idx);
      if (ax != ay) {
        zero = ax < ay ? x : y;
        break;
      }
    }
  }
  FOR(i, 1, n) if (i != zero) p[i] = ask(i, zero);
  answer();
}