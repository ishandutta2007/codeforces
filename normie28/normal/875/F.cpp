#include <bits/stdc++.h>
using namespace std;
int rep[200001],cyc[200001];
vector<int> buc[200001];
int eu[200001],ev[200001],ew[200001];
int n,m,i,j,k,t,t1,u,v,a,b,res=0;
vector<int> lis;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		cin>>eu[i]>>ev[i]>>ew[i];
		lis.push_back(i);
	}
	sort(lis.begin(),lis.end(),[](int a, int b){
		return (ew[a]>ew[b]);
	});
	for (i=1;i<=n;i++)
	{
		rep[i]=i;
		cyc[i]=0;
		buc[i].push_back(i);
	}
	for (i=0;i<m;i++)
	{
		a=lis[i];
		u=eu[a];
		v=ev[a];
		u=rep[u];
		v=rep[v];
		if (u!=v)
		{
		    if (!(cyc[u]&cyc[v]))
		    {
			res+=ew[a];
			if (buc[u].size()>buc[v].size())
			{
				for (int g : buc[v])
				{
					rep[g]=u;
					buc[u].push_back(g);
				}
				cyc[u]=max(cyc[u],cyc[v]);
				buc[v].clear();
			}
			else
			{
				for (int g : buc[u])
				{
					rep[g]=v;
					buc[v].push_back(g);
				}
				cyc[v]=max(cyc[u],cyc[v]);
				buc[u].clear();
			}
		    }
		}
		else if (!cyc[u])
		{
			cyc[u]=1;
			res+=ew[a];
		}
	}
	cout<<res;
}