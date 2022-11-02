#include <bits/stdc++.h>
#define long long long
#define pii pair<int, int>
 
using namespace std;
const int inf = 1e9 + 7;
const int max_n = 1001;
int n;

int xr[4]{-1, 1, 0, 0};
int yr[4]{0, 0, -1, 1};
int last_x[max_n][max_n], last_y[max_n][max_n];

bool ans = true;
int num[max_n][max_n];


bool check(int x, int y) {
	return (x >= 0 && y >= 0 && x < n && y < n);
}

void dfs_minus(int x, int y) {
	if (num[x][y] != -1) return;
	for(int i = 0;i < 4;i++) {
		int to_x = x + xr[i];
		int to_y = y + yr[i];
		if (check(to_x, to_y) && last_x[to_x][to_y] == -1) {
			num[x][y] = i;
			dfs_minus(to_x, to_y);
		}
	}
}

void dfs1(int sx, int sy, int x, int y) {
	//if (num[x][y] != -1) continue;
	for(int i = 0;i < 4;i++) {
		int to_x = x + xr[i];
		int to_y = y + yr[i];
		if (check(to_x, to_y) && last_x[to_x][to_y] == sx && last_y[to_x][to_y] == sy && num[to_x][to_y] == -1) {
			num[to_x][to_y] = (i ^ 1);
			dfs1(sx, sy, to_x, to_y);
		}
	}
}

void dfs(int x, int y) {
	if (last_x[x][y] == -1) dfs_minus(x, y);
	else{
		num[x][y] = 4;
		dfs1(x, y, x, y);
	}
}

void solve() {
	cin >> n;
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			cin >> last_x[i][j] >> last_y[i][j];
			if (last_x[i][j] != -1) {
				last_x[i][j]--; last_y[i][j]--;
			}
			num[i][j] = -1;
		}
	}

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			if (last_x[i][j] == i && last_y[i][j] == j) dfs(i, j);
			if (last_x[i][j] == -1) dfs(i, j);
		}
	}

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			if (num[i][j] == -1) ans = false;
		}
	}
	if (!ans) cout << "INVALID";
	else{
		cout << "VALID" << '\n';

		for(int i = 0;i < n;i++) {
			for(int j = 0;j < n;j++) {
				if (num[i][j] == 4) cout << "X";
				if (num[i][j] == 0) cout << "U";
				if (num[i][j] == 1) cout << "D";
				if (num[i][j] == 2) cout << "L";
				if (num[i][j] == 3) cout << "R";
			}
			cout << '\n';
		}
	}
}






int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	solve();
}