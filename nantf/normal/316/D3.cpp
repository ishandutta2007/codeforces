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
int n,fac[maxn],inv[maxn],invfac[maxn],pw2[maxn];
void init(){
	fac[0]=fac[1]=inv[1]=invfac[0]=invfac[1]=1;
	FOR(i,2,n){
		fac[i]=1ll*fac[i-1]*i%mod;
		inv[i]=mod-1ll*(mod/i)*inv[mod%i]%mod;
		invfac[i]=1ll*invfac[i-1]*inv[i]%mod;
	}
	pw2[0]=1;
	FOR(i,1,n) pw2[i]=1ll*inv2*pw2[i-1]%mod;
}
inline int C(int n,int m){
	if(n<0 || n<m || m<0) return 0;
	return 1ll*fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
void solve(){
	n=read();
	init();
	int c1=0,c2=0;
	FOR(i,1,n){
		int x=read();
		if(x==1) c1++;
		else c2++;
	}
	int ans=0;
	FOR(i,0,c1) if((c1-i)%2==0)
		ans=(ans+1ll*C(c1,i)*C(c1-i,(c1-i)/2)%mod*fac[(c1-i)/2]%mod*pw2[(c1-i)/2])%mod;
	FOR(i,1,c2) ans=1ll*ans*(c1+i)%mod;
	printf("%d\n",ans);
}
int main(){
	int T=1;
	while(T--) solve();
}
// da biao ren fei sheng