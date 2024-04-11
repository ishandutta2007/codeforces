#include<bits/stdc++.h>
using namespace std;
const int maxn=1010,mod=1000000007;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int k,pa,pb,dp[maxn][maxn],pinv,pbinv;
int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int DP(int i,int j){
	if(i+j>=k) return (i+j+1ll*pa*pbinv)%mod;
	if(~dp[i][j]) return dp[i][j];
	return dp[i][j]=(1ll*pa*DP(i+1,j)+1ll*pb*DP(i,i+j))%mod*pinv%mod;
}
int main(){
	MEM(dp,-1);
	k=read();pa=read();pb=read();
	pinv=qpow((pa+pb)%mod,mod-2);
	pbinv=qpow(pb,mod-2);
	printf("%d\n",DP(1,0));
}