#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
bool dfs(int v, map <int, int> &m) {
	if (v == 0) return 0;
	if (m[v]) {
		m[v]--;
		return true;
	}
	return (dfs(v / 2, m)) && dfs(v / 2, m);
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		map <int, int> m;
		while (n--) {
			int x; cin >> x;
			m[x]++;
		}
		for (int i = 1; i <= 2048; i *= 2)
			m[i] += 0;
		if (dfs(2048, m)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}