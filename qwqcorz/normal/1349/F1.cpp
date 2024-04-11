#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+5;
const int mod=998244353;

int n,F[N][N],C[N][N],fact[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	for (int i=fact[0]=1;i<=n;i++) {
		fact[i]=1LL*fact[i-1]*i%mod;
	}
	for (int i=C[0][0]=1;i<=n;i++) {
		for (int j=C[i][0]=1;j<=i;j++) {
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
	for (int i=F[0][0]=1;i<=n;i++) {
		for (int j=F[i][0]=1;j<i;j++) {
			F[i][j]=(1LL*F[i-1][j]*(j+1)+1LL*F[i-1][j-1]*(i-j))%mod;
		}
	}
	for (int k=1;k<=n;k++) {
		int ans=0;
		for (int i=1;i<=n;i++) ans=(ans+1LL*F[i][k-1]*C[n][i]%mod*fact[n-i])%mod;
		cout<<ans<<" \n"[k==n];
	}
	
	return 0;
}