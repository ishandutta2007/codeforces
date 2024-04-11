#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, h;
		cin >> n >> h;
		vector<int> a(n);
		for (int& i : a)
			cin >> i;
		sort(a.begin(), a.end());
		int x=a.back(), y=a.end()[-2];
		int ans=h/(x+y)*2;
		h%=x+y;
		cout << (ans+(h?h<=x?1:2:0)) << "\n";
	}
	return 0;
}