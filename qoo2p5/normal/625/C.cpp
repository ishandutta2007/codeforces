#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (int) x.size()
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-10;
const ld PI = 3.141592653589;

#define TASKNAME ""

int n, k;
int ans[500][500];

int main() {
  ios::sync_with_stdio(false);
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

  cin >> n >> k;
  k--;

  int cur = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      ans[i][j] = cur++;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = k; j < n; j++) {
      ans[i][j] = cur++;
    }
  }

  ll sum = 0;
  for (int i = 0; i < n; i++) {
    sum += ans[i][k];
  }

  cout << sum << endl;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

  return 0;
}