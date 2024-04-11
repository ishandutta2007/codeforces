#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n;

int deg[N],w[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		long long ans=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&w[i]),ans+=w[i],deg[i]=0;
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			deg[u]++;
			deg[v]++;
		}
		vector<pair<int,int> >v;
		for(int i=1;i<=n;i++)
			v.push_back(make_pair(w[i],deg[i]));
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		printf("%lld ",ans);
		int j=0;
		for(int i=2;i<n;i++)
		{
			while(v[j].second==1&&j<v.size())
				j++;
			ans+=v[j].first;
			v[j].second--;
			printf("%lld ",ans);
		}
		puts("");
	}
}