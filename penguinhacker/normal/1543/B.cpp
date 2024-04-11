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
		int n;
		cin >> n;
		vector<int> a(n);
		for (int& i : a)
			cin >> i;
		ll s=accumulate(a.begin(), a.end(), 0ll);
		ll r=s%n;
		cout << r*(n-r) << "\n";
	}
	return 0;
}