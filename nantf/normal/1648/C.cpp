#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=266666,mod=998244353,INF=1e9;
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,m,c[maxn],t[maxn],ans,fac[maxn],invfac[maxn],pr=1,b[maxn];
inline void update(int p,int v){
	if(!v) return;
	for(int i=p;i<=2e5;i+=i&-i) b[i]+=v;
}
inline int query(int p){
	int s=0;
	for(int i=p;i;i-=i&-i) s+=b[i];
	return s;
}
int main(){
	n=read();m=read();
	FOR(i,1,n) c[read()]++;
	fac[0]=1;
	FOR(i,1,n) fac[i]=1ll*fac[i-1]*i%mod;
	invfac[n]=qpow(fac[n],mod-2);
	ROF(i,n-1,0) invfac[i]=1ll*invfac[i+1]*(i+1)%mod;
	FOR(i,1,2e5) pr=1ll*pr*invfac[c[i]]%mod,update(i,c[i]);
	FOR(i,1,m) t[i]=read();
	FOR(i,1,min(n,m)){
		ans=(ans+1ll*pr*fac[n-i]%mod*query(t[i]-1))%mod;
//		printf("i=%d,pr=%d,ans=%d,%d\n",i,pr,ans,c[t[i]]);
		if(!c[t[i]]) break;
		pr=1ll*pr*fac[c[t[i]]]%mod;
		c[t[i]]--;
		update(t[i],-1);
		pr=1ll*pr*invfac[c[t[i]]]%mod;
		if(i==n && n<m) ans=(ans+1)%mod;
	}
	printf("%d\n",ans);
}