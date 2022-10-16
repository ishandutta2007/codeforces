#include<bits/stdc++.h>
using namespace std;
const int maxn=100010,mod=1000000007;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int m,f[maxn],fac[7],fl;
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int dfs(int dep,int pro,int sgn,int up){
	if(dep>fl) return up/pro*sgn;
	else return dfs(dep+1,pro,sgn,up)+dfs(dep+1,pro*fac[dep],-sgn,up);
}
int cnt(int x,int y){
	fl=0;
	for(int i=2;i*i<=x;i++)
		if(x%i==0){
			fac[++fl]=i;
			while(x%i==0) x/=i;
		}
	if(x>1) fac[++fl]=x;
	return dfs(1,1,1,y);
}
int main(){
	m=read();int inv=qpow(m,mod-2);
	f[1]=0;
	FOR(i,1,m){
		if(i!=1){
			f[i]=1ll*f[i]*inv%mod;
			f[i]=(f[i]+1)%mod;
			f[i]=1ll*f[i]*qpow((1-1ll*(m/i)*inv%mod+mod)%mod,mod-2)%mod;
		}
		FOR(j,2,m/i) f[i*j]=(f[i*j]+1ll*f[i]*cnt(j,m/i))%mod;
	}
	int ans=0;
	FOR(i,1,m) ans=(ans+f[i]+1)%mod;
	ans=1ll*ans*inv%mod;
	printf("%d\n",ans);
}