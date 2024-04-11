#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e9 + 7;
const int max_n = 52;

int xdir[] = {-1, 1, 0, 0};
int ydir[] = {0, 0, -1, 1};

int n, m;
int col[max_n][max_n];
string a[max_n];

bool check(int x, int y) {
	return x < n && x >= 0 && y < m && y >= 0;
}

void dfs(int x, int y) {
	if (col[x][y] != 0) return;
	col[x][y] = 1;

	for(int i = 0;i < 4;i++) {
		int to_x = x + xdir[i];
		int to_y = y + ydir[i];
		if (!check(to_x, to_y)) continue;
		dfs(to_x, to_y);
	}
}

void solve() {
	cin >> n >> m;
	for(int i = 0;i < n;i++) {
		cin >> a[i];
	}

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) col[i][j] = 0;
	}


	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			if (a[i][j] == '#') col[i][j] = 2;
			if (a[i][j] == 'B') {
				for(int q = 0;q < 4;q++) {
					int to_x = i + xdir[q];
					int to_y = j + ydir[q];

					if (check(to_x, to_y)) col[to_x][to_y] = 2;
				}
			}
		}
	}

	bool bad = false;
		
	dfs(n - 1, m - 1);

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) if (a[i][j] == 'G' && col[i][j] != 1) bad = true;
	}

	if (bad) cout << "No" << endl;
	else cout << "Yes" << endl;
}




signed main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
  	#endif
 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);


    int t;
    cin >> t;
    while(t--) {
    	solve();
    }
}