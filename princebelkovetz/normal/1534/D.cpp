#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>

using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#pragma GCC optimize("O3")
const int mod = 1e9 + 7;
int n;
vector <int> query(int x) {
	cout << "? " << x << endl;
	vector <int> ans(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> ans[i];
	return ans;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector <vector <int>> mat(n + 1);
	vector <pair <int, int>> ans;
	mat[1] = query(1);
	int cnt[2]; cnt[0] = 0, cnt[1] = 0;
	for (int i = 1; i <= n; ++i)
		cnt[mat[1][i] % 2]++;
	int need = (cnt[1] < cnt[0] ? 1 : 0);
	for (int i = 2; i <= n; ++i) {
		if (mat[1][i] % 2 == need)
			mat[i] = query(i);
	}
	for (int i = 1 + need; i <= n; ++i) {
		for (int j = 1; j < mat[i].size(); ++j) {
			if (mat[i][j] == 1)
				ans.push_back({ i, j });
		}
	}
	cout << "!" << endl;
	for (auto& x : ans)
		cout << x.first << ' ' << x.second << endl;
}