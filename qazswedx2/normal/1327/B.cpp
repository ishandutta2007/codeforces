#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int t,n,visa[100005],visb[100005];
vector<int> a[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			visa[i]=visb[i]=0,a[i].clear();
		for(int i=1;i<=n;i++)
		{
			int k;
			scanf("%d",&k);
			for(int j=1;j<=k;j++)
			{
				int x;
				scanf("%d",&x);
				a[i].push_back(x);
			}
		}
		int ct=0,ida=0,idb=0;
		for(int i=1;i<=n;i++)
			for(int j=0;j<a[i].size();j++)
				if(!visb[a[i][j]])
				{
					visa[i]=visb[a[i][j]]=1;
					ct++;
					break;
				}
		for(int i=1;i<=n;i++)
		{
			if(!visa[i]) ida=i;
			if(!visb[i]) idb=i;
		}
		if(ct==n) printf("OPTIMAL\n");
		else printf("IMPROVE\n%d %d\n",ida,idb);
	}
	return 0;
}