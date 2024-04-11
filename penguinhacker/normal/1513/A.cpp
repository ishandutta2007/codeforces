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
		int n, k;
		cin >> n >> k;
		if (k>(n-1)/2) {
			cout << "-1\n";
			continue;
		}
		vector<int> v(n), ans(n);
		iota(v.begin(), v.end(), 1);
		for (int i=1; i<2*k; i+=2)
			ans[i]=v.back(), v.pop_back();
		for (int i=0; i<=2*k; i+=2)
			ans[i]=v.back(), v.pop_back();
		for (int i=2*k+1; i<n; ++i)
			ans[i]=v.back(), v.pop_back();
		for (int i : ans)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}