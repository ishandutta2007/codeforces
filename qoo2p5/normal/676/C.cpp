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

int n, k;
string s;
int p[N];

int get(int l, int r) {
  int res = p[r];
  if (l) res -= p[l - 1];
  return res;
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
  cin >> s;
  
  p[0] = s[0] == 'a' ? 0 : 1;
  for (int i = 1; i < n; i++) {
    p[i] = p[i - 1] + (s[i] == 'a' ? 0 : 1);
  }
  
  int ans = 0;
  
  int j = 0;
  for (int i = 0; i < n; i++) {
    while (min(get(j, i), i - j + 1 - get(j, i)) > k) j++;
    ans = max(ans, i - j + 1);
  }
  
  cout << ans << "\n";

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}