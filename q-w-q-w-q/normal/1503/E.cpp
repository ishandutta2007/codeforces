#include<iostream>
#include<cstdio>
using namespace std;
const int mod=998244353,N=2022;
int n,m,ans,f[N][N],s[N][N];
int main(){
	cin>>n>>m;
	for(int i=0;i<=m;i++) f[0][i]=1;
	for(int i=1;i<=n;i++){
		f[i][0]=1;
		for(int j=1;j<=m;j++) f[i][j]=(f[i-1][j]+f[i][j-1])%mod; 
	}
	for(int i=1;i<n;i++)
		for(int j=1,s=0;j<=m;j++)
			ans=(ans+1ll*f[i-1][j-1]*f[i][m-j]%mod*s)%mod,
			s=(s+1ll*f[n-i][j-1]*f[n-i-1][m-j])%mod;
	for(int j=1;j<m;j++)
		for(int i=2,s=0;i<n;i++)
			s=(s+1ll*f[i-2][j]*f[n+1-i][j-1])%mod,
			ans=(ans+1ll*s*f[i][m-j-1]%mod*f[n-i-1][m-j])%mod;
	cout<<(ans+ans)%mod;
}