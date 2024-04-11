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
const ld EPS = 1e-9;
const ld PI = 3.141592653589;

#define TASKNAME ""

int cnt[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

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

  int a, b;
  cin >> a >> b;

  ll ans = 0;

  for (int i = a; i <= b; i++) {
    int j = i;
    while (j) {
      ans += cnt[j % 10];
      j /= 10;
    }
  }

  cout << ans << endl;

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

    return 0;
}