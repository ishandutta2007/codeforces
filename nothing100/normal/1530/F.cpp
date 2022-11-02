#include<bits/stdc++.h>
using namespace std;
const int mo=31607;
const int ny=3973;
int n,a[24][24],f[1<<24],dp[1<<24],xs[1<<24],res;
int main(){
	//freopen("F.in","r",stdin);
	//freopen("F.out","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;i++) 
	for (int j=0;j<n;j++) scanf("%d",&a[i][j]);
	for (int i=0;i<(4<<n);i++) dp[i]=1;
	for (int i=0;i<n;i++){
		memset(f,0,sizeof(f));
		f[0]=1;
		for (int j=0;j<n;j++)
		for (int k=(1<<j);k<(2<<j);k++)
			f[k]=f[k-(1<<j)]*a[i][j]%mo*ny%mo;
		for (int k=(1<<n);k<(2<<n);k++){
			if (k&(1<<i)) f[k]=f[k-(1<<n)];
			else f[k]=f[k-(1<<n)]*a[i][i]%mo*ny%mo;
		}
		for (int k=(2<<n);k<(3<<n);k++){
			if (k&(1<<(n-i-1))) f[k]=f[k-(2<<n)];
			else f[k]=f[k-(2<<n)]*a[i][n-i-1]%mo*ny%mo;
		}
		for (int k=(3<<n);k<(4<<n);k++){
			if (2*i==n-1||(k&(1<<(n-i-1)))) f[k]=f[k-(2<<n)];
			else f[k]=f[k-(2<<n)]*a[i][n-i-1]%mo*ny%mo;
		}
		for (int k=0;k<(4<<n);k++) dp[k]=(dp[k]*(f[k]-f[(1<<n)-1])%mo+mo)%mo;
	}
	dp[0]=dp[0];
	xs[0]=-1;
	for (int i=0;i<n+2;i++){
		for (int j=(1<<i);j<(2<<i);j++){
			xs[j]=-xs[j-(1<<i)];
			res=(res+xs[j]*dp[j]+mo)%mo;
		}
	}
	printf("%d\n",(res-dp[0]+mo+1)%mo);
}