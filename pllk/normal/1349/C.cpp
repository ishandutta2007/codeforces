#include <iostream>
#include <vector>

using namespace std;

#define INF 2000000000000000000LL

typedef long long ll;

int n, m, t;
string s[1111];
ll d[1111][1111];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = "#"+s[i];
	}
	vector<pair<int,int>> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int x = 0;
			if (i-1 >= 1 && s[i][j] == s[i-1][j]) x = 1;
			if (i+1 <= n && s[i][j] == s[i+1][j]) x = 1;
			if (j-1 >= 1 && s[i][j] == s[i][j-1]) x = 1;
			if (j+1 <= m && s[i][j] == s[i][j+1]) x = 1;
			if (x) {
				d[i][j] = 0;
				q.push_back({i,j});
			} else {
				d[i][j] = INF;
			}
		}
	}
	for (int i = 0; i < q.size(); i++) {
		int y = q[i].first;
		int x = q[i].second;
		int u[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
		for (int j = 0; j < 4; j++) {
			int uy = y+u[j][0];
			int ux = x+u[j][1];
			if (uy >= 1 && uy <= n && ux >= 1 && ux <= m) {
				if (d[uy][ux] > d[y][x]+1) {
					d[uy][ux] = d[y][x]+1;
					q.push_back({uy,ux});
				}
			}
		}
	}
	for (int i = 1; i <= t; i++) {
		int y, x;
		ll p;
		cin >> y >> x >> p;
		int r = s[y][x] == '1';
		if (d[y][x] >= p) {
			cout << r << "\n";
		} else {
			if (d[y][x]%2 != p%2) r = 1-r;
			cout << r << "\n";
		}
	}
}