#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=2005;
vector<int> cnt[maxn];
int ans[3][maxn],sol,n;
void outans()
{
	puts("YES");
	for(int i=0;i<3;i++)
		for(int j=0;j<n;j++)
			printf("%d%c",ans[i][j],j==n-1?'\n':' ');
}
void addans()
{
	int tmp=0;
	for(int i=1;i<=2000;i++)
		for(int j=0;j<cnt[i].size();j++)
			ans[sol][tmp++]=cnt[i][j];
	sol++;
	if(sol==3)
	{
		outans();
		exit(0);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		cnt[x].push_back(i);
	}
	addans();
	for(int i=1;i<=2000;i++)
	{
		if(cnt[i].size()>=2)
		{
			swap(cnt[i][0],cnt[i][1]);
			addans();
		}
		if(cnt[i].size()>=3)
		{
			swap(cnt[i][0],cnt[i][2]);
			addans();
		}
	}
	puts("NO");
	return 0;
}