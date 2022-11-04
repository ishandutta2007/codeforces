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
		long long r, g, b,MX=0,s=0;
		cin >> r >> g >> b;
		s = r + g + b;
		MX = max(r, max(g, b));
		s -= MX;
		if (s + 1 >= MX)cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}