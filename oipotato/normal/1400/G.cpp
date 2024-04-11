#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int MOD=998244353;
const int N=300010;
vector<pair<int,int>>g[N],lk[N];
int fac[N],inv[N],C[50],n,m,cnt[1<<20],a[30],b[30];
bool vis[N],exi[N];
int mypow(int x,int n){int ans=1;for(;n;n>>=1,x=1ll*x*x%MOD)if(n&1)ans=1ll*ans*x%MOD;return ans;}
void rebuild(int msk)
{
	rep(j,2*m)C[j]=0;
	for(int i=msk;i;i=msk&(i-1))C[cnt[i]]+=(__builtin_popcount(i)&1?-1:1);
	rep(j,2*m)(C[j]+=MOD)%=MOD;
}
void rev(int x,int&msk)
{
	bool flag=0;
	exi[x]^=1;
	for(auto i:lk[x])if(exi[i.first])msk^=1<<(i.second-1),flag=1;
	if(flag)rebuild(msk);
}
int main()
{
	scanf("%d%d",&n,&m);
	fac[0]=1;
	rep(i,n)fac[i]=1ll*fac[i-1]*i%MOD;
	inv[n]=mypow(fac[n],MOD-2);
	for(int i=n-1;i>=0;i--)inv[i]=1ll*inv[i+1]*(i+1)%MOD;
	rep(i,n){int l,r;scanf("%d%d",&l,&r);g[l].pb(mp(i,1));g[r+1].pb(mp(i,-1));}
	rep(i,m)scanf("%d%d",&a[i],&b[i]),lk[a[i]].pb(mp(b[i],i)),lk[b[i]].pb(mp(a[i],i));
	rep(i,(1<<m))
	{
		int msk=i-1;cnt[msk]=0;
		rep(j,m)if(msk&(1<<(j-1))){if(!vis[a[j]])cnt[msk]++,vis[a[j]]=1;if(!vis[b[j]])cnt[msk]++,vis[b[j]]=1;}
		rep(j,m)if(msk&(1<<(j-1)))vis[a[j]]=vis[b[j]]=0;
	}
	int msk=0,k=0,ans=0;C[0]=1;
	rep(i,n)
	{
		for(auto j:g[i])rev(j.first,msk),k+=j.second;
		if(i>k)continue;
		for(int j=0;j<=2*m&&j<=i&&j<=k;j++)if(C[j])ans=(ans+1ll*C[j]*fac[k-j]%MOD*inv[i-j]%MOD*inv[k-i])%MOD;
	}
	printf("%d\n",ans);
    return 0;
}