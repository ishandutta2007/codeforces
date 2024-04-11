#include <iostream>

using namespace std;

int n, m;
string s[55];
int c;

void dfs(int y, int x) {
	if (y < 1 || x < 1 || y > n || x > m) return;
	if (s[y][x] != '.' && s[y][x] != 'G') return;
	if (s[y][x] == 'G') c--;
	s[y][x] = '#';
	dfs(y-1,x);
	dfs(y+1,x);
	dfs(y,x-1);
	dfs(y,x+1);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> s[i];
			s[i] = "#"+s[i];
		}
		c = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (s[i][j] == 'G') c++;
				if (s[i][j] != '.' && s[i][j] != 'G') continue;
				if (i-1 >= 1 && s[i-1][j] == 'B') s[i][j] = '#';
				if (i+1 <= n && s[i+1][j] == 'B') s[i][j] = '#';
				if (j-1 >= 1 && s[i][j-1] == 'B') s[i][j] = '#';
				if (j+1 <= m && s[i][j+1] == 'B') s[i][j] = '#';
			}
		}
		dfs(n,m);
		if (c == 0) cout << "YES\n";
		else cout << "NO\n";
	}
}