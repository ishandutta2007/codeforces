#include<bits/stdc++.h>
using namespace std;
const int maxn=1111111,mod=1000000007;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,k,a[maxn],fac[maxn];
int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int main(){
	n=read();k=read();
	FOR(i,1,k+2) a[i]=(a[i-1]+qpow(i,k))%mod;
	if(n<=k+2) return printf("%d\n",a[n]),0;
	int pro=1;
	fac[0]=1;
	FOR(i,1,k+2) pro=1ll*pro*(n-i)%mod,fac[i]=1ll*fac[i-1]*i%mod;
	int ans=0;
	FOR(i,1,k+2){
		int x=1ll*(n-i)*fac[i-1]%mod*fac[k-i+2]%mod;
		if((k-i+2)&1) x=(mod-x)%mod;
		ans=(ans+1ll*pro*qpow(x,mod-2)%mod*a[i])%mod;
	}
	printf("%d\n",ans);
}