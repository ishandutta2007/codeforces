//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 3000010
using namespace std;
int n,m,fa[N],ch[N][2],id[N],cnt=0,ndcnt=0;
bool vis[N];
char buf[10];
vector<pair<pair<ll,ll>,int> > qry;
vector<ll> allv;
vector<int> ans,vt[N];
int getf(int x)
{
	return x==fa[x]?x:fa[x]=getf(fa[x]);
}
void add_seg(int cur,ll l,ll r,ll tl,ll tr)
{
	if(l<=tl&&tr<=r)
	{
		id[cur]=cnt++;
		return;
	}
	ll mid=(tl+tr)>>1;
	if(mid>=l)
	{
		if(ch[cur][0]==-1)
		{
			ch[cur][0]=++ndcnt;
		}
		add_seg(ch[cur][0],l,r,tl,mid);
	}
	if(mid<r)
	{
		if(ch[cur][1]==-1)
		{
			ch[cur][1]=++ndcnt;
		}
		add_seg(ch[cur][1],l,r,mid+1,tr);
	}
	return;
}
void dfs(int l,int r,int curdep,int dest)
{
	if(id[l]!=-1&&id[r]!=-1)
	{
		if(curdep>=dest)
		{
			return;
		}
		vt[id[l]].push_back(id[r]);
		vt[id[r]].push_back(id[l]);
		return;
	}
	if(id[r]!=-1)
	{
		swap(l,r);
	}
	if(id[l]!=-1)
	{
		if(ch[r][0]!=-1)
		{
			dfs(l,ch[r][0],curdep-1,dest);
		}
		if(ch[r][1]!=-1)
		{
			dfs(l,ch[r][1],curdep-1,dest);
		}
		return;
	}
	if(curdep==dest)
	{
		if(l>r)
		{
			swap(l,r);
		}
		if(ch[l][0]!=-1&&ch[r][1]!=-1)
		{
			dfs(ch[l][0],ch[r][1],curdep-1,dest);
		}
		return;
	}
	if(ch[l][0]!=-1&&ch[r][0]!=-1)
	{
		dfs(ch[l][0],ch[r][0],curdep-1,dest);
	}
	if(ch[l][1]!=-1&&ch[r][1]!=-1)
	{
		dfs(ch[l][1],ch[r][1],curdep-1,dest);
	}
	return;
}
int get_bel(ll x)
{
	int cur=0,i;
	for(i=n-1;i>=0;i--)
	{
		if(id[cur]!=-1)
		{
			return id[cur];
		}
		if(x&((ll)1<<i))
		{
			cur=ch[cur][1];
		}
		else
		{
			cur=ch[cur][0];
		}
	}
	return id[cur];
}
void modify(ll l,ll r)
{
	int i,j;
	l=get_bel(l);
	r=get_bel(r);
	for(i=l;i<=r;i++)
	{
		vis[i]=true;
		for(j=0;j<vt[i].size();j++)
		{
			if(vis[vt[i][j]])
			{
				fa[getf(vt[i][j])]=getf(i);
			}
		}
	}
	return;
}
int main(){
	int i;
	ll l,r;
	for(i=0;i<N;i++)
	{
		id[i]=ch[i][0]=ch[i][1]=-1;
		fa[i]=i;
	}
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%s",&buf);
		scanf("%lld%lld",&l,&r);
		if(buf[0]=='a')
		{
			qry.push_back(make_pair(make_pair(l,r),0));
		}
		else
		{
			allv.push_back(l);
			allv.push_back(r);
			qry.push_back(make_pair(make_pair(l,r),1));
		}
	}
	allv.push_back(-1);
	allv.push_back(((ll)1<<n));
	sort(allv.begin(),allv.end());
	ll rt=0;
	for(i=1;i<allv.size();i++)
	{
		if(i&1)
		{
			if(allv[i]-1>=allv[i-1]+1)
			{
				add_seg(0,allv[i-1]+1,allv[i]-1,0,((ll)1<<n)-1);
			}
		}
		else
		{
			add_seg(0,allv[i-1],allv[i],0,((ll)1<<n)-1);
		}
	}
	for(i=0;i<n;i++)
	{
		dfs(0,0,n-1,i);
	}
	for(i=1;i<allv.size();i+=2)
	{
		if(allv[i]-1>=allv[i-1]+1)
		{
			modify(allv[i-1]+1,allv[i]-1);
		}
	}
	reverse(qry.begin(),qry.end());
	for(i=0;i<m;i++)
	{
		if(qry[i].S==0)
		{
			ans.push_back(getf(get_bel(qry[i].F.F))==getf(get_bel(qry[i].F.S)));
		}
		else
		{
			modify(qry[i].F.F,qry[i].F.S);
		}
	}
	reverse(ans.begin(),ans.end());
	for(i=0;i<ans.size();i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}