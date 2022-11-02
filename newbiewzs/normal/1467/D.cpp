#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int f[N][N];
int g[N][N];
int n,m,s,x,y;
int tong[N];
int a[N];
const int mod=1e9+7;
signed main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		f[0][i]=1;
		g[m][i]=1;
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		for(int k=1;k<=n;k++){
		if(k>1)f[i][k]=(f[i-1][k-1]);
		if(k<n)f[i][k]=(f[i][k]+f[i-1][k+1])%mod;}
	}
	for(int i=m-1;i>=0;i--){
		for(int k=1;k<=n;k++){
		if(k>1)g[i][k]=(g[i+1][k-1]);
		if(k<n)g[i][k]=(g[i][k]+g[i+1][k+1])%mod;
			tong[k]=(tong[k]+1ll*g[i][k]*f[i][k]%mod)%mod;
		}
	}
	for(int i=1;i<=n;i++)tong[i]=(tong[i]+f[m][i])%mod;
	for(int i=1;i<=n;i++){
		ans=(ans+1ll*tong[i]*a[i]%mod)%mod;
	}
	for(int i=1;i<=s;i++){
		scanf("%d%d",&x,&y);
		ans=(ans+1ll*(y-a[x]+mod)%mod*tong[x]%mod+mod)%mod;
		printf("%lld\n",ans);
		a[x]=y;
	}
	return 0;
}