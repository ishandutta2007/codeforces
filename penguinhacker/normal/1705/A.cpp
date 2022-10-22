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
		int n, x;
		cin >> n >> x;
		vector<int> a(2*n);
		for (int& i : a)
			cin >> i;
		sort(a.begin(), a.end());
		bool ok=1;
		for (int i=0; i<n; ++i)
			ok&=a[i]+x<=a[i+n];
		cout << (ok?"YES":"NO") << "\n";
	}
	return 0;
}