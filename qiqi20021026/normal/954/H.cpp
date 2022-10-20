#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define N 12000

const int mod=1000000007;
int n,a[N],f[2][N],f2[2][N],g[N];

int main(){
	scanf("%d",&n);
	for (int i=1;i<n;++i) scanf("%d",&a[i]); a[0]=1;
	f[0][0]=1; f2[0][0]=1;
	for (int i=n,t=0;i>1;--i,t^=1){
		for (int j=0;j<=(n-1)*2;++j){
			g[j+2]=(g[j+2]+f2[t][j]*((LL)a[i-1]*(a[i-1]-1)/2%mod))%mod;
			g[j+1]=(g[j+1]+(LL)f[t][j]*a[i-1])%mod;
			g[0]=(g[0]+1)%mod;
		}
		for (int j=0;j<=(n-1)*2;++j) g[j]=(LL)g[j]*a[i-2]%mod;
		memset(f[t^1],0,sizeof f[t^1]);
		memset(f2[t^1],0,sizeof f2[t^1]);
		f[t^1][0]=1;
		for (int j=0;j<=(n-1)*2;++j)
			f[t^1][j+1]=(f[t^1][j+1]+(LL)a[i-1]*f[t][j])%mod;
		f2[t^1][0]=1;
		for (int j=0;j<=(n-1)*2;++j){
			f2[t^1][j+1]=(f2[t^1][j+1]+(LL)2*a[i-1]*f[t][j])%mod;
			f2[t^1][j+2]=(f2[t^1][j+2]+(LL)a[i-1]*a[i-1]%mod*f2[t][j])%mod;
		}
	}
	for (int i=1;i<=(n-1)*2;++i)
		printf(i==(n-1)*2?"%d\n":"%d ",g[i]);
	
	return 0;
}