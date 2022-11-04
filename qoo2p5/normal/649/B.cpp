#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (int) x.size()
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

#ifdef DEBUG
  #define debug(x) cerr << "\033[31m" << x << "\033[39m" << endl;
#else
  #define debug(x)
#endif

const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-10;
const ld PI = 3.141592653589;
const int MOD = 1e9 + 7;

#define TASKNAME ""

int n, m, k;
int a, b;

int up(int f, int t) {
  return min(10 + abs(f - t), 5 * abs(f - t));
}

int v(int f, int t) {
  return 15 * min(abs(f - t), n - abs(f - t));
}

int main() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  float tbegin = clock();
  srand(42);

#ifdef DEBUG
  freopen("input.txt", "r", stdin);
#else
  if (TASKNAME != "") {
    freopen(TASKNAME ".in", "r", stdin);
    freopen(TASKNAME ".out", "w", stdout);
  }
#endif

  cin >> n >> m >> k;
  cin >> a >> b;
  a--;
  b--;

  int z1 = a % k;
  int y1 = ((a - z1) % (m * k)) / k;
  int x1 = a / (m * k);
  int z2 = b % k;
  int y2 = ((b - z2) % (m * k)) / k;
  int x2 = b / (m * k);

  if (x1 == x2) {
    cout << up(y1, y2) << endl;
    return 0;
  }

  debug(x1 << " " << y1 << " " << z1);
  debug(x2 << " " << y2 << " " << z2);

  cout << v(x1, x2) + up(y1, 0) + up(0, y2) << endl;

#ifdef DEBUG
  cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

  return 0;
}