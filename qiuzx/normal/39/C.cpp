#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 2010
using namespace std;
int n,in[N],out[N],pt[N];
vector<int> ans[N];
vector<pair<pair<int,int>,int> > cir;
int rint(){
	int ret=0,uu=1;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') uu=-1,c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret*uu;
}
bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b)
{
	if(a.F.S>b.F.S)
	{
		return false;
	}
	if(a.F.S<b.F.S)
	{
		return true;
	}
	if(a.F.F>b.F.F)
	{
		return true;
	}
	return false;
}
void getans(int x)
{
	int i,j,mx=-1,tm=-1;
	vector<pair<pair<int,int>,int> > si;
	for(i=0;i<x;i++)
	{
		if(cir[x].F.F<=cir[i].F.F&&cir[i].F.S<=cir[x].F.S)
		{
			si.push_back(cir[i]);
		}
	}
	for(i=0;i<si.size();i++)
	{
		in[i]=0;
		pt[i]=-1;
		for(j=0;j<i;j++)
		{
			if(si[i].F.F>=si[j].F.S)
			{
				if(in[i]<in[j])
				{
					in[i]=in[j];
					pt[i]=j;
				}
			}
		}
		in[i]+=out[si[i].S];
	}
	for(i=0;i<si.size();i++)
	{
		if(in[i]>mx)
		{
			mx=in[i];
			tm=i;
		}
	}
	while(tm>=0)
	{
		for(i=0;i<ans[si[tm].S].size();i++)
		{
			ans[cir[x].S].push_back(ans[si[tm].S][i]);
		}
		tm=pt[tm];
	}
	if(cir[x].S!=n)
	{
		ans[cir[x].S].push_back(cir[x].S);
	}
	out[cir[x].S]=ans[cir[x].S].size();
	return;
}
int main()
{
	int i,c,r;
	n=rint();
	cir.push_back(make_pair(make_pair(-2000000000,2000000000),n));
	for(i=0;i<n;i++)
	{
		c=rint();
		r=rint();
		cir.push_back(make_pair(make_pair(c-r,c+r),i));
	}
	sort(cir.begin(),cir.end(),cmp);
	for(i=0;i<=n;i++)
	{
		getans(i);
	}
	printf("%d\n",ans[n].size());
	for(i=0;i<ans[n].size();i++)
	{
		printf("%d ",ans[n][i]+1);
	}
	puts("");
	return 0;
}