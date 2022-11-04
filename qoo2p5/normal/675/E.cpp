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

const ll INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-9;
const ld PI = 3.141592653589;
const ll MOD = 1e9 + 7;

#define TASKNAME ""

const int N = 1e5 + 123;
const int M = 20;

int n;
int a[N];
ll dp[N];
pair<int, int> sp[M][N];
int log2z[N];

void build() {
  for (int i = 2; i < N; i++) {
    log2z[i] = log2z[i / 2] + 1;
  }
  
  for (int i = 0; i < n; i++) {
    sp[0][i] = {a[i], i};
  }
  
  for (int j = 1; j < M; j++) {
    for (int i = 0; i + (1 << j) - 1 < n; i++) {
      sp[j][i] = max(sp[j - 1][i], sp[j - 1][i + (1 << (j - 1))]);
    }
  }
}

pair<int, int> query(int l, int r) {
  int k = log2z[r - l + 1];
  return max(sp[k][l], sp[k][r - (1 << k) + 1]);
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

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  
  build();
  
  ll ans = 0;
  dp[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--) {
    pair<int, int> t = query(i + 1, a[i]);
    dp[i] = dp[t.second] - (a[i] - t.second) + (n - 1 - i);
    ans += dp[i];
  }
  
  cout << ans << "\n";

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}