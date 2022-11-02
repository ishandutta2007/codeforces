#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define pii pair<int, int>
//#define sz(a) ((int)a.size())  
typedef long double ld;

const int inf = 1e9 + 7;
const int max_n = 1e3 + 43;

int xr[]{0, -1, 0, 1}, yr[]{-1, 0, 1, 0};
int n, m;
string s[max_n];

bool check(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}


bool used[max_n][max_n];

void dfs(int x, int y) {
	if (used[x][y]) return;
	used[x][y] = true;
	for(int q = 0;q < 4;q++) {
		int to_x = x + xr[q];
		int to_y = y + yr[q];
		if (check(to_x, to_y) && s[to_x][to_y] == '#') dfs(to_x, to_y);
	}
}



void solve() {
	cin >> n >> m;
	for(int i = 0;i < n;i++) cin >> s[i];

	int cnt = 0;
	vector<bool> bad1(n, true), bad2(m, true);

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			if (s[i][j] == '#') {

				if (j != 0 && !bad1[i] && s[i][j - 1] == '.') cnt = -inf;
				if (i != 0 && !bad2[j] && s[i - 1][j] == '.') cnt = -inf;

				bad1[i] = false;
				bad2[j] = false;

				if (!used[i][j]) {
					cnt++;
					dfs(i, j);
				}
			}
		}
	}

	bool q1 = false, q2 = false;
	for(int i = 0;i < n;i++) if (bad1[i]) q1 = true;
	for(bool i : bad2) q2 |= i;

	if ((q1 ^ q2) || cnt < 0) cout << -1;
	else cout << cnt;

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