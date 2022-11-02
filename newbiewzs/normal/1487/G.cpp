#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#define int long long
using namespace std;
int read(){
	int s=0;
	int x=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*x;
}
const int N=405;
const int mod=998244353;
int n,a[N];
int f[2][N][N][3][3];
int g[N][N];
signed main(){
	n=read();
	for(int i=1;i<=26;i++){
		a[i]=read();
	}
	for(int i=0;i<=2;i++){
		for(int k=0;k<=2;k++){
			f[0][(i==0)+(k==0)][(i==1)+(k==1)][i][k]=((i<=1)?1:24)*((k<=1)?1:24);
		}
	}
	for(int i=3;i<=n;i++){
		memset(f[i&1],0,sizeof(f[i&1]));
		int pre=((i-1)&1);
		for(int k=0;k<=i;k++){
			for(int j=0;j<=i;j++){
				for(int l=0;l<=2;l++){
					f[i&1][k][j][l][0]=(f[i&1][k][j][l][0]+((k>=1)?(f[pre][k-1][j][1][l]+f[pre][k-1][j][2][l])%mod:0))%mod;
					f[i&1][k][j][l][1]=(f[i&1][k][j][l][1]+((j>=1)?(f[pre][k][j-1][0][l]+f[pre][k][j-1][2][l])%mod:0))%mod;
					f[i&1][k][j][l][2]=((f[i&1][k][j][l][2]+1ll*f[pre][k][j][2][l]*23%mod)%mod+(1ll*f[pre][k][j][0][l]*24%mod+1ll*f[pre][k][j][1][l]*24%mod)%mod)%mod;
				}
			}
		}
	}
	for(int i=n;i>=0;i--){
		for(int k=n;k>=0;k--){
			g[i][k]=(g[i][k]+f[n&1][i][k][0][0])%mod;
			g[i][k]=(g[i][k]+f[n&1][i][k][0][1])%mod;
			g[i][k]=(g[i][k]+f[n&1][i][k][0][2])%mod;
			g[i][k]=(g[i][k]+f[n&1][i][k][1][0])%mod;
			g[i][k]=(g[i][k]+f[n&1][i][k][1][1])%mod;
			g[i][k]=(g[i][k]+f[n&1][i][k][1][2])%mod;
			g[i][k]=(g[i][k]+f[n&1][i][k][2][0])%mod;
			g[i][k]=(g[i][k]+f[n&1][i][k][2][1])%mod;
			g[i][k]=(g[i][k]+f[n&1][i][k][2][2])%mod;
		}
	}
	for(int i=n;i>=0;i--){
		for(int k=n;k>=0;k--){
			g[i][k]=((g[i+1][k]+g[i][k+1])%mod-g[i+1][k+1]+mod+g[i][k]+mod+mod)%mod;
		}
	}
	int ans=g[0][0];
	for(int i=1;i<=26;i++){
		ans=(ans-g[a[i]+1][0]+mod)%mod;
	}
	for(int i=1;i<=26;i++){
		for(int k=i+1;k<=26;k++){
			ans=(ans+g[a[i]+1][a[k]+1])%mod;
		}
	}
	cout<<ans;
	return 0;
}