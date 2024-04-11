#include <stdio.h>
#include <string.h>
#define MN 400
typedef long long LL;
const int mod = 998244353;

int n,a[26];
int f[2][3][3][MN+5][MN+5];
int g[MN+5][MN+5];

int main(){
	scanf("%d",&n);
	for(int i=0;i<26;i++)
		scanf("%d",&a[i]);
	f[0][0][0][0][0] = 1;
	for(int i=0;i<n;i++){
		memset(f[(i&1)^1],0,sizeof(f[0]));
		for(int c0=0;c0<3;c0++){
			for(int c1=0;c1<3;c1++){
				for(int u0=0;u0<=i;u0++){
					for(int u1=0;u0+u1<=i;u1++){
						int cf = f[i&1][c0][c1][u0][u1];
						if(i<2||c0!=0){
							int& tf = f[(i+1)&1][c1][0][u0+1][u1];
							tf = (tf+cf)%mod;
						}
						if(i<2||c0!=1){
							int& tf = f[(i+1)&1][c1][1][u0][u1+1];
							tf = (tf+cf)%mod;
						}
						if(i<2||c0!=2){
							int& tf = f[(i+1)&1][c1][2][u0][u1];
							tf = (tf+cf*24ll)%mod;
						}else{
							int& tf = f[(i+1)&1][c1][2][u0][u1];
							tf = (tf+cf*23ll)%mod;
						}
					}
				}
			}
		}
	}
	for(int c0=0;c0<3;c0++){
		for(int c1=0;c1<3;c1++){
			for(int u0=0;u0<=n;u0++){
				for(int u1=0;u0+u1<=n;u1++){
					g[u0][u1] = (g[u0][u1]+f[n&1][c0][c1][u0][u1])%mod;
				}
			}
		}
	}
	for(int u0=n;u0>=0;u0--){
		for(int u1=n;u1>=0;u1--){
			g[u0][u1] = ((LL)g[u0][u1]+g[u0+1][u1]+g[u0][u1+1]-g[u0+1][u1+1])%mod;
			if(g[u0][u1]<0) g[u0][u1] += mod;
		}
	}
	int ans = g[0][0];
	for(int i=0;i<26;i++){
		ans = ans-g[a[i]+1][0];
		if(ans<0) ans += mod;
	}
	for(int i=0;i<26;i++){
		for(int j=i+1;j<26;j++){
			ans = ans+g[a[i]+1][a[j]+1];
			if(ans>=mod) ans -= mod;
		}
	}
	printf("%d\n",ans);
}