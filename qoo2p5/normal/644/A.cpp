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

int n, a, b;
int ans[200][200];

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

  cin >> n >> a >> b;

  if (n > a * b) {
    cout << "-1\n";
    return 0;
  }

  int cur = 1;
  for (int i = 0; i < a; i++) {
    for (int j = i % 2; j < b; j += 2) {
      if (cur <= n) ans[i][j] = cur;
      cur += 2;
    }
  }

  cur = 2;
  for (int i = 0; i < a; i++) {
    for (int j = !(i % 2); j < b; j += 2) {
      if (cur <= n) ans[i][j] = cur;
      cur += 2;
    }
  }

  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }

#ifdef DEBUG
  cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

  return 0;
}