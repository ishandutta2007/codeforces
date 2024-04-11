#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#include <fstream>
#include <random>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, m, a[500][500], cnt[500];
vector<int> vis;
string ans;

// ch = 0 -> ans[v] = 'a'. ch = 2 -> ans[v] = 'c'
void dfs(int v, int ch) {
	if (vis[v]) {
//		cout << "checking " << v << " ch " << ch << endl;
		if (ans[v] != char(ch + 'a')) {
			cout << "No" << endl;
			exit(0);
		}
		return;
	}
//	cout << "v " << v << " ch " << ch << endl;
	vis[v] = 1;
	ans[v] = char(ch + 'a');
	for (int i = 0; i < n; i++) {
		if (a[v][i])
			dfs(i, 2 ^ ch);
	}
}

int main() {
	fast;
	cin >> n >> m;
	vis.resize(n, 0);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) a[i][j] = 1;
	for (int i = 0; i < n; i++) a[i][i] = 0, cnt[i] = n - 1;

	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		--u, --v;
		a[u][v] = a[v][u] = 0;
		cnt[u]--, cnt[v]--;
	}

//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) cout << a[i][j] << " "; cout << endl;
//	}

	ans = string(n, 'b');
	for (int i = 0; i < n; i++) {
		if (!vis[i] && cnt[i]) dfs(i, 0);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i][j]) {
				if (abs(ans[j] - ans[i]) != 2) finish("No");
			}
			else {
				if (abs(ans[j] - ans[i]) == 2) finish("No");
			}
		}
	}
	cout << "Yes" << endl;
	finish(ans);
}