#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

string s, t;
bool dp[999][500][2];

void solve() {
	cin >> s >> t;
	for (int i=0; i<s.size(); ++i)
		dp[0][i][0]=dp[0][i][1]=t[0]==s[i];
	for (int i=1; i<t.size(); ++i) {
		memset(dp[i], 0, 2*s.size());
		for (int j=0; j<s.size(); ++j) {
			if (dp[i-1][j][0]&&j+1<s.size()&&t[i]==s[j+1])
				dp[i][j+1][0]=dp[i][j+1][1]=1;
			if (dp[i-1][j][1]&&j&&t[i]==s[j-1])
				dp[i][j-1][1]=1;
		}
	}
	bool ok=0;
	for (int i=0; i<s.size(); ++i)
		ok|=dp[t.size()-1][i][1];
	cout << (ok?"YES":"NO") << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}