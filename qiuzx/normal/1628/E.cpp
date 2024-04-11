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
#define ll int
#define N 600010
using namespace std;
struct SegT{
	ll mn[N<<2],mx[N<<2];
	void update(ll x,ll l,ll tl,ll tr,ll v)
	{
		if(l==tl&&tr==l)
		{
			mn[x]=mx[x]=v;
			return;
		}
		ll mid=(tl+tr)>>1,a=x<<1;
		if(mid>=l)
		{
			update(a,l,tl,mid,v);
		}
		if(mid<l)
		{
			update(a|1,l,mid+1,tr,v);
		}
		mn[x]=min(mn[a],mn[a|1]);
		mx[x]=max(mx[a],mx[a|1]);
		return;
	}
}prec;
struct SegmentTree{
	ll lo[N<<2],hi[N<<2],mnv[N<<2],mxv[N<<2],pd[N<<2];
	void build(ll x,ll l,ll r)
	{
		lo[x]=l,hi[x]=r;
		mnv[x]=INF,mxv[x]=-INF,pd[x]=0;
		if(l==r)
		{
			return;
		}
		ll mid=(l+r)>>1,a=x<<1;
		build(a,l,mid);
		build(a|1,mid+1,r);
	}
	void push_down(ll x)
	{
		ll a=x<<1;
		if(pd[x]==1)
		{
			mnv[a]=prec.mn[a],mnv[a|1]=prec.mn[a|1];
			mxv[a]=prec.mx[a],mxv[a|1]=prec.mx[a|1];
			pd[a]=pd[a|1]=1;
		}
		else if(pd[x]==-1)
		{
			mnv[a]=mnv[a|1]=INF;
			mxv[a]=mxv[a|1]=-INF;
			pd[a]=pd[a|1]=-1;
		}
		pd[x]=0;
		return;
	}
	void update(ll x,ll l,ll r)
	{
		ll tl=lo[x],tr=hi[x];
		if(l<=tl&&tr<=r)
		{
			mnv[x]=prec.mn[x];
			mxv[x]=prec.mx[x];
			pd[x]=1;
			if(tl!=tr)
			{
				push_down(x);
			}
			return;
		}
		push_down(x);
		ll mid=(tl+tr)>>1,a=x<<1;
		if(mid>=l)
		{
			update(a,l,r);
		}
		if(mid<r)
		{
			update(a|1,l,r);
		}
		mnv[x]=min(mnv[a],mnv[a|1]);
		mxv[x]=max(mxv[a],mxv[a|1]);
		return;
	}
	void recall(ll x,ll l,ll r)
	{
		ll tl=lo[x],tr=hi[x];
		if(l<=tl&&tr<=r)
		{
			mnv[x]=INF;
			mxv[x]=-INF;
			pd[x]=-1;
			if(tl!=tr)
			{
				push_down(x);
			}
			return;
		}
		push_down(x);
		ll mid=(tl+tr)>>1,a=x<<1;
		if(mid>=l)
		{
			recall(a,l,r);
		}
		if(mid<r)
		{
			recall(a|1,l,r);
		}
		mnv[x]=min(mnv[a],mnv[a|1]);
		mxv[x]=max(mxv[a],mxv[a|1]);
		return;
	}
}segt;
ll n,q,val[N],fa[N],f[N][21],dep[N],curcnt=0,dfn[N],id[N];
vector<pair<ll,pair<ll,ll> > > ed;
vector<ll> vt[N];
ll getf(ll x){return x==fa[x]?x:fa[x]=getf(fa[x]);}
void dfs(ll x,ll d)
{
	ll i;
	if(vt[x].size()==0)
	{
		dfn[x]=++curcnt;
		id[curcnt]=x;
	}
	dep[x]=d;
	for(i=1;i<=20;i++)
	{
		f[x][i]=f[f[x][i-1]][i-1];
	}
	for(i=0;i<vt[x].size();i++)
	{
		f[vt[x][i]][0]=x;
		dfs(vt[x][i],d+1);
	}
	return;
}
ll glca(ll x,ll y)
{
	if(dep[x]<dep[y])
	{
		swap(x,y);
	}
	ll i;
	for(i=20;i>=0;i--)
	{
		if(dep[f[x][i]]>=dep[y])
		{
			x=f[x][i];
		}
	}
	if(x==y)
	{
		return x;
	}
	for(i=20;i>=0;i--)
	{
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int main(){
	ll i,j,x,y,z,cnt,tp;
	scanf("%d%d",&n,&q);
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		x--,y--;
		ed.push_back(make_pair(z,make_pair(x,y)));
	}
	sort(ed.begin(),ed.end());
	cnt=n;
	for(i=0;i<2*n;i++)
	{
		fa[i]=i;
	}
	for(i=0;i<ed.size();i++)
	{
		val[cnt]=ed[i].F;
		x=getf(ed[i].S.F),y=getf(ed[i].S.S);
		vt[cnt].push_back(x);
		vt[cnt].push_back(y);
		fa[x]=fa[y]=cnt++;
	}
	for(i=0;i<cnt;i++)
	{
		for(j=0;j<=20;j++)
		{
			f[i][j]=cnt-1;
		}
	}
	dfs(cnt-1,0);
	segt.build(1,0,n-1);
	for(i=0;i<n;i++)
	{
		prec.update(1,i,0,n-1,dfn[i]);
	}
	while(q--)
	{
		scanf("%d",&tp);
		if(tp==1)
		{
			scanf("%d%d",&x,&y);
			segt.update(1,x-1,y-1);
		}
		else if(tp==2)
		{
			scanf("%d%d",&x,&y);
			segt.recall(1,x-1,y-1);
		}
		else
		{
			scanf("%d",&x);
			x--;
			y=segt.mnv[1];
			z=segt.mxv[1];
			if(y>=INF||z<0)
			{
				puts("-1");
				continue;
			}
			y=id[y],z=id[z];
			if(y==x&&z==x)
			{
				puts("-1");
				continue;
			}
			printf("%d\n",max(val[glca(x,y)],val[glca(x,z)]));
		}
	}
	return 0;
}