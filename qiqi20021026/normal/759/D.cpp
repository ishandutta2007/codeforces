#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define N 6000

const int mod=1000000007;
int n,ans,f[30][N],fac[N],ifac[N],sum[N];
char s[N];

int inv(int x){return x==1?1:(LL)(mod-mod/x)*inv(mod%x)%mod;}

int C(int x,int y){return (LL)fac[x]*ifac[y]%mod*ifac[x-y]%mod;}

int main(){
	scanf("%d%s",&n,s+1);
	fac[0]=1; for (int i=1;i<=n;i++) fac[i]=(LL)fac[i-1]*i%mod;
	ifac[n]=inv(fac[n]); for (int i=n-1;i>=0;i--) ifac[i]=(LL)ifac[i+1]*(i+1)%mod;
	sum[0]=1;
	for (int i=1;i<=n;i++){
		int ch=s[i]-'a';
		for (int j=1;j<=n;j++){
			sum[j]=(sum[j]-f[ch][j]+mod)%mod;
			f[ch][j]=(sum[j-1]-f[ch][j-1]+mod)%mod;
			sum[j]=(sum[j]+f[ch][j])%mod;
		}
	}
	for (int i=1;i<=n;i++)
		ans=(ans+(LL)sum[i]*C(n-1,i-1))%mod;
	printf("%d\n",ans);
	
	return 0;
}