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
const int MOD = 1e9 + 7;

#define TASKNAME ""

const int N = 1e5 + 123;
const int M = 2 * sqrt(N);
const int K = 26;

ll fact[N];
ll rev_fact[N];
ll p25[N];

ll power(ll a, ll p) {
  if (p == 0) {
    return 1;
  }
  
  if (p & 1) {
    return (power(a, p - 1) * a) % MOD;
  }
  
  ll tmp = power(a, p / 2);
  return (tmp * tmp) % MOD;
}

ll cnk(int n, int k) {
  return (((fact[n] * rev_fact[k]) % MOD) * rev_fact[n - k]) % MOD;
}

int ans[M][N];

vector<int> lens;

int calc(int len, int n) {
  if (n < len) {
    return 0;
  }
  int j = lower_bound(lens.begin(), lens.end(), len) - lens.begin();
  return ans[j][n];
}

int main() {
	/*ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);*/
	float tbegin = clock();
	srand(time(nullptr));

#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#else
	if (TASKNAME != "") {
		freopen(TASKNAME ".in", "r", stdin);
		freopen(TASKNAME ".out", "w", stdout);
	}
#endif

  p25[0] = 1;
  fact[0] = 1;
  rev_fact[0] = power(fact[0], MOD - 2);
  for (int i = 1; i < N; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
    rev_fact[i] = power(fact[i], MOD - 2);
    p25[i] = (p25[i - 1] * (K - 1)) % MOD;
  }

  char s[N];

  int m;
  scanf("%d", &m);
  vector<pair<int, int>> queries;
  int cur_len = 0;
  {
    scanf("%s", s);
    cur_len = strlen(s);
    lens.pb(cur_len);
  }
  
  for (int i = 0; i < m; i++) {
    int t;
    scanf("%d", &t);
    
    if (t == 1) {
      scanf("%s", s);
      cur_len = strlen(s);
      lens.pb(cur_len);
    } else {
      int n;
      scanf("%d", &n);
      queries.pb(mp(cur_len, n));
    }
  }
  
  sort(lens.begin(), lens.end());
  lens.resize(unique(lens.begin(), lens.end()) - lens.begin());
    
  for (int j = 0; j < sz(lens); j++) {
    int len = lens[j];
    ans[j][len] = 1;
    for (int i = len + 1; i < N; i++) {
      ans[j][i] = (ans[j][i - 1] * 1LL * K + p25[i - len] * cnk(i - 1, len - 1)) % MOD;
    }
  }

  for (auto &q : queries) {
    printf("%d\n", calc(q.first, q.second));
  }

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}