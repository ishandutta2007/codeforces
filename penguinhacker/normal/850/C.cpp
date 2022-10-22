#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

map<int, int> mp, dp;
int solve(int x) {
	if (dp.find(x)==dp.end()) {
		int ans=0;
		for (int i=0; (1<<i)<=x; ++i) {
			int nxt=(x>>(i+1))|(x&(1<<i)-1);
			ans|=1<<solve(nxt);
		}
		dp[x]=__builtin_ctz(ans+1);
	}
	return dp[x];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while(n--) {
		int a; cin >> a;
		for (int i=2; i*i<=a; ++i) {
			if (a%i)
				continue;
			int cnt=-1;
			while(a%i==0)
				++cnt, a/=i;
			mp[i]|=1<<cnt;
		}
		if (a>1)
			mp[a]|=1;
	}
	dp[0]=0;
	int ans=0;
	for (auto& x : mp)
		ans^=solve(x.second);
	cout << (ans?"Mojtaba":"Arpa");
	return 0;
}