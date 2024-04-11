#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=200000;
int n,m,f[maxn+10],pre[maxn+10],a[maxn+10],acnt; bool b[maxn+10];
vector<int> g[maxn+10];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
ll fpow(ll a,ll b,ll mod){
	ll ans=1; for(;b;b/=2,a=a*a%mod) if(b%2) ans=ans*a%mod; return ans;
}
ll phi(ll x){
	ll ans=x; for(int i=2;i*i<=x;++i) if(x%i==0) for(ans=ans/i*(i-1);x%i==0;x/=i);
	if(x>1) ans=ans/x*(x-1); return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		int x; scanf("%d",&x); b[x?x:m]=1;
	}
	for(int i=1;i<=m;++i) if(!b[i]) g[gcd(i,m)].push_back(i);
	for(int i=1;i<=m;++i){
		f[i]+=g[i].size();
		for(int j=i*2;j<=m;j+=i) if(f[i]>f[j]){
			f[j]=f[i]; pre[j]=i;
		}
	}
	for(int i=m;i;i=pre[i]) for(int j=0;j<g[i].size();++j) a[++acnt]=g[i][j];
	printf("%d\n%d ",f[m],a[acnt]%m);
	for(int i=acnt-1;i;--i){
		int g=gcd(a[i+1],m); printf("%lld ",1ll*fpow(a[i+1]/g,phi(m/g)-1,m/g)*a[i]/g%(m/g));
	}
}