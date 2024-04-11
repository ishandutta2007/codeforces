#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 17810
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
struct Edge{
	ll v,bkid,cap,cost;
};
struct Flow{
	vector<Edge> vt[N];
	ll n,m,s,t,dep[N],cur[N],totcost;
	bool vis[N],inq[N];
	void init(ll _n)
	{
		n=_n,m=0,s=_n-2,t=_n-1;
		ll i;
		for(i=0;i<n;i++)
		{
			vt[i].clear();
		}
		return;
	}
	void addedge(ll x,ll y,ll w,ll c)
	{
		Edge cur;
		cur.v=y,cur.bkid=vt[y].size(),cur.cap=w,cur.cost=c;
		vt[x].push_back(cur);
		cur.v=x,cur.bkid=vt[x].size()-1,cur.cap=0,cur.cost=-c;
		vt[y].push_back(cur);
		return;
	}
	bool spfa()
	{
		queue<ll> q;
		ll i,x,w;
		for(i=0;i<n;++i)
		{
			dep[i]=INF;
		}
		q.push(s);
		dep[s]=0;
		while(!q.empty())
		{
			x=q.front();
			inq[x]=false;
			q.pop();
			for(i=0;i<vt[x].size();i++)
			{
				if(vt[x][i].cap>0&&dep[vt[x][i].v]>dep[x]+vt[x][i].cost)
				{
					dep[vt[x][i].v]=dep[x]+vt[x][i].cost;
					if(!inq[vt[x][i].v])
					{
						q.push(vt[x][i].v);
					}
				}
			}
		}
		return (dep[t]<INF);
	}
	ll dfs(ll x,ll lft)
	{
		vis[x]=true;
		if(x==t||lft<=0)
		{
			return lft;
		}
		ll i,v,ret=0;
		for(i=cur[x];i<vt[x].size();++i,++cur[x])
		{
			if((!vis[vt[x][i].v])&&vt[x][i].cap>0&&dep[vt[x][i].v]==dep[x]+vt[x][i].cost)
			{
				v=dfs(vt[x][i].v,min(lft,vt[x][i].cap));
				totcost+=v*vt[x][i].cost;
				ret+=v;
				vt[x][i].cap-=v;
				vt[vt[x][i].v][vt[x][i].bkid].cap+=v;
				lft-=v;
				if(lft<=0)
				{
					break;
				}
			}
		}
		return ret;
	}
	pair<ll,ll> min_cost_max_flow()
	{
		ll ret=0,i;
		totcost=0;
		while(spfa())
		{
			for(i=0;i<n;++i)
			{
				vis[i]=0;
				cur[i]=0;
			}
			ret+=dfs(s,INF);
		}
		return make_pair(ret,totcost);
	}
}fl;
ll n,a[N],b[N],cnt[N],ord[N],sum[N],des[N],mxid[N],curtime,idx[N],tp;
pair<ll,ll> rg[N];
bool vis[N];
bool cmp(ll x,ll y)
{
	return (b[x]+a[x]*curtime==b[y]+a[y]*curtime)?(tp?(a[x]<a[y]):(x<y)):(b[x]+a[x]*curtime>b[y]+a[y]*curtime);
}
bool check(ll x)
{
	curtime=x;
	ll i,j;
	for(i=0;i<2*n;++i)
	{
		ord[i]=i;
		cnt[i]=0;
	}
	for(i=0;i<n;++i)
	{
		ll id=-1;
		for(j=0;j<2*n;++j)
		{
			if(b[i]>=b[j]||b[i]+x*a[i]>=b[j]+x*a[j])
			{
				if(id==-1||b[j]+x*a[j]>b[id]+x*a[id])
				{
					id=j;
				}
			}
		}
		++cnt[id];
	}
	sort(ord,ord+2*n,cmp);
	ll cur=0,num=0;
	for(i=0;i<2*n;++i)
	{
		num+=(ord[i]>=n);
		cur+=cnt[ord[i]];
		if(cur<num)
		{
			return false;
		}
	}
	return true;
}
ll calc(ll x)
{
	ll i,j;
	curtime=0;
	for(i=0;i<2*n;++i)
	{
		ord[i]=i;
	}
	fl.init(n*8+2);
	tp=1;
	sort(ord,ord+2*n,cmp);
	for(i=0;i<2*n;++i)
	{
		fl.addedge(ord[i]*4,i*4+1,INF,1);
		fl.addedge(i*4+1,ord[i]*4,INF,0);
		if(ord[i]<n)
		{
			fl.addedge(fl.s,ord[i]*4,1,0);
		}
		if(i+1<2*n)
		{
			fl.addedge(i*4+1,(i+1)*4+1,INF,0);
		}
	}
	curtime=x;
	tp=0;
	for(i=0;i<2*n;++i)
	{
		ord[i]=i;
	}
	sort(ord,ord+2*n,cmp);
	for(i=0;i<2*n;++i)
	{
		fl.addedge(ord[i]*4+2,i*4+3,INF,1);
		fl.addedge(i*4+3,ord[i]*4+2,INF,0);
		if(ord[i]>=n)
		{
			fl.addedge(ord[i]*4+2,fl.t,1,0);
		}
		if(i+1<2*n)
		{
			fl.addedge(i*4+3,(i+1)*4+3,INF,0);
		}
	}
	for(i=0;i<2*n;++i)
	{
		fl.addedge(i*4,i*4+2,INF,0);
	}
	return fl.min_cost_max_flow().S;
}
int main(){
	ll i,l,r,mid;
	n=rint();
	for(i=0;i<2*n;++i)
	{
		a[i]=rint(),b[i]=rint();
	}
	l=0,r=INF*(ll)2;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	if(l==(ll)2*INF)
	{
		puts("-1");
		return 0;
	}
	printf("%lld %lld\n",l,calc(l));
	return 0;
}