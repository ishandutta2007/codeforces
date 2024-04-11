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

vector<int> nums;

int f(int x, int a, int b) {
  return max(abs(nums[x] - nums[a]), abs(nums[x] - nums[b]));
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

  int n, k;
  cin >> n >> k;
  k++;

  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    if (c == '0') {
      nums.pb(i);
    }
  }

  int m = sz(nums);

  int ans = INF;
  int best = 0;
  int j = k - 1;
  for (int i = 0; i < m - k + 1; i++, j++) {
    while (best + 1 <= j && f(best + 1, i, j) <= f(best, i, j)) best++;
    ans = min(ans, f(best, i, j));
  }

  cout << ans << endl;

#ifdef DEBUG
  cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

  return 0;
}