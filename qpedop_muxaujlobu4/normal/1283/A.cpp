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
		int a, b;
		cin >> a >> b;
		int res = (24 - a) * 60 - b;
		cout << res << "\n";
	}
	return 0;
}