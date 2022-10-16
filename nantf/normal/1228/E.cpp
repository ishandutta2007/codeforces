#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=1000000007;
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
int n,k,ans,fac[maxn],invfac[maxn];
int qpow(int a,ll b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int C(int n,int m){
	return 1ll*fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
int main(){
	n=read();k=read();
	if(k==1) return puts("1"),0;
	fac[0]=1;
	FOR(i,1,n) fac[i]=1ll*fac[i-1]*i%mod;
	invfac[n]=qpow(fac[n],mod-2);
	ROF(i,n-1,0) invfac[i]=1ll*invfac[i+1]*(i+1)%mod;
	FOR(i,0,n) FOR(j,0,n){
		int sum=1ll*C(n,i)*C(n,j)%mod*qpow(k-1,1ll*n*n-1ll*(n-i)*(n-j))%mod*qpow(k,1ll*(n-i)*(n-j))%mod;
		if((i+j)%2==0) ans=(ans+sum)%mod;
		else ans=(ans-sum+mod)%mod;
	}
	printf("%d\n",ans);
}