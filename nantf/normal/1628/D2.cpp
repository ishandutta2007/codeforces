#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1111111,mod=1000000007,inv2=(mod+1)/2;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,m,k,fac[maxn],invfac[maxn],pw[maxn];
inline int C(int n,int m){
	if(n<0 || n<m || m<0) return 0;
	return 1ll*fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
void solve(){
	n=read();m=read();
	n-=m;
	fac[0]=1;
	FOR(i,1,n+m) fac[i]=1ll*fac[i-1]*i%mod;
	invfac[n+m]=qpow(fac[n+m],mod-2);
	ROF(i,n+m-1,0) invfac[i]=1ll*invfac[i+1]*(i+1)%mod;
	pw[0]=1;
	FOR(i,1,n+m) pw[i]=1ll*pw[i-1]*inv2%mod;
	int ans=0;
	FOR(i,1,m) ans=(ans+1ll*C(n-1+m-i,n-1)*pw[n+m-i]%mod*i)%mod;
	if(!n) ans=m;
	ans=1ll*ans*read()%mod;
	printf("%d\n",ans);
}
int main(){
	int T=read();
	while(T--) solve();
}