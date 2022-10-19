//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll ksm(ll x,ll y)
{
	ll ret=1;
	while(y>0)
	{
		if(y&1)
		{
			ret=(ret*x)%mod;
		}
		x=(x*x)%mod;
		y>>=1;
	}
	return ret;
}
bool isprm[500];
vector<ll> allp;
ll n,ans,mx[N],pre[N],cnt[N],res,inv[N];
vector<pair<ll,pair<ll,ll> > > vt[N];
void dfs(ll x,ll lst)
{
	ll i,j,nxt;
	for(i=0;i<allp.size();i++)
	{
		mx[allp[i]]=max(mx[allp[i]],pre[i]);
	}
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i].F!=lst)
		{
			nxt=vt[x][i].S.S;
			for(j=0;j<allp.size();j++)
			{
				while(nxt%allp[j]==0)
				{
					pre[j]--;
					nxt/=allp[j];
				}
			}
			if(nxt>1)
			{
				cnt[nxt]--;
			}
			nxt=vt[x][i].S.F;
			for(j=0;j<allp.size();j++)
			{
				while(nxt%allp[j]==0)
				{
					pre[j]++;
					nxt/=allp[j];
				}
			}
			if(nxt>1)
			{
				cnt[nxt]++;
				mx[nxt]=max(mx[nxt],cnt[nxt]);
			}
			dfs(vt[x][i].F,x);
			nxt=vt[x][i].S.S;
			for(j=0;j<allp.size();j++)
			{
				while(nxt%allp[j]==0)
				{
					pre[j]++;
					nxt/=allp[j];
				}
			}
			if(nxt>1)
			{
				cnt[nxt]++;
			}
			nxt=vt[x][i].S.F;
			for(j=0;j<allp.size();j++)
			{
				while(nxt%allp[j]==0)
				{
					pre[j]--;
					nxt/=allp[j];
				}
			}
			if(nxt>1)
			{
				cnt[nxt]--;
			}
		}
	}
	return;
}
void dfs2(ll x,ll lst,ll curx,ll cury)
{
	res=(res+((cury*((ans*curx)%mod))%mod))%mod;
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i].F!=lst)
		{
			dfs2(vt[x][i].F,x,(curx*inv[vt[x][i].S.F])%mod,(cury*vt[x][i].S.S)%mod);
		}
	}
	return;
}
int main(){
	ll T,i,j,x,y,z,w;
	inv[1]=1;
	for(i=2;i<N;i++)
	{
		inv[i]=(inv[mod%i]*(mod-mod/i))%mod;
	}
	memset(isprm,true,sizeof(isprm));
	isprm[0]=isprm[1]=false;
	for(i=2;i<=450;i++)
	{
		if(isprm[i])
		{
			allp.push_back(i);
			for(j=i+i;j<=450;j+=i)
			{
				isprm[j]=false;
			}
		}
	}
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			mx[i+1]=cnt[i+1]=pre[i]=0;
			vt[i].clear();
		}
		for(i=1;i<n;i++)
		{
			scanf("%lld%lld%lld%lld",&x,&y,&z,&w);
			x--,y--;
			vt[x].push_back(make_pair(y,make_pair(z,w)));
			vt[y].push_back(make_pair(x,make_pair(w,z)));
		}
		ans=1;
		dfs(0,-1);
		for(i=1;i<=n;i++)
		{
			ans=(ans*ksm(i,mx[i]))%mod;
		}
		res=0;
		dfs2(0,-1,1,1);
		printf("%lld\n",res);
	}
	return 0;
}