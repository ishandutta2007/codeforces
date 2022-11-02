#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e18 + 7;
const int max_n = 1e3 + 5;

int xr[]{-1, 1, 0, 0}, yr[]{0, 0, -1, 1};
int n, m;


bool check(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

void solve() {
	int t;
	cin >> n >> m >> t;

	string a[n];
	for(int i = 0;i < n;i++) cin >> a[i];

	vector<vector<int>> dist(n, vector<int>(m, inf));
	
	deque<pii> bfs;
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			bool good = false;
			for(int it = 0;it < 4;it++) {
				int to_x = i + xr[it];
				int to_y = j + yr[it];
				if (check(to_x, to_y) && a[to_x][to_y] == a[i][j]) good = true;
			}
			if (good) {
				dist[i][j] = 0;
				bfs.emplace_back(i, j);
			}
		}	
	}

	while(!bfs.empty()) {
		pii v = bfs.front();
		bfs.pop_front();

		for(int it = 0;it < 4;it++) {
			int x = v.first + xr[it];
			int y = v.second + yr[it];
			if (check(x, y) && dist[x][y] == inf) {
				dist[x][y] = dist[v.first][v.second] + 1;
				bfs.emplace_back(x, y);
			}
		}
	}

	while(t--) {
		int x, y, p;
		cin >> x >> y >> p;
		x--; y--;

		if (p < dist[x][y]) cout << a[x][y] << endl;
		else{
			p -= dist[x][y];
			int v = a[x][y] - '0';
			if (p % 2 == 0) cout << v << endl;
			else cout << 1 - v << endl;
		}
	}
}



signed main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
  	#endif
 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}