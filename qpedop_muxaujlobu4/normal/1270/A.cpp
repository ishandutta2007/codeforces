
#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, k1, k2;
		bool ans;
		cin >> n >> k1 >> k2;
		for (int j = 0; j < k1; ++j) {
			int tmp;
			cin >> tmp;
			if (tmp == n)ans = true;
		}
		for (int j = 0; j < k2; ++j) {
			int tmp;
			cin >> tmp;
			if (tmp == n)ans = false;
		}
		if (ans)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}