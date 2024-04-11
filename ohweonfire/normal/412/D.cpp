#include <cstdio>
#include <unordered_set>
using namespace std;
const int maxn=100005;
unordered_set<int> st[maxn];
int ans[maxn];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		st[x].insert(y);
	}
	for(int i=1;i<=n;i++)
	{
		int j=i;
		ans[i]=i;
		while(j!=1&&st[ans[j-1]].count(ans[j]))
		{
			swap(ans[j],ans[j-1]);
			j--;
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}