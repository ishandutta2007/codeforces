#define FNAME ""

#undef __STRICT_ANSI__

#include <bits/stdc++.h> 

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (int)(n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (int)(b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end()

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
	#define U64 "%I64u"
#else
	#define I64 "%lld"
	#define U64 "%llu"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ld;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;


const int N = 3e5 + 100;
const int INF = 1e9 + 7;

vector<int> g[N];
int d[N], p[N], deg[N], used[N];
set<int> adj[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	forn(i, m) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		g[v].pb(u);
		g[u].pb(v);
		adj[u].insert(v);
		adj[v].insert(u);
		deg[v]++;
		deg[u]++;
	}
	forn(i, N)
		p[i] = -1, d[i] = INF;
	queue<int> q;
	q.push(0);
	d[0] = 0;
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for(int to : g[v]) {
			if (d[to] > d[v] + 1) {
				d[to] = d[v] + 1;
				p[to] = v;
				q.push(to);
			}
		}
	}
	if (d[n - 1] <= 4) {
		cout << d[n - 1] << '\n';
		vector<int> path;
		path.pb(n - 1);
		int now = n - 1;
		while(p[now] != -1) {
			now = p[now];
			path.pb(now);
		}
		reverse(all(path));
		for(int v : path) cout << v + 1 << " ";
		cout << '\n';
		return 0;
	}
	for(int v : g[0]) {
		for(int to : g[v]) {
			if (!to) continue;
			if (!adj[0].count(to)) {
				cout << 4 << '\n';
				cout << 1 << " " << v + 1 << " " << to + 1 << " " << 1 << " " << n << '\n';
				return 0;
			}
		}
	}
	for(int v: g[0]) {
		if (used[v]) continue;
		for(int to: g[v]) {
			if (!to) continue;
			assert(!used[to]);
			used[to] = 1;
			for (int to2: g[to]) {
				if (to2 == v || to2 == 0) continue;
				if (!adj[v].count(to2)) {
					cout << 5 << '\n';
					cout << 1 << " " << v + 1 << " " << to + 1 << " " << to2 + 1 << " " << v + 1 << " " << n << '\n';
					return 0;
				}
			}
			if (deg[to] != deg[v]) {
				for (int to2: g[v]) {
					if (to2 == to || to2 == 0) continue;
					if (!adj[to].count(to2)) {
						cout << 5 << '\n';
						cout << 1 << " " << to + 1 << " " << v + 1 << " " << to2 + 1 << " " << to + 1 << " " << n << '\n';
						return 0;
					}
				}
			}
		}
	}
	cout << -1 << '\n';
	return 0;
}