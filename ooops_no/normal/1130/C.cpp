/*
_NUUUUUUU_
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<iterator>
using namespace std;

#define pb push_back
typedef long long ll;
const int N = 51;
int n;
int g[N][N];
bool used[N][N];
vector<pair<int,int>> ans;

bool check(int v) {
	return v >= 1 && v <= n;
}
void dfs(int i, int j) {
	used[i][j] = true;
	if (check(i - 1)) {
		if (!used[i - 1][j] && g[i - 1][j] == 0) {
			dfs(i - 1, j);
		}
	}
	if (check(i + 1)) {
		if (!used[i + 1][j] && g[i + 1][j] == 0) {
			dfs(i + 1, j);
		}
	}
	if (check(j - 1)) {
		if (!used[i][j - 1] && g[i][j - 1] == 0) {
			dfs(i, j - 1);
		}
	}
	if (check(j + 1)) {
		if (!used[i][j + 1] && g[i][j + 1] == 0) {
			dfs(i, j + 1);
		}
	}
}

void dfs1(int i, int j) {
	ans.push_back(make_pair(i, j));
	used[i][j] = true;
	if (check(i - 1)) {
		if (!used[i - 1][j] && g[i - 1][j] == 0) {
			dfs1(i - 1, j);
		}
	}
	if (check(i + 1)) {
		if (!used[i + 1][j] && g[i + 1][j] == 0) {
			dfs1(i + 1, j);
		}
	}
	if (check(j - 1)) {
		if (!used[i][j - 1] && g[i][j - 1] == 0) {
			dfs1(i, j - 1);
		}
	}
	if (check(j + 1)) {
		if (!used[i][j + 1] && g[i][j + 1] == 0) {
			dfs1(i, j + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char a;
			cin >> a;
			g[i][j] = a - '0';
		}
	}
	dfs(a, b);
	cout << endl;
	int mns = 1e8;
	if (used[c][d]) {
		cout << 0;
		return 0;
	}
	else {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				used[i][j] = 0;
			}
		}
		dfs1(a, b);
		vector<pair<int,int>> ans1;
		for (auto to : ans) {
			ans1.pb(to);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				used[i][j] = 0;
			}
		}
		ans.clear();
		dfs1(c, d);
		for (auto to : ans1) {
			for (auto to1 : ans) {
				mns = min(mns, (to.first - to1.first) * (to.first - to1.first) + (to.second - to1.second) * (to.second - to1.second));
			}
		}
	}
	cout << mns;
}