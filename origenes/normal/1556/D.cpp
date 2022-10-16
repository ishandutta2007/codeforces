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

const int maxn = 11234;

int a[maxn];

int ask(int i, int j) {
  int x, y;
  cout << "and " << i << ' ' << j << endl;
  cin >> x;
  cout << "or " << i << ' ' << j << endl;
  cin >> y;
  return x + y;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> b(4, vector<int>(4));
  FOR(i, 1, 3) FOR(j, i + 1, 3) b[i][j] = ask(i, j);
  a[1] = (b[1][2] + b[1][3] - b[2][3]) / 2;
  a[2] = b[1][2] - a[1];
  a[3] = b[1][3] - a[1];
  FOR(i, 4, n) a[i] = ask(1, i) - a[1];
  sort(a + 1, a + n + 1);
  cout << "finish " << a[k] << endl;
}