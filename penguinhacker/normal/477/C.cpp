#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array

const int INF=1e9;
int dp[2001][2001], ans[2001];
string s, p;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> p;
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0]=0;
	for (int i=0; i<s.size(); ++i)
		for (int j=0; j<=i; ++j) {
			if (dp[i][j]>=INF)
				continue;
			bool t=j%p.size()>0;
			dp[i+1][j]=min(dp[i+1][j], dp[i][j]+t); // remove this character
			if (s[i]==p[j%p.size()])
				dp[i+1][j+1]=min(dp[i+1][j+1], dp[i][j]);
		}
	int pos=0;
	for (int i=p.size(); i<=s.size(); i+=p.size())
		if (dp[s.size()][i]<INF) {
			ans[dp[s.size()][i]]=i/p.size();
			pos=dp[s.size()][i];
		}
	for (int i=1; i<pos; ++i)
		ans[i]=max(ans[i], ans[i-1]);
	for (int i=pos+1; i<=s.size(); ++i) {
		int x=s.size()-i;
		if (x>=ans[pos]*p.size())
			ans[i]=ans[pos];
		else
			ans[i]=x/p.size();
	}
	for (int i=0; i<=s.size(); ++i)
		cout << ans[i] << "\n";
	return 0;
}