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
#define ll long long
#define N 2010
using namespace std;
int n,m,a[N],b[N],c[N],d[N],tg[1000010],dep[1000010],tp[N],ans;
vector<int> cge;
vector<pair<int,int> > wt;
multiset<int> nd;
bool cmp(pair<int,int> a,pair<int,int> x)
{
	if(max(0,a.S-b[a.F])<max(0,x.S-b[x.F]))
	{
		return true;
	}
	return false;
}
int main(){
	//freopen("d.in","r",stdin);
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&c[i],&d[i]);
		tg[d[i]]=max(tg[d[i]],c[i]);
	}
	for(i=1000000;i>=0;i--)
	{
		dep[i]=max(dep[i+1],tg[i]);
		if(dep[i]!=dep[i+1])
		{
			cge.push_back(i);
		}
	}
	sort(cge.begin(),cge.end());
	for(i=0;i<n;i++)
	{
		tp[i]=max(dep[b[i]]-a[i],-1);
		nd.insert(-tp[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<cge.size();j++)
		{
			if(cge[j]+1>=b[i])
			{
				wt.push_back(make_pair(i,cge[j]+1));
			}
			if(cge[j]>=b[i])
			{
				wt.push_back(make_pair(i,cge[j]));
			}
		}
	}
	sort(wt.begin(),wt.end(),cmp);
	ans=1-(*nd.begin());
	for(i=0;i<wt.size();i++)
	{
		nd.erase(nd.find(-tp[wt[i].F]));
		tp[wt[i].F]=max(-1,dep[wt[i].S]-a[wt[i].F]);
		nd.insert(-tp[wt[i].F]);
		ans=min(ans,wt[i].S-b[wt[i].F]-(*nd.begin())+1);
	}
	printf("%d\n",ans);
	return 0;
}