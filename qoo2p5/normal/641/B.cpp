#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <map>
#include <queue>
#pragma comment(linker, "/stack:111")
#define ll long long
#define cs(x) (int)x.size()
#define mp make_pair
#define ld long double
using namespace std;

const int N = 500000;
const ll INF = 1e12;
const ll mod = 10;

int ans[100][100];
pair<int, int> arr[100][100];

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("kthpath.in", "r", stdin);
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			arr[i][j] = mp(i, j);
	}
	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int x;
			cin >> x;
			x--;
			auto first = arr[x][0];
			for (int j = 0; j < m - 1; j++)
				arr[x][j] = arr[x][j + 1];
			arr[x][m - 1] = first;
		}
		if (t == 2) {
			int y;
			cin >> y;
			y--;
			auto first = arr[0][y];
			for (int j = 0; j < n - 1; j++)
				arr[j][y] = arr[j + 1][y];
			arr[n - 1][y] = first;
		}
		if (t == 3) {
			int a, b, v;
			cin >> a >> b >> v;
			a--;
			b--;
			ans[arr[a][b].first][arr[a][b].second] = v;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}
	return 0;
}