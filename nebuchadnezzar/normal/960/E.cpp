#include "bits/stdc++.h"
#define ff first
#define ss second
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }

const int MOD = 1e9 + 7;
void add(int& a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int sum(int a, int b) {
	add(a, b);
	return a;
}

int mult(int a, int b) {
	unsigned long long x = (ll) a * b;
	    unsigned int xh = x >> 32, xl = x, q, r;
	#ifdef __GNUC__
	    asm(
	        "divl %4; \n\t"
	        : "=a" (q), "=d" (r)
	        : "d" (xh), "a" (xl), "r" (MOD)
	    );
	#else
	    __asm {
	        mov edx, dword ptr[xh];
	        mov eax, dword ptr[xl];
	        div dword ptr[mod];
	        mov dword ptr[q], eax;
	        mov dword ptr[r], edx;
	    };
	#endif
	    return r;
}

const int MAXN = 2e5 + 5;

vector<int> graph[MAXN];
vector<int> arr;

vector<int> now;
bool used[MAXN];
int sz[MAXN];
int largest[MAXN];

int calc_szs(int v, int p) {
	sz[v] = 1;
	largest[v] = 0;
	now.push_back(v);
	for (int to : graph[v]) {
		if (!used[to] && to != p) {
			calc_szs(to, v);
			sz[v] += sz[to];
			largest[v] = max(largest[v], sz[to]);
		}
	}
	return 0;
}

int ans = 0;
int rt;
int cont, cnt, ncont, ncnt;
int qq[2], qcnt[2], nqq[2], nqcnt[2];

int dfs(int v, int p, int csum, int l) {
	if (l % 2 == 0) {
		add(csum, arr[v]);
		add(ans, sum(cont, mult(sum(csum, MOD - rt), cnt)));
		add(ans, sum(qq[0], mult(sum(csum, MOD - rt), qcnt[0])));
		add(ans, sum(qq[1], mult(sum(MOD - csum, rt), qcnt[1])));
		add(nqq[0], csum);
		add(nqcnt[0], 1);
		add(ncont, csum);
		add(ncnt, 1);
	} else {
		add(csum, MOD - arr[v]);
		add(ans, sum(MOD - cont, mult(sum(MOD - csum, rt), cnt)));
		add(ans, sum(qq[0], mult(sum(csum, MOD - rt), qcnt[0])));
		add(ans, sum(qq[1], mult(sum(MOD - csum, rt), qcnt[1])));
		add(nqq[1], MOD - csum);
		add(nqcnt[1], 1);
		add(ncont, csum);
		add(ncnt, 1);
	}
	for (int to : graph[v]) {
		if (!used[to] && to != p) {
			dfs(to, v, csum, l + 1);
		}
	}
	return 0;
}

int rec(int v) {
	now.clear();
	calc_szs(v, v);
	int best = INF;
	for (int u : now) {
		largest[u] = max(largest[u], szof(now) - sz[u]);
		if (largest[u] < best) {
			best = largest[u];
			v = u;
		}
	}

	used[v] = true;

	cnt = 1;
	cont = 0;
	rt = arr[v];
	add(ans, rt);
	qq[0] = 0;
	qq[1] = 0;
	qcnt[0] = 0;
	qcnt[1] = 1;
	for (int to : graph[v]) {
		if (!used[to]) {
			//cerr << cont << " " << cnt << endl;
			ncont = 0;
			ncnt = 0;
			//nqq = {0, 0};
			nqq[0] = 0;
			nqq[1] = 0;
			//nqcnt = {0, 0};
			nqcnt[0] = 0;
			nqcnt[1] = 0;
			dfs(to, v, 0, 0);
			add(cont, ncont);
			add(cnt, ncnt);
			add(qq[0], nqq[0]);
			add(qq[1], nqq[1]);
			add(qcnt[0], nqcnt[0]);
			add(qcnt[1], nqcnt[1]);
		}
	}

	for (int to : graph[v]) {
		if (!used[to]) {
			rec(to);
		}
	}

	return 0;
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		num %= MOD;
		if (num < 0) {
			num += MOD;
		}
		arr.push_back(num);
	}

	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	rec(0);

	cout << ans << "\n";
}


int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);
	cerr << fixed << setprecision(15);
	cout << fixed << setprecision(15);
	ios::sync_with_stdio(false);

	int tests = 1;
	// cin >> tests;
	for (int it = 1; it <= tests; ++it) {
		solve();
	}
	
	#ifdef LOCAL
		cerr << "time: " << clock() << " ms\n";
	#endif
	return 0;
}