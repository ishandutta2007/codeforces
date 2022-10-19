#pragma GCC optimize(2)
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
#define ll int
#define N 100010
using namespace std;
ll n,m,h,t,hs[N],res[N];
vector<ll> vt[N],res1,res2,res3;
vector<pair<ll,ll> > ed;
bool check(ll x,ll y)
{
	ll i,on=0,tw=0,on2=0;
	for(i=0;i<vt[x].size();i++)
	{
		hs[vt[x][i]]=0;
	}
	for(i=0;i<vt[y].size();i++)
	{
		hs[vt[y][i]]=0;
	}
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=y)
		{
			hs[vt[x][i]]++;
			on++;
		}
	}
	for(i=0;i<vt[y].size();i++)
	{
		if(vt[y][i]!=x)
		{
			hs[vt[y][i]]++;
			on2++;
			if(hs[vt[y][i]]==2)
			{
				on--;
				on2--;
				tw++;
			}
		}
	}
	if(on+tw>=h&&on2+tw>=t&&on+tw+on2>=h+t)
	{
		return true;
	}
	if(on+tw>=t&&on2+tw>=h&&on+tw+on2>=h+t)
	{
		return true;
	}
	return false;
}
bool ok(ll a,ll b,ll c)
{
	ll req=max((ll)0,h-a);
	if(c<req)
	{
		return false;
	}
	c-=req;
	if(b+c>=t)
	{
		return true;
	}
	return false;
}
void print(ll x,ll y)
{
	ll i,j;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=y)
		{
			res[vt[x][i]]|=1;
		}
	}
	for(i=0;i<vt[y].size();i++)
	{
		if(vt[y][i]!=x)
		{
			res[vt[y][i]]|=2;
		}
	}
	for(i=0;i<n;i++)
	{
		if(res[i]==1)
		{
			res1.push_back(i);
		}
		else if(res[i]==2)
		{
			res2.push_back(i);
		}
		else if(res[i]==3)
		{
			res3.push_back(i);
		}
	}
	if(ok(res1.size(),res2.size(),res3.size()))
	{
		printf("%d %d\n",x+1,y+1);
		i=0;
		while(res1.size()<h)
		{
			res1.push_back(res3[i++]);
		}
		while(res2.size()<t)
		{
			res2.push_back(res3[i++]);
		}
		for(i=0;i<h;i++)
		{
			printf("%d ",res1[i]+1);
		}
		puts("");
		for(i=0;i<t;i++)
		{
			printf("%d ",res2[i]+1);
		}
		puts("");
		return;
	}
	printf("%d %d\n",y+1,x+1);
	i=0;
	while(res2.size()<h)
	{
		res2.push_back(res3[i++]);
	}
	while(res1.size()<t)
	{
		res1.push_back(res3[i++]);
	}
	for(i=0;i<h;i++)
	{
		printf("%d ",res2[i]+1);
	}
	puts("");
	for(i=0;i<t;i++)
	{
		printf("%d ",res1[i]+1);
	}
	puts("");
	return;
}
int main(){
	ll i,j,x,y,sza,szb;
	scanf("%d%d%d%d",&n,&m,&h,&t);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		x--;
		y--;
		vt[x].push_back(y);
		vt[y].push_back(x);
		ed.push_back(make_pair(x,y));
	}
	for(i=0;i<ed.size();i++)
	{
		x=ed[i].F;
		y=ed[i].S;
		sza=vt[x].size()-1;
		szb=vt[y].size()-1;
		if(sza<min(h,t)||szb<min(h,t))
		{
			continue;
		}
		if(sza>=h+t||szb>=h+t)
		{
			puts("YES");
			print(x,y);
			return 0;
		}
		if(check(x,y))
		{
			puts("YES");
			print(x,y);
			return 0;
		}
	}
	puts("NO");
	return 0;
}