#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> v1, v2, vv;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		if (a < b) {
			v1.push_back({a,b,i});
		} else {
			v2.push_back({a,b,i});
		}
	}
	sort(v1.rbegin(),v1.rend());
	sort(v2.begin(),v2.end());
	if (v1.size() > v2.size()) vv = v1;
	else vv = v2;
	cout << vv.size() << "\n";
	for (auto x : vv) {
		cout << x[2] << " ";
	}
	cout << "\n";
}