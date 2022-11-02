#include<cstdio>
#include<vector>
using namespace std;
vector<int>c[100010];
int n,ans[100010],cnt;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		c[x].push_back(i);
	}
	for(int i=0;i<n;i++)
	if(c[i].size())
	{
		for(;c[i].size()>=n-i;)
		{
			++cnt;
			for(int j=1;j<=n-i;j++)
			{
				ans[*c[i].rbegin()]=cnt;
				c[i].pop_back();
			}
		}
		if(c[i].size())
		{
			puts("Impossible");
			return 0;
		}
	}
	puts("Possible");
	for(int i=1;i<=n;i++)printf("%d%c",ans[i]," \n"[i==n]);
	return 0;
}