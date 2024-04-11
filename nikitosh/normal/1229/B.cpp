#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; (i) < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define forba(i, a, b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end() 

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FNAME ""

const int MAX_N = 1e5 + 5, MOD = 1e9 + 7;

int ans = 0;
vector<int> g[MAX_N];
ll x[MAX_N];

void add(vector<pair<ll, int>>& stack, ll val, int cnt) {
	stack.pb(mp(val, cnt));
	int k = sz(stack);
	if (k > 1 && stack[k - 1].fs == stack[k - 2].fs) {
		stack[k - 2].sc += stack[k - 1].sc;
		stack.pop_back();
	}
}

void dfs(int v, int p, vector<pair<ll, int>> stack) {
	vector<pair<ll, int>> newStack;
	for (const auto &np : stack) {
		ll k = __gcd(x[v], np.fs);
		ans = (ans + k * np.sc) % MOD;
		add(newStack, k, np.sc);
	}
	add(newStack, x[v], 1);
	ans = (ans + x[v]) % MOD;
	for (int u : g[v])
		if (u != p)
			dfs(u, v, newStack);
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	scanf("%d", &n);
	forn (i, n)
		cin >> x[i];
	forn (i, n - 1) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--, u--;
		g[v].pb(u);
		g[u].pb(v);
	}
	dfs(0, -1, {});
	cout << ans;

	return 0;
}