#include<cstdio>
using namespace std;
bool vis[55][55];
int a[55][55],n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	for(int k=1;k<=n;k++)
	for(int p=1;p<=n;p++)
	{
		if(a[i][j]+a[p][k]==a[i][k])vis[i][k]=1;
		if(a[i][j]+a[p][k]==a[p][j])vis[p][j]=1;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(a[i][j]!=1&&!vis[i][j])
	{
		printf("No");
		return 0;
	}
	printf("Yes");
	return 0;
}