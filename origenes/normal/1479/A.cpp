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

const int maxn = 112345;

int a[maxn];

void ask(int i) {
  if (a[i]) return;
  cout << "? " << i << endl;
  cin >> a[i];
}

void answer(int i) {
  cout << "! " << i << endl;
}

int main() {
  int n; cin >> n;
  a[0] = a[n + 1] = n + 1;
  int lo = 1, hi = n;
  while (lo < hi) {
    int mi = lo + hi >> 1;
    ask(mi - 1);
    ask(mi);
    ask(mi + 1);
    if (a[mi - 1] > a[mi] && a[mi] < a[mi + 1]) {
      answer(mi);
      return 0;
    }
    if (a[mi - 1] < a[mi]) hi = mi;
    else lo = mi + 1;
  }
  ask(lo);
  FOR(i, 1, n) if (a[i] > 0 && a[i - 1] > a[i] && a[i] < a[i + 1]) {
    answer(i);
    return 0;
  }
  assert(0);
}