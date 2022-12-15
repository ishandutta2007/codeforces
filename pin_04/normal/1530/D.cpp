#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {
	if (a > b) {a = b; return true;} return false;
}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {
	if (a < b) {a = b; return true;} return false;
}
const int N = 2e5 + 5; 
const int oo = 1e9;

vector <int> adj[N];
vector <int> s;

int par[N];
int p[N];
int n;

bool vis[N];
bool inq[N];

void dfs(int u) {

	vis[u] = inq[u] = true;
	s.push_back(u);

	int v = p[u];
	if (inq[v]) {
		int w = 0;
		do {
			w = s.back();
			s.pop_back();
			inq[w] = false;
			if (w != v) 
				par[w] = s.back();
			else 
				par[v] = u;
		} while (w != v);
	} else if (!vis[v]) 
		dfs(v);
	
	if (s.size() && s.back() == u) {
		s.pop_back();
		inq[u] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		int ans = 0;

		for (int i = 1; i <= n; i++)
			vis[i] = false;

		for (int i = 1; i <= n; i++) {
			cin >> p[i];
			if (!vis[p[i]])
				ans++, vis[p[i]] = true;
		}
	
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
			vis[i] = inq[i] = false;
			par[i] = 0;
		}

		for (int i = 1; i <= n; i++)
			adj[p[i]].push_back(i);

		for (int i = 1; i <= n; i++)
			if (!vis[i])
				dfs(i);
			
		queue <int> q;
		
		for (int i = 1; i <= n; i++) 
			if (par[i]) 
				q.push(i);

		while (q.size()) {
			int u = q.front(); q.pop();

			for (int v : adj[u]) if (!par[v]) {
				p[par[u]] = v;
				p[v] = u;
				par[v] = par[u];
				par[u] = v;
				q.push(v);
			}
		}

		cout << ans << "\n";
		for (int i = 1; i <= n; i++)
			cout << p[i] << " \n"[i == n];
	}
	return 0;
}