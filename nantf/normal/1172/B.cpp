#include<bits/stdc++.h>
using namespace std;
const int maxn=200020,mod=998244353;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,fac[maxn],deg[maxn],ans;
int main(){
	ans=n=read();
	FOR(i,1,n-1) deg[read()]++,deg[read()]++;
	fac[0]=1;
	FOR(i,1,n) fac[i]=1ll*fac[i-1]*i%mod;
	FOR(i,1,n) ans=1ll*ans*fac[deg[i]]%mod;
	printf("%d\n",ans);
}