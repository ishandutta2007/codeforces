#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 8000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 50010
using namespace std;
int n,m,fa[N],G,S,g[N],s[N];
ll ans=LINF;
vector<pair<pair<int,int>,pair<int,int> > > ed;
vector<pair<int,int> > ned;
bool cmp(pair<pair<int,int>,pair<int,int> > a,pair<pair<int,int>,pair<int,int> > b)
{
	if(a.S.F<b.S.F)
	{
		return true;
	}
	return false;
}
void init_fa()
{
	int i;
	for(i=0;i<n;i++)
	{
		fa[i]=i;
	}
	return;
}
int getf(int x)
{
	if(x==fa[x])
	{
		return x;
	}
	return fa[x]=getf(fa[x]);
}
ll calc(int wg) 
{
	init_fa();
	int i,a,b,ws=0;
	for(i=0;i<ned.size();i++)
	{
		a=getf(ed[ned[i].S].F.F);
		b=getf(ed[ned[i].S].F.S);
		if(a==b)
		{
			ned.erase(ned.begin()+i);
			i--;
			continue;
		}
		fa[b]=a;
		ws=max(ws,ned[i].F);
	}
	if(ned.size()==n-1)
	{
		return (ll)wg*G+(ll)ws*S;
	}
	return LINF;
}
void add_edge(int x)
{
	ned.push_back(make_pair(ed[x].S.S,x));
	ll i;
	for(i=ned.size()-1;i>0;i--)
	{
		if(ned[i]>=ned[i-1])
		{
			break;
		}
		swap(ned[i],ned[i-1]);
	}
	ans=min(ans,calc(ed[x].S.F));
	return;
}
int main(){
	int i,x,y;
	scanf("%d%d%d%d",&n,&m,&G,&S);
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d%d",&x,&y,&g[i],&s[i]);
		x--;
		y--;
		if(x==y)
		{
			continue;
		}
		ed.push_back(make_pair(make_pair(x,y),make_pair(g[i],s[i])));
	}
	sort(ed.begin(),ed.end(),cmp);
	if(ed.size()<n-1)
	{
		puts("-1");
		return 0;
	}
	for(i=0;i<ed.size();i++)
	{
		add_edge(i);
	}
	if(ans>=LINF)
	{
		puts("-1");
		return 0;
	}
	printf("%lld\n",ans);
	return 0;
}