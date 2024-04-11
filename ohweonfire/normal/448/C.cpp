#include <cstdio>
#include <algorithm>
using namespace std;

int a[5005],n;
int dfs(int left,int right,int h)
{
	if(left>right)
		return 0;
	int minn=left;
	for(int i=left+1;i<=right;i++)
		if(a[minn]>a[i])
			minn=i;
	return min(right-left+1,dfs(left,minn-1,a[minn])+dfs(minn+1,right,a[minn])+a[minn]-h);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	printf("%d\n",dfs(1,n,0));
	return 0;
}