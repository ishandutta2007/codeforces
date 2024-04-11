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

const int maxn = 1123;

int n, a[maxn];

int f(int k) {
  return n - k - (n + k - 1) / k + 1;
}

void query(int k, int &cur) {
  cout << k;
  int have = 0;
  REP(i, n) if (!a[i]) {
    cout << ' ' << i + 1;
    a[i] = 1;
    have++, cur++;
    if (have == k) break;
  }
  cout << endl;
  int x;
  cin >> x;
  REP(i, k) if (a[(x + i - 1) % n] == 1) {
    a[(x + i - 1) % n] = 0;
    cur--;
  }
}

int main() {
  cin >> n;
  int k = 1;
  FOR(i, 2, n) if (f(i) > f(k)) k = i;
  for (int i = 0; i < n; i += k) a[i] = -1;
  int cur = 0;
  while (cur < f(k)) query(k, cur);
  cout << 0 << endl;
}