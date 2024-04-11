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
#define N 500010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
struct SegT{
	ll lo[N<<2],hi[N<<2],val[N<<2],pd[N<<2];
	void build(ll x,ll l,ll r)
	{
		lo[x]=l,hi[x]=r,val[x]=pd[x]=0;
		if(l==r)
		{
			return;
		}
		ll mid=(l+r)>>1,a=x<<1;
		build(a,l,mid);
		build(a|1,mid+1,r);
		return;
	}
	void push_down(ll x)
	{
		ll a=x<<1;
		val[a]+=pd[x],pd[a]+=pd[x];
		val[a|1]+=pd[x],pd[a|1]+=pd[x];
		pd[x]=0;
		return;
	}
	void update(ll x,ll l,ll r,ll v)
	{
		if(l>r)
		{
			return;
		}
		ll tl=lo[x],tr=hi[x];
		if(tl<tr)
		{
			push_down(x);
		}
		if(l<=tl&&tr<=r)
		{
			val[x]+=v;
			pd[x]+=v;
			if(tl<tr)
			{
				push_down(x);
			}
			return;
		}
		ll mid=(tl+tr)>>1,a=x<<1;
		if(mid>=l)
		{
			update(a,l,r,v);
		}
		if(mid<r)
		{
			update(a|1,l,r,v);
		}
		val[x]=min(val[a],val[a|1]);
		return;
	}
}segt;
ll n,k,h[N],s[N],pos[N],mnid[N],mnid2[N],len[N];
vector<ll> vt[N],trs[N];
void dfs(ll x,ll lst)
{
	if(mnid[x]==-1)
	{
		mnid[x]=x;
	}
	else if(h[mnid[x]]>h[x])
	{
		mnid2[x]=mnid[x];
		mnid[x]=x;
	}
	else if(mnid2[x]==-1||h[mnid2[x]]>h[x])
	{
		mnid2[x]=x;
	}
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			mnid[vt[x][i]]=mnid[x];
			mnid2[vt[x][i]]=mnid2[x];
			dfs(vt[x][i],x);
		}
	}
	return;
}
int main(){
	ll i,j;
	n=rint();
	for(i=0;i<n;i++)
	{
		h[i]=rint();
		mnid[i]=mnid2[i]=-1;
	}
	for(i=1;i<n;i++)
	{
		ll x=rint()-1,y=rint()-1;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	k=rint();
	for(i=0;i<k;i++)
	{
		s[i]=rint();
	}
	sort(s,s+k);
	for(i=0;i<n;i++)
	{
		pos[i]=upper_bound(s,s+k,h[i])-s;
	}
	dfs(0,-1);
	for(i=0;i<n;i++)
	{
		trs[mnid[i]].push_back(i);
		len[pos[mnid[i]]+1]--;
	}
	len[1]+=n;
	segt.build(1,1,k);
	for(i=1;i<=k;i++)
	{
		len[i]+=len[i-1];
		segt.update(1,i,i,i+len[i]);
	}
	if(segt.val[1]>k)
	{
		puts("0");
		return 0;
	}
	for(i=k;i>0;i--)
	{
		if(i+len[i]<=k)
		{
			break;
		}
	}
	ll id=i;
	ll ans=LINF;
	for(i=0;i<n;i++)
	{
		if(h[i]<s[id-1])
		{
			for(j=0;j<trs[i].size();j++)
			{
				segt.update(1,1,pos[i],-1);
				segt.update(1,1,(mnid2[trs[i][j]]==-1)?id:pos[mnid2[trs[i][j]]],1);
			}
			if(segt.val[1]>k)
			{
				ans=min(ans,s[id-1]-h[i]);
			}
			for(j=0;j<trs[i].size();j++)
			{
				segt.update(1,1,pos[i],1);
				segt.update(1,1,(mnid2[trs[i][j]]==-1)?id:pos[mnid2[trs[i][j]]],-1);
			}
		}
	}
	if(ans>INF)
	{
		ans=-1;
	}
	printf("%lld\n",ans);
	return 0;
}