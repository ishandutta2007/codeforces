#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e3+5;

int n,mod,C[N][N],f[N],dp[N][N],S[N][N],pre[N][N],suf[N][N];
vector<int>e[N],son[N];
void dfs(int now,int father) {
	for (int to:e[now]) {
		if (to==father) {
			continue;
		}
		son[now].push_back(to);
		dfs(to,now);
	}
	int m=son[now].size();
	if (!m) {
		for (int i=1;i<n;i++) {
			dp[now][i]=1;
		}
		return;
	}
	for (int i=1;i<n;i++) {
		dp[now][i]=pre[0][i]=suf[m-1][i]=1;
	}
	for (int i=0;i<m;i++) {
		for (int j=1;j<n;j++) {
			S[i][j]=(S[i][j-1]+dp[son[now][i]][j])%mod;
			dp[now][j]=1LL*dp[now][j]*S[i][j]%mod;
		}
	}
	if (now==1) {
		return;
	}
	for (int i=0;i+1<m;i++) {
		for (int j=1;j<n;j++) {
			pre[i+1][j]=1LL*pre[i][j]*S[i][j]%mod;
		}
	}
	for (int i=m-1;i>=1;i--) {
		for (int j=1;j<n;j++) {
			suf[i-1][j]=1LL*suf[i][j]*S[i][j]%mod;
		}
	}
	for (int i=0;i<m;i++) {
		int sum=0;
		for (int j=1;j<n;j++) {
			dp[now][j]=(dp[now][j]+1LL*sum*dp[son[now][i]][j])%mod;
			sum=(sum+1LL*pre[i][j]*suf[i][j])%mod;
		}
	}
}
void work() {
	cin>>n>>mod;
	for (int i=1;i<n;i++) {
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	for (int i=C[0][0]=1;i<=n;i++) {
		for (int j=C[i][0]=1;j<=i;j++) {
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
	for (int i=1;i<n;i++) {
		f[i]=dp[1][i];
		for (int j=1;j<i;j++) {
			f[i]=(f[i]-1LL*C[i][j]*f[j]%mod+mod)%mod;
		}
		cout<<f[i]<<" \n"[i+1==n];
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T=1;
//	cin>>T;
	while (T--) {
		work();
	}
	
	return 0;
}