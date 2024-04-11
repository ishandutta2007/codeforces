#include<cstdio>
#include<algorithm>
using namespace std;
int a[210],b[210],n,k;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=k;i++)scanf("%d",&b[i]);
	sort(b+1,b+k+1);
	for(int i=1;i<=n;i++)
	if(a[i]==0)
	a[i]=b[k--];
	for(int i=1;i<n;i++)
	if(a[i]>a[i+1])
	{
		printf("Yes");
		return 0;
	}
	printf("No");
	return 0;
}