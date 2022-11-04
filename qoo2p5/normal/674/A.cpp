#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (ll) x.size()
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
const ll MOD = 1e9 + 7;

#define TASKNAME ""

const int N = 5005;

int n;
int t[N];
int a[N];
int cur[N];

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

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }

  for (int i = 0; i < n; i++) {
    fill(cur, cur + n + 1, 0);
    int max_cnt = 0;
    int max_color = 0;

    for (int j = i; j < n; j++) {
      cur[t[j]]++;
      if (cur[t[j]] > max_cnt || (cur[t[j]] == max_cnt && t[j] < max_color)) {
        max_cnt = cur[t[j]];
        max_color = t[j];
      }

      a[max_color]++;
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}