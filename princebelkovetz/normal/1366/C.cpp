#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define endl "\n"
#define int long long
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int mxN = 1e5 + 7, inf = 1e9 + 7;
int fastpow(int a, int b) {
	if (!b) return 1ll;
	if (b % 2 == 1) return fastpow(a, b - 1) * a;
	int t = fastpow(a, b / 2);
	return t * t;
}
signed main() {
	int t; cin >> t;
	while (t --> 0) {
		int n, m, ans = 0; cin >> n >> m;
		vector <vector <int>> matrix(n, vector <int>(m));
		vector <vector <bool>> used(n, vector <bool>(m));
		for (auto& x : matrix) for (auto& y : x) cin >> y;
		vector <pair <int, int>> curleft, curright, prevleft, prevright;
		prevleft.push_back({ 0, 0 }); prevright.push_back({ n - 1, m - 1 });
		if (matrix[0][0] != matrix[n - 1][m - 1]) ++ans;
		used[0][0] = true; used[n - 1][m - 1] = true;
		while (prevleft.size() and prevright.size()) {
			curleft.clear(); curright.clear();
			int cou1 = 0;
			for (auto x : prevleft) {
				if (x.first < n - 1 and !used[x.first + 1][x.second]) {
					curleft.push_back({ x.first + 1, x.second });
					used[x.first + 1][x.second] = true;
					if (matrix[x.first + 1][x.second]) ++cou1;
				} 
				if (x.second < m - 1 and !used[x.first][x.second + 1]) {
					curleft.push_back({ x.first, x.second + 1 });
					used[x.first][x.second + 1] = true;
					if (matrix[x.first][x.second + 1]) ++cou1;
				}
			}
			for (auto x : prevright) {
				if (x.first > 0 and !used[x.first - 1][x.second]) {
					curright.push_back({ x.first - 1, x.second });
					used[x.first - 1][x.second] = true;
					if (matrix[x.first - 1][x.second]) ++cou1;
				}
				if (x.second > 0 and !used[x.first][x.second - 1]) {
					curright.push_back({ x.first, x.second - 1 });
					used[x.first][x.second - 1] = true;
					if (matrix[x.first][x.second - 1]) ++cou1;
				}
			}
			prevleft = curleft; prevright = curright;
			if (prevleft.size() and prevright.size())ans += min(cou1, prevleft.size() + prevright.size() - cou1);
		}
		cout << ans << endl;
	}


}