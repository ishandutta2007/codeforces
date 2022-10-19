#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

#define LL long long

const int mod=1000000007;
LL n,m,ans,f[2][1<<18][2][2];
char s[255][255],a[255][255];

int main(){
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
	if (n<m){swap(n,m); for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) a[i][j]=s[j][i];}
	else for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) a[i][j]=s[i][j];
	f[1][0][0][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			if (j==1)
				for (int k=0;k<1<<m;k++){
					f[0][k][0][0]=(f[1][k][0][0]+f[1][k][1][0])%mod;
					f[0][k][0][1]=(f[1][k][0][1]+f[1][k][1][1])%mod;
					f[0][k][1][0]=0;
					f[0][k][1][1]=0;
					f[1][k][0][0]=f[1][k][0][1]=f[1][k][1][0]=f[1][k][1][1]=0;
				}
			else
				for (int k=0;k<1<<m;k++){
					f[0][k][0][0]=f[1][k][0][0];
					f[0][k][0][1]=f[1][k][0][1];
					f[0][k][1][0]=f[1][k][1][0];
					f[0][k][1][1]=f[1][k][1][1];
					f[1][k][0][0]=f[1][k][0][1]=f[1][k][1][0]=f[1][k][1][1]=0;
				}
			for (int k=0;k<1<<m;k++)
				if (a[i][j]=='.'){
					(f[1][k|(1<<j-1)][1][0]+=f[0][k][0][0]+f[0][k][1][0])%=mod;
					(f[1][k|(1<<j-1)][1][1]+=f[0][k][0][1]+f[0][k][1][1])%=mod;
					(f[1][k][1][0]+=f[0][k][1][0])%=mod;
					(f[1][k][1][1]+=f[0][k][1][1])%=mod;
					if (k&(1<<j-1)){
						(f[1][k][0][0]+=f[0][k][0][0])%=mod;
						(f[1][k][0][1]+=f[0][k][0][1])%=mod;
					}
					if (!(k&(1<<j-1))) (f[1][k][0][1]+=f[0][k][0][0])%=mod;
				}
				else{
					(f[1][k&(~(1<<j-1))][0][0]+=f[0][k][0][0]+f[0][k][1][0])%=mod;
					(f[1][k&(~(1<<j-1))][0][1]+=f[0][k][0][1]+f[0][k][1][1])%=mod;
				}
		}
	for (int i=0;i<1<<m;i++) (ans+=f[1][i][0][0]+f[1][i][1][0]+f[1][i][0][1]+f[1][i][1][1])%=mod;
	printf("%lld\n",ans);
	
	return 0;
}