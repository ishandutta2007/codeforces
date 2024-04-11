#include<cstdio>
#include<algorithm>
using namespace std;
int m,n,a[3001],b[3001];
int main()
{
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	for(j=1;j<=m;j++)scanf("%d",&b[j]);
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	i=1;j=1;
	for(i=1;i<=n;i++)
	{
		while(j<=m&&b[j]<a[i])j++;
		if(j>m)break;
		j++;
	}
	printf("%d\n",n+1-i);
	return 0;
}