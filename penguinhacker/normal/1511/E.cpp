#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int M=998244353;
int n, m, cnt;
vector<string> g;
ll ans, p[300001], c[300001][2], dp[300001][2];

void solve(int x) {
	ans=(ans+(dp[x][0]+dp[x][1])*p[cnt-x])%M;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	p[0]=1;
	for (int i=1; i<=300000; ++i)
		p[i]=p[i-1]*2%M;
	c[1][0]=c[1][1]=1;
	for (int i=2; i<=300000; ++i) {
		c[i][0]=(c[i-1][0]+2*c[i-1][1])%M;
		c[i][1]=c[i-1][0];
		dp[i][0]=(dp[i-1][0]+2*dp[i-1][1]+c[i-1][1])%M;
		dp[i][1]=dp[i-1][0];
	}
	cin >> n >> m;
	g=vector<string>(n, string(m, '.'));
	for (int i=0; i<n; ++i) {
		cin >> g[i];
		cnt+=count(g[i].begin(), g[i].end(), 'o');
	}
	for (int rep=0; rep<2; ++rep) {
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				if (g[i][j]=='*')
					continue;
				int k=j;
				while(k+1<m&&g[i][k+1]=='o')
					++k;
				solve(k-j+1);
				j=k;
			}
		}
		vector<string> ng(m, string(n, '.'));
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				ng[j][i]=g[i][j];
		swap(n, m);
		swap(g, ng);
	}
	cout << ans;
	return 0;
}