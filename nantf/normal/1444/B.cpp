#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=333333,mod=998244353;
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
int n,a[maxn],fac[maxn],inv[maxn],invfac[maxn],s1,s2,ans;
inline int C(int n,int m){
	if(n<0 || n<m || m<0) return 0;
	return 1ll*fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
int main(){
	n=read();
	FOR(i,1,2*n) a[i]=read();
	sort(a+1,a+2*n+1);
	fac[0]=fac[1]=inv[1]=invfac[0]=invfac[1]=1;
	FOR(i,2,n){
		fac[i]=1ll*fac[i-1]*i%mod;
		inv[i]=mod-1ll*(mod/i)*inv[mod%i]%mod;
		invfac[i]=1ll*invfac[i-1]*inv[i]%mod;
	}
	FOR(i,1,n) s1=(s1+a[i])%mod;
	FOR(i,n+1,2*n) s2=(s2+a[i])%mod;
	FOR(i,1,n){
		ans=(ans+1ll*(s2-s1+mod)*C(n-1,i-1)%mod*C(n,i))%mod;
	}
	printf("%d\n",ans*2%mod);
}