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
		vector<int> a(n), b(n);
		int base=0, sum=0;
		for (int& i : a) {
			cin >> i;
			sum+=i;
			base+=i*i*(n-2);
		}
		for (int& i : b) {
			cin >> i;
			sum+=i;
			base+=i*i*(n-2);
		}
		bitset<10001> dp;
		dp[0]=1;
		for (int i=0; i<n; ++i)
			dp=(dp<<a[i])|(dp<<b[i]);
		int ans=1e9;
		for (int i=0; i<=sum; ++i)
			if (dp[i])
				ans=min(ans, base+i*i+(sum-i)*(sum-i));
		cout << ans << "\n";
	}
	return 0;
}