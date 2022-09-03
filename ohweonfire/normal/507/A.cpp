#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=105;
int a[maxn],k,n,ord[maxn];
bool cmp(int x,int y)
{
	return a[x]<a[y];
}
vector<int> ans;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		ord[i]=i;
		scanf("%d",a+i);
	}
	sort(ord,ord+n,cmp);
	int tmp=k;
	for(int i=0;i<n&&tmp>=a[ord[i]];i++)
	{
		tmp-=a[ord[i]];
		ans.push_back(ord[i]);
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		printf("%d ",ans[i]+1);
	}
	return 0;
}