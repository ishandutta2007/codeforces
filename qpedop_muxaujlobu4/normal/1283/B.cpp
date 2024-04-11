#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<tuple>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, k;
		cin >> n >> k;
		int tmp = n / k;
		int res = min(tmp * k + k / 2, n);
		cout << res << "\n";
	}
	return 0;
}