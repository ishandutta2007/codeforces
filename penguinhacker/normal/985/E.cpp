#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5e5;
int n, k, d, a[mxN], p[mxN+1];
bool dp[mxN+1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> d;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);
	dp[0]=1;
	fill(p, p+k, 1);
	for (int i=k-1; i<n; ++i) {
		int j=lower_bound(a, a+n, a[i]-d)-a;
		if (i-j+1>=k)
			dp[i+1]=p[i-k+1]-(j?p[j-1]:0)>0;
		p[i+1]=p[i]+dp[i+1];
	}
	cout << (dp[n]?"YES":"NO");
	return 0;
}