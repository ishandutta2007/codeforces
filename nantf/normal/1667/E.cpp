#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222222,mod=998244353;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0;bool f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
inline int qmo(int x){return x+((x>>31)&mod);}
int n,m,fac[maxn],inv[maxn],ifac[maxn],ans[maxn],sum;
inline int C(int n,int m){
	if(n<0 || n<m || m<0) return 0;
	return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod; 
} 
int main(){
	n=read();m=(n+1)/2;
	fac[0]=1;
	FOR(i,1,n) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n],mod-2);
	ROF(i,n-1,0) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	FOR(i,1,n) inv[i]=1ll*ifac[i]*fac[i-1]%mod;
	ROF(i,n,1){
		ans[i]=i==1?fac[n-1]:1ll*fac[n-i]*fac[i-1]%mod*C((n-1)/2,i-1)%mod;
		ans[i]=(ans[i]-1ll*sum*inv[i]%mod+mod)%mod;
		sum=(sum+ans[i])%mod;
	}
	FOR(i,1,n) printf("%d ",ans[i]);
}