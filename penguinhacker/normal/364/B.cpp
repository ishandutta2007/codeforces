#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, d, a[50], p[50], nxt[500001];
bool dp[500001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> d;
	dp[0]=1;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		for (int j=10000*(i+1); j>=a[i]; --j)
			dp[j]|=dp[j-a[i]];
	}
	nxt[500000]=-1;
	for (int i=500000-1; ~i; --i)
		nxt[i]=dp[i+1]?i+1:nxt[i+1];
	int val=0, cnt=0;
	while(1) {
		int can=val+d;
		if (nxt[val]==-1||nxt[val]>can)
			break;
		while(nxt[val]!=-1&&nxt[val]<=can)
			val=nxt[val];
		++cnt;
	}
	cout << val << " " << cnt;
	return 0;
}