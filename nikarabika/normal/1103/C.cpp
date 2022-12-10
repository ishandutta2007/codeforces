//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 5e5 + 10;
int leaf[maxn],
	mark[maxn],
	par[maxn],
	h[maxn],
	n, k, m;
vector<int> adj[maxn];

void dfs(int u, int p = -1) {
par[u] = p;
	if (h[u] >= (n + k - 1) / k - 1) {
		cout << "PATH" << '\n'; 
		cout << h[u] + 1 << '\n';
		while (u != 0) {
			cout << u + 1 << ' ';
			u = par[u];
		}
		cout << 1 << '\n';
		exit(0);
	}
	mark[u] = true;
	leaf[u] = true;
	for (auto v : adj[u])
		if (!mark[v]) {
			h[v] = h[u] + 1;
			dfs(v, u);
			leaf[u] = false;
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	dfs(0);
	cout << "CYCLES\n";
	int c = k;
	for (int i = 0; i < n and c; i++) if (leaf[i]) {
		int x[3] = {-1, -1, -1};
		c--;
		for (auto u : adj[i])
			if (u != par[i]) {
				for (int j = 0; j < 2; j++)
					if (x[j] == -1) {
						x[j] = u;
						break;
					}
			}
		bool haha = false;
		for (int j = 0; j < 2 and !haha; j++) {
			if ((h[i] - h[x[j]]) % 3 != 2) {
				cout << h[i] - h[x[j]] + 1 << '\n';
				int t = i;
				while (t != x[j]) {
					cout << t + 1 << ' ';
					t = par[t];
				}
				cout << x[j] + 1 << '\n';
				haha = true;
			}
		}
		if (!haha) {
			if (h[x[0]] > h[x[1]])
				swap(x[0], x[1]);
			cout << h[x[1]] - h[x[0]] + 2 << '\n';
			int t = x[1];
			while (t != x[0]) {
				cout << t + 1 << ' ';
				t = par[t];
			}
			cout << x[0] + 1 << ' '
				<< i + 1 << '\n';
		}
	}
	return 0;
}