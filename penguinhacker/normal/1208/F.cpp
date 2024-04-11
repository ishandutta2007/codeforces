#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6;
int n, a[mxN];
ar<int, 2> dp[1<<21];

void add(ar<int, 2>& a, int x) {
	if (x>a[0])
		a={x, a[0]};
	else if (x>a[1]) {
		assert(x!=a[0]);
		a[1]=x;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		add(dp[a[i]], i);
	}
	for (int j=0; j<21; ++j)
		for (int i=0; i<(1<<21); ++i)
			if (!(i&1<<j)) {
				add(dp[i], dp[i|1<<j][0]);
				add(dp[i], dp[i|1<<j][1]);
			}
	int ans=0;
	for (int i=0; i+2<n; ++i) {
		int cur=0;
		for (int j=20; ~j; --j)
			if (!(a[i]&1<<j)&&dp[cur|1<<j][1]>i)
				cur|=1<<j;
		ans=max(ans, a[i]|cur);
	}
	cout << ans;
	return 0;
}