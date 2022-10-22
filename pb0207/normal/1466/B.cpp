#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T;

int n,x[N],vis[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=n*4;i++)
			vis[i]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&x[i]);
		for(int i=1;i<=n;i++)
		{
			vis[x[i]]++;
			if(vis[x[i]]>2)
				vis[x[i]]=2;
		}
		for(int i=1;i<=n*4;i++)
			if(vis[i]>1)
				vis[i+1]++,vis[i]--;
		int ans=0;
		for(int i=1;i<=n*4;i++)
			ans+=vis[i]?1:0;
		printf("%d\n",ans);
	}
}