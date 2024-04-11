#include <bits/stdc++.h>
        
using namespace std;
        
        
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
        
//#define GCC optimize("O3, Ofast")
//#define GCC optimize("unroll-loops")
#define aidar asadulin
         
#define int long long
#define ull long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double
        
const int inf = 5e9 + 7;
const int max_n = 1e6;

int n, col[max_n];
vector<pii> gr[max_n];

void solve() {
	int m;
	cin >> n >> m;
	for(int i = 0;i < m;i++) {
		int v1, v2, c;
		cin >> v1 >> v2 >> c;
		gr[--v2].emplace_back(--v1, c);
	}
	fill(col, col + max_n, -1);

	vector<int> dist(n, inf);
	dist[n - 1] = 0;

	deque<int> bfs{n - 1};

	while(sz(bfs)) {
		int v = bfs.front();
		bfs.pop_front();

		for(pii to : gr[v]) {
			if (dist[to.fi] <= dist[v] + 1) continue;
			if (col[to.fi] != to.se) {
				if (col[to.fi] == -1) col[to.fi] = 1 - to.se;
			}else {
				bfs.emplace_back(to.fi);
				dist[to.fi] = dist[v] + 1;
			}
		}
	}

	cout << (dist[0] == inf ? -1 : dist[0]) << endl;
	for(int i = 0;i < n;i++) {
		cout << (col[i] == 1 ? 1 : 0);
	}
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}