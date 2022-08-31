#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[105][105],b[105][105],ans[100005][2],t;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++)
			if(a[i][j]&&a[i][j+1]&&a[i+1][j]&&a[i+1][j+1])
			{
				b[i][j]=b[i][j+1]=b[i+1][j]=b[i+1][j+1]=1;
				ans[++t][0]=i;
				ans[t][1]=j;
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]!=b[i][j])
			{
				printf("-1");
				return 0;
			}
	printf("%d\n",t);
	for(int i=1;i<=t;i++)
		printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}