#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=1000000007,maxn=1000010;
ll a[maxn+10],inv[maxn+10],fac[maxn+10],invfac[maxn+10],sum[maxn+10],val,ans;
int id[maxn+10],n,rk[maxn+10],maxrk,k;
void prework(){
	inv[0]=fac[0]=invfac[0]=1;
	for(int i=1;i<=maxn;++i){
		inv[i]=i==1?1:(mod-mod/i*inv[mod%i]%mod)%mod;
		fac[i]=i*fac[i-1]%mod;
		invfac[i]=inv[i]*invfac[i-1]%mod;
	}
}
ll c(int a,int b){return fac[a]*invfac[b]%mod*invfac[a-b]%mod;}
bool cmp(int x,int y){return a[x]<a[y];}
int main(){
	prework(); scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]),id[i]=i;
	sort(id+1,id+n+1,cmp);
	for(int i=1;i<=n;++i){
		rk[id[i]]=a[id[i]]==a[id[i-1]]?rk[id[i-1]]:i;
	}
	for(int i=1;i<=n;++i) maxrk=max(maxrk,rk[i]);
	for(int i=1;i<=n;++i) if(rk[i]!=maxrk){
		(ans+=fac[n-1]*n%mod*inv[n-rk[i]+1]%mod*a[i]%mod)%=mod;
	}
	printf("%lld",ans);
}