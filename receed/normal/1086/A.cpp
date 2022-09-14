#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
 
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<int> x(3), y(3), ax(3), ay(3);
	rep(i, 3)
		cin >> x[i] >> y[i];
	ax = x;
	sort(ax.begin(), ax.end());
	ay = y;
	sort(ay.begin(), ay.end());
	int mx = ax[1], my = ay[1];
	vector<pair<int, int>> ans({{mx, my}});
	rep(i, 3) {
		if (x[i] < mx)
			for (int j = x[i]; j < mx; j++)
				ans.push_back({j, y[i]});
		else
			for (int j = mx + 1; j <= x[i]; j++)
				ans.push_back({j, y[i]});
		if (y[i] < my)
			for (int j = y[i]; j < my; j++)
				ans.push_back({mx, j});
		else
			for (int j = my + 1; j <= y[i]; j++)
				ans.push_back({mx, j});
	}
	cout << ans.size() << '\n';
	for (auto pp : ans)
		cout << pp.first << ' ' << pp.second << '\n';
}