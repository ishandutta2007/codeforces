#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

long long triangle(long long x) {
	return x*(x+1)/2;
}

int main() {
	int n; cin >> n;
	
	vector<pair<int,int>> points;
	while (n--) {
		int x, y;
		cin >> x >> y;
		points.emplace_back(-y,x);
	}
	sort(begin(points),end(points));

	vector<vector<int>> levels;
	int py = 0;
	for (auto [y,x]: points) {
		if (y != py) levels.push_back({});
		levels.back().push_back(x);
		py = y;
	}
	
	oset S;
	long long res = 0;
	for (auto xs: levels) {
		int px = -1;
		for (int x: xs) {
			res -= triangle(S.order_of_key(x) - S.order_of_key(px+1));
			px = x;
			S.insert(x);
		}
		res -= triangle(S.size() - S.order_of_key(px+1));
		res += triangle(S.size());
	}
	cout << res << endl;
}