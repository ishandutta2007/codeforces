#include <bits/stdc++.h>
//#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e9 + 7;
map<char, int> dir;
int xr[]{0, -1, 1, 0};
int yr[]{1, 0, 0, -1};

int n, m;
vector<string> s;
vector<string> c;

vector<vector<bool>> used;
vector<vector<int>> dist1;

vector<vector<int>> dist;

bool all[1000005], black[1000005];

int res1 = 0, res2 = 0;
int sz = 0;

void dfs(int x, int y) {

	//cout << x << " " << y << '\n';

	for(int q = 0;q < 4;q++) {
		int to_x = xr[q] + x;
		int to_y = yr[q] + y;

		if (to_x < 0 || to_x >= n || to_y < 0 || to_y >= m) continue;
		/*if (to_x == 1 && to_y == 2) {
			cout << dir[s[to_x][to_y]] << " " << q << "asdhlkgahkdjnva;" << '\n';
		}*/

		if (dir[s[to_x][to_y]] != 3 - q) continue;

		if (dist[to_x][to_y] == -1) {
			dist[to_x][to_y] = (dist[x][y] + 1) % sz;
			dfs(to_x, to_y);
		}

	}

	all[dist[x][y]] = true;
	if (c[x][y] == '0') black[dist[x][y]] = true;
}

bool check_dfs(int x, int y) {
	//cout << x << " " << y << endl;
	used[x][y] = true;

	int to_x = xr[dir[s[x][y]]] + x;
	int to_y = yr[dir[s[x][y]]] + y;

	if (used[to_x][to_y]) {
		dist[to_x][to_y] = 0;
		sz = dist1[x][y] - dist1[to_x][to_y] + 1;

		//cout << x << " " << y << " " << to_x << " " << to_y << " " << size << endl;
		dfs(to_x, to_y);
		return true;
	}


	dist1[to_x][to_y] = dist1[x][y] + 1;



	return check_dfs(to_x, to_y);
}

void scan() {
	s.clear();
	c.clear();
	used.clear();
	dist.clear();
	dist1.clear();

	cin >> n >> m;

	s.resize(n);
	c.resize(n);
	used.resize(n, vector<bool>(m));
	dist.resize(n, vector<int>(m, -1));
	dist1.resize(n, vector<int>(m, 0));

	for(int i = 0;i < n;i++) cin >> c[i];
	for(int i = 0;i < n;i++) cin >> s[i];
}

void solve() {
	scan();
	res1 = 0; res2 = 0;

	dir['U'] = 1;
	dir['D'] = 2;
	dir['L'] = 3;
	dir['R'] = 0;

	//cout << "scan" << endl;

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			if (dist[i][j] == -1)  {
				//cout << i << " " << j << " qqq" << endl;
				check_dfs(i, j);

				for(int q = 0;q <= sz;q++) {
					if (all[q]) res1++;
					if (black[q]) res2++;
					all[q] = false;
					black[q] = false;
				}


				//res1 += all.size();
				//res2 += black.size();
				//cout << "all " << all.size() << " black" << " " << black.size() << '\n';
				//cout << i << " " << j << "  qqq" << endl;
				//all.clear();
				//black.clear();
			}
		}
	}

	cout << res1 << " " << res2 << '\n';
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