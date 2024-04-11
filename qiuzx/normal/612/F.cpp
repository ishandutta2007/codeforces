#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 2010
using namespace std;
ll n,st,a[N],dp[N],ans=LINF;
pair<ll,ll> lst[N];//last position , clockwise(0) or counterclockwise(1)
vector<ll> allv,dep[N];
ll getdist(ll x,ll y)//move clockwise from x to y
{
	if(x==2005)
	{
		x=st;
	}
	if(y==2005)
	{
		y=st;
	}
	if(x<=y)
	{
		return y-x;
	}
	return n-(x-y);
}
void print_path(ll ly,ll x)
{
	if(ly<=0)
	{
		return;
	}
	ll chs=lst[x].F,cclo=lst[x].S,i,id,nxt,da,db,md;
	print_path(ly-1,chs);
	for(id=0;id<dep[ly].size();id++)
	{
		if(dep[ly][id]==x)
		{
			break;
		}
	}
	x=id;
	if(cclo)
	{
		nxt=(x+dep[ly].size()-1)%dep[ly].size();
		da=getdist(chs,dep[ly][nxt]);
		db=getdist(dep[ly][nxt],chs);
		md=min(da,db);
		if(md==da)
		{
			printf("+%lld\n",md);
		}
		else
		{
			printf("-%lld\n",md);
		}
		while(nxt!=x)
		{
			i=(nxt+dep[ly].size()-1)%dep[ly].size();
			printf("-%lld\n",getdist(dep[ly][i],dep[ly][nxt]));
			nxt=i;
		}
	}
	else
	{
		nxt=(x+1)%dep[ly].size();
		da=getdist(chs,dep[ly][nxt]);
		db=getdist(dep[ly][nxt],chs);
		md=min(da,db);
		if(md==da)
		{
			printf("+%lld\n",md);
		}
		else
		{
			printf("-%lld\n",md);
		}
		while(nxt!=x)
		{
			i=(nxt+1)%dep[ly].size();
			printf("+%lld\n",getdist(dep[ly][nxt],dep[ly][i]));
			nxt=i;
		}
	}
	return;
}
int main(){
	ll i,j,k,x,y,nxt,upd;
	scanf("%lld%lld",&n,&st);
	st--;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		allv.push_back(a[i]);
	}
	sort(allv.begin(),allv.end());
	allv.erase(unique(allv.begin(),allv.end()),allv.end());
	for(i=0;i<n;i++)
	{
		a[i]=lower_bound(allv.begin(),allv.end(),a[i])-allv.begin()+1;
		dep[a[i]].push_back(i);
	}
	memset(dp,63,sizeof(dp));
	dp[2005]=0;
	dep[0].push_back(2005);
	for(i=0;i<allv.size();i++)
	{
		for(j=0;j<dep[i].size();j++)
		{
			x=dep[i][j];
			for(k=0;k<dep[i+1].size();k++)
			{
				y=dep[i+1][k];
				//x->y+1->...->y
				nxt=dep[i+1][(k+1)%(dep[i+1].size())];
				upd=min(getdist(nxt,x),getdist(x,nxt))+getdist(nxt,y);
				if(dp[y]>dp[x]+upd)
				{
					dp[y]=dp[x]+upd;
					lst[y]=make_pair(x,0);
				}
				//x->y-1->...->y
				nxt=dep[i+1][(k+dep[i+1].size()-1)%(dep[i+1].size())];
				upd=min(getdist(nxt,x),getdist(x,nxt))+getdist(y,nxt);
				if(dp[y]>dp[x]+upd)
				{
					dp[y]=dp[x]+upd;
					lst[y]=make_pair(x,1);
				}
			}
		}
	}
	for(i=0;i<dep[allv.size()].size();i++)
	{
		if(ans>dp[dep[allv.size()][i]])
		{
			ans=dp[dep[allv.size()][i]];
			x=dep[allv.size()][i];
		}
	}
	printf("%lld\n",ans);
	print_path(allv.size(),x);
	return 0;
}