#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 1005
using namespace std;
int n,p,mnp,mxp,vx,vy,a[N][N];
ll ans=0;
pair<int,int> pos;
vector<pair<int,int> > ord;
struct Segt{
	int pd,val;
}segt[4*N*N];
bool cmp(pair<int,int> a,pair<int,int> b)
{
	ll ay=((ll)a.S*vx-vy*(ll)a.F)*vx;
	ll by=((ll)b.S*vx-vy*(ll)b.F)*vx;
	if(ay>by)
	{
		return true;
	}
	return false;
}
void spc1()
{
	ll ans=0;
	int i,j,mx;
	for(i=0;i<n;i++)
	{
		mx=0;
		if(vy>0)
		{
			for(j=0;j<n;j++)
			{
				ans+=(ll)max(0,a[i][j]-mx);
				mx=max(mx,a[i][j]);
			}
		}
		else
		{
			for(j=n-1;j>=0;j--)
			{
				ans+=(ll)max(0,a[i][j]-mx);
				mx=max(mx,a[i][j]);
			}
		}
	}
	printf("%lld\n",ans);
	return;
}
void spc2()
{
	ll ans=0;
	int i,j,mx;
	for(i=0;i<n;i++)
	{
		mx=0;
		if(vy>0)
		{
			for(j=0;j<n;j++)
			{
				ans+=(ll)max(0,a[j][i]-mx);
				mx=max(mx,a[j][i]);
			}
		}
		else
		{
			for(j=n-1;j>=0;j--)
			{
				ans+=(ll)max(0,a[j][i]-mx);
				mx=max(mx,a[j][i]);
			}
		}
	}
	printf("%lld\n",ans);
	return;
}
void build_tree(int l,int r,int x)
{
	if(l>r)
	{
		return;
	}
	segt[x].pd=0;
	segt[x].val=INF+7;
	if(l==r)
	{
		return;
	}
	int mid=(l+r)>>1,a=x<<1;
	build_tree(l,mid,a);
	build_tree(mid+1,r,(a|1));
	return;
}
void push_down(int x)
{
	int a=(x<<1);
	segt[a].pd=max(segt[a].pd,segt[x].pd);
	segt[a|1].pd=max(segt[a|1].pd,segt[x].pd);
	return;
}
int query(int l,int r,int tl,int tr,int x)
{
	if(l>tr||r<tl)
	{
		return INF+7;
	}
	if(tl!=tr)
	{
		push_down(x);
	}
	if(segt[x].val==INF+7||segt[x].val<segt[x].pd)
	{
		segt[x].val=segt[x].pd;
	}
	segt[x].pd=0;
	if(l<=tl&&tr<=r)
	{
		return segt[x].val;
	}
	int mid=(tl+tr)>>1,a=x<<1,ret=INF+7;
	if(mid>=l)
	{
		ret=min(ret,query(l,r,tl,mid,a));
	}
	if(mid<r)
	{
		ret=min(ret,query(l,r,mid+1,tr,a|1));
	}
	return ret;
}
void update(int l,int r,int tl,int tr,int x,int v)
{
	if(l>tr||r<tl)
	{
		return;
	}
	if(l<=tl&&tr<=r)
	{
		segt[x].pd=max(segt[x].pd,v);
		if(tl!=tr)
		{
			push_down(x);
		}
		if(segt[x].val==INF+7||segt[x].val<segt[x].pd)
		{
			segt[x].val=segt[x].pd;
		}
		segt[x].pd=0;
		return;
	}
	if(tl!=tr)
	{
		push_down(x);
	}
	if(segt[x].val==INF+7||segt[x].val<segt[x].pd)
	{
		segt[x].val=segt[x].pd;
	}
	segt[x].pd=0;
	int mid=(tl+tr)>>1,a=x<<1;
	if(mid>=l)
	{
		update(l,r,tl,mid,a,v);
	}
	if(mid<r)
	{
		update(l,r,mid+1,tr,a|1,v);
	}
	if(segt[a].val==INF+7||segt[a|1].val==INF+7)
	{
		segt[x].val=INF+7;
	}
	else
	{
		segt[x].val=min(segt[a].val,segt[a|1].val);
	}
	return;
}
void run1()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			pos=make_pair(i,j+1);
			mnp=lower_bound(ord.begin(),ord.end(),pos,cmp)-ord.begin();
			pos=make_pair(i+1,j);
			mxp=lower_bound(ord.begin(),ord.end(),pos,cmp)-ord.begin();
			ans+=(ll)max(0,a[i][j]-query(mnp+1,mxp,1,ord.size()-1,1));
			update(mnp+1,mxp,1,ord.size()-1,1,a[i][j]);
		}
	}
	printf("%lld\n",ans);
	return;
}
void run2()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>=0;j--)
		{
			pos=make_pair(i,j);
			mxp=lower_bound(ord.begin(),ord.end(),pos,cmp)-ord.begin();
			pos=make_pair(i+1,j+1);
			mnp=lower_bound(ord.begin(),ord.end(),pos,cmp)-ord.begin();
			ans+=(ll)max(0,a[i][j]-query(mnp+1,mxp,1,ord.size()-1,1));
			update(mnp+1,mxp,1,ord.size()-1,1,a[i][j]);
		}
	}
	printf("%lld\n",ans);
	return;
}
void run3()
{
	int i,j;
	for(i=n-1;i>=0;i--)
	{
		for(j=0;j<n;j++)
		{
			pos=make_pair(i,j);
			mxp=lower_bound(ord.begin(),ord.end(),pos,cmp)-ord.begin();
			pos=make_pair(i+1,j+1);
			mnp=lower_bound(ord.begin(),ord.end(),pos,cmp)-ord.begin();
			ans+=(ll)max(0,a[i][j]-query(mnp+1,mxp,1,ord.size()-1,1));
			update(mnp+1,mxp,1,ord.size()-1,1,a[i][j]);
		}
	}
	printf("%lld\n",ans);
	return;
}
void run4()
{
	int i,j;
	for(i=n-1;i>=0;i--)
	{
		for(j=n-1;j>=0;j--)
		{
			pos=make_pair(i,j+1);
			mnp=lower_bound(ord.begin(),ord.end(),pos,cmp)-ord.begin();
			pos=make_pair(i+1,j);
			mxp=lower_bound(ord.begin(),ord.end(),pos,cmp)-ord.begin();
			ans+=(ll)max(0,a[i][j]-query(mnp+1,mxp,1,ord.size()-1,1));
			update(mnp+1,mxp,1,ord.size()-1,1,a[i][j]);
		}
	}
	printf("%lld\n",ans);
	return;
}
int main(){
	int i,j;
	scanf("%d%d%d",&n,&vx,&vy);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	if(vx==0)
	{
		spc1();
		return 0;
	}
	if(vy==0)
	{
		spc2();
		return 0;
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			ord.push_back(make_pair(i,j));
		}
	}
	sort(ord.begin(),ord.end(),cmp);
	build_tree(1,ord.size()-1,1);
	if(vx>0&&vy>0)
	{
		run1();
		return 0;
	}
	if(vx>0&&vy<0)
	{
		run2();
		return 0;
	}
	if(vx<0&&vy>0)
	{
		run3();
		return 0;
	}
	if(vx<0&&vy<0)
	{
		run4();
		return 0;
	}
	return 0;
}