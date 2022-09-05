#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int n,T,w[300010];
long long W;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		v.clear();
		scanf("%d%lld",&n,&W);
		for (int i=1; i<=n; i++) 
		{
			scanf("%d",&w[i]);
			if (w[i]>=(W+1)/2&&w[i]<=W&&v.empty()) v.push_back(i);
		}
		if (!v.empty())
		{
			printf("%d\n",(int)v.size());
			for (int i=0,sz=v.size(); i<sz; i++) printf("%d%c",v[i],i==sz-1?'\n':' ');
			continue;
		}
		long long tot=0;
		for (int i=1; i<=n; i++)
			if (w[i]<=W)
			{
				tot+=w[i];
				v.push_back(i);
				if (tot>=(W+1)/2) break;
			}
		if (tot>=(W+1)/2)
		{
			printf("%d\n",(int)v.size());
			for (int i=0,sz=v.size(); i<sz; i++) printf("%d%c",v[i],i==sz-1?'\n':' ');
		} else puts("-1");
	}
	return 0;
}