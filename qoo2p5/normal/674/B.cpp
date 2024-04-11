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

const int N = 5000;

int n, k;
int a, b, c, d;
int used[N];
int ans[N];
int ptr = 1;

int use() {
  while (used[ptr]) {
    ptr++;
  }

  used[ptr] = 1;
  return ptr;
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

  cin >> n >> k;
  cin >> a >> b >> c >> d;

  if (k < n + 1 || n == 4) {
    cout << "-1\n";
    return 0;
  }

  ans[0] = a;
  ans[n - 1] = b;
  ans[1] = c;
  ans[n - 2] = d;
  used[a] = 1;
  used[b] = 1;
  used[c] = 1;
  used[d] = 1;

  for (int i = 2; i < n - 2; i++) {
    ans[i] = use();
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";

  cout << ans[1] << " " << ans[0] << " ";
  for (int i = 2; i < n - 2; i++) {
    cout << ans[i] << " ";
  }
  cout << ans[n - 1] << " " << ans[n - 2] << "\n";

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}