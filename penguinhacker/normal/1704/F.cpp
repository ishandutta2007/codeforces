#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5e5;
int n, dp[mxN];
string s;

void solve() {
	cin >> n >> s;
	int x=count(s.begin(), s.end(), 'R');
	if (x!=n-x) {
		cout << (x>n-x?"Alice":"Bob") << "\n";
		return;
	}
	vector<int> chains;
	int cur=0;
	for (int i=0; i+1<n; ++i) {
		if (s[i]==s[i+1]) {
			if (cur)
				chains.push_back(cur);
			cur=0;
		} else
			++cur;
	}
	if (cur)
		chains.push_back(cur);
	int ans=0;
	for (int i : chains) {
		//cout << i << endl;
		while(i>200)
			i-=34;
		ans^=dp[i];
	}
	cout << (ans?"Alice":"Bob") << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i=1; i<=200; ++i) {
		ll state=1ll<<dp[max(0, i-2)];
		for (int j=1; j<i; ++j)
			state|=1ll<<(dp[max(0, j-2)]^dp[max(0, i-j-1)]);
		dp[i]=__builtin_ctzll(state+1);
	}
	/*for (int i=0; i<=200; ++i) {
		cout << dp[i] << " ";
		if (i%34==33)
			cout << endl;
	}*/
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}