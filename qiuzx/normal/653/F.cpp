#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll int
#define N 1000010
using namespace std;
struct Node{
	ll trs[3],par,mx;
}sam[N];
void init(ll id)
{
	memset(sam[id].trs,-1,sizeof(sam[id].trs));
	sam[id].par=-1;
	sam[id].mx=0;
	return;
}
vector<ll> vt[N];
ll n,lst=0,cnt=0,f[N],rt[N],hei[N],mxext[N];
long long ans=0;
vector<ll> hv[N];
vector<ll> null;
string s;
char buf[N];
void addsam(ll i)
{
	cnt++;
	init(cnt);
	sam[cnt].mx=sam[lst].mx+1;
	rt[cnt]=i;
	f[cnt]=1;
	ll p=lst,q,nq;
	while(p!=-1)
	{
		if(sam[p].trs[s[i]-'(']!=-1)
		{
			break;
		}
		sam[p].trs[s[i]-'(']=cnt;
		p=sam[p].par;
	}
	lst=cnt;
	if(p==-1)
	{
		sam[cnt].par=0;
		return;
	}
	q=sam[p].trs[s[i]-'('];
	if(sam[q].mx==sam[p].mx+1)
	{
		sam[cnt].par=q;
	}
	else
	{
		nq=cnt+1;
		sam[nq]=sam[q];
		sam[nq].mx=sam[p].mx+1;
		sam[q].par=nq;
		sam[cnt].par=nq;
		while(p!=-1)
		{
			if(sam[p].trs[s[i]-'(']!=q)
			{
				break;
			}
			sam[p].trs[s[i]-'(']=nq;
			p=sam[p].par;
		}
		cnt++;
	}
	return;
}
void dfs(ll x)
{
	ll i,mx,mn,res;
	for(i=0;i<vt[x].size();i++)
	{
		dfs(vt[x][i]);
		rt[x]=rt[vt[x][i]];
	}
	mn=max(mxext[rt[x]],rt[x]-sam[x].mx+1);
	mx=rt[x]-((sam[x].par==-1)?1:sam[sam[x].par].mx+1)+1;
	if(mn>mx)
	{
		res=0;
	}
	else
	{
		res=upper_bound(hv[hei[rt[x]+1]].begin(),hv[hei[rt[x]+1]].end(),mx)-lower_bound(hv[hei[rt[x]+1]].begin(),hv[hei[rt[x]+1]].end(),mn);
	}
	ans+=(long long)res;
	return;
}
struct SegT{
	ll l,r,v;
}segt[N*4];
void build_tree(ll x,ll l,ll r)
{
	segt[x].l=l;
	segt[x].r=r;
	segt[x].v=-1;
	if(l==r)
	{
		return;
	}
	ll mid=(l+r)>>1,a=x<<1;
	build_tree(a,l,mid);
	build_tree(a|1,mid+1,r);
	return;
}
void update(ll x,ll l,ll v)
{
	ll tl=segt[x].l,tr=segt[x].r;
	if(tl>l||tr<l)
	{
		return;
	}
	if(l==tl&&tr==l)
	{
		segt[x].v=max(segt[x].v,v);
		return;
	}
	ll mid=(tl+tr)>>1,a=x<<1;
	if(mid>=l)
	{
		update(a,l,v);
	}
	else
	{
		update(a|1,l,v);
	}
	segt[x].v=max(segt[a].v,segt[a|1].v);
	return;
}
ll qry(ll x,ll l,ll r)
{
	ll tl=segt[x].l,tr=segt[x].r;
	if(tl>r||tr<l)
	{
		return -1;
	}
	if(l<=tl&&tr<=r)
	{
		return segt[x].v;
	}
	ll mid=(tl+tr)>>1,a=x<<1,ret=-1;
	if(mid>=l)
	{
		ret=max(ret,qry(a,l,r));
	}
	if(mid<r)
	{
		ret=max(ret,qry(a|1,l,r));
	}
	return ret;
}
int main(){
	ll i,d;
	scanf("%d",&n);
	scanf("%s",&buf);
	s=buf;
	null.clear();
	hei[0]=d=n+1;
	build_tree(1,0,2*n+1);
	update(1,d,0);
	for(i=0;i<s.size();i++)
	{
		hv[d].push_back(i);
		if(s[i]=='(')
		{
			d++;
		}
		else
		{
			d--;
		}
		hei[i+1]=d;
		update(1,hei[i+1],i+1);
		mxext[i]=qry(1,0,hei[i+1]-1)+1;
	}
	init(0);
	for(i=0;i<s.size();i++)
	{
		addsam(i);
	}
	for(i=0;i<=cnt;i++)
	{
		if(sam[i].par!=-1)
		{
			vt[sam[i].par].push_back(i);
		}
	}
	dfs(0);
	printf("%lld\n",ans);
	return 0;
}