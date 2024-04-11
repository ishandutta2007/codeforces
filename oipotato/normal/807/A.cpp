#include<cstdio>
using namespace std;
int n,a[1010],b[1010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		if(a[i]!=b[i])
		{
			printf("rated");
			return 0;
		}
	}
	for(int i=1;i<n;i++)
	for(int j=i+1;j<=n;j++)
	if(a[j]>a[i])
	{
		printf("unrated");
		return 0;
	}
	printf("maybe");
	return 0;
}