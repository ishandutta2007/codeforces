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

int ask(int x) {
  cout << "? " << x << endl;
  int v; cin >> v;
  return v;
}

int main() {
  int n, k; cin >> n >> k;
  int sz = sqrt(n) + 1;
  FOR(i, 1, sz) ask(1);
  int p, v;
  for (int i = 1; ; i += sz) {
    i %= n;
    if (!i) i = n;
    v = ask(i);
    if (v > k) {
      p = i;
      break;
    }
  }
  while (v != k) {
    p = (p + n - 1) % n;
    if (!p) p = n;
    v = ask(p);
  }
  cout << "! " << p << endl;
}