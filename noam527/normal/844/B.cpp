#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
typedef long long ll;
typedef long double ldb;
using namespace std;

int n, m, t[50][50];
ll ans = 0;

int main() {
	fast;
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> t[i][j];

	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < m; j++)
			if (t[i][j] == 1) cnt++;
		ans += (1LL << cnt) + (1LL << (m - cnt)) - 2;
	}
	for (int j = 0; j < m; j++) {
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (t[i][j] == 1) cnt++;
		ans += (1LL << cnt) + (1LL << (n - cnt)) - 2;
	}
	cout << ans - (n * m) << endl;
}