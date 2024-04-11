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
		auto cmp=[&](int i) {
			return max(0, max(a[i-1], a[i+1])-a[i]+1);
		};
		auto cmb=[&](ar<ll, 2> a, ar<ll, 2> b) {
			if (a[0]!=b[0])
				return a[0]>b[0]?a:b;
			return a[1]<b[1]?a:b;
		};
		vector<ar<ll, 2>> dp0(n), dp1(n);
		dp1[1]={1, cmp(1)};
		for (int i=2; i<n-1; ++i) {
			dp0[i]=cmb(dp0[i-1], dp1[i-1]);
			dp1[i]=dp0[i-1];
			++dp1[i][0];
			dp1[i][1]+=cmp(i);
		}
		cout << cmb(dp0[n-2], dp1[n-2])[1] << "\n";
	}
	return 0;
}