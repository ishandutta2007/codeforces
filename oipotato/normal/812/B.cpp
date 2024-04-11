#include<cstdio>
#include<algorithm>
using namespace std;
int l[20],r[20],f[20][2],a[20][110],n,m;
int main()
{
	scanf("%d%d\n",&n,&m);
	for(int i=n;i;i--)
	{
		getchar();
		for(int j=1;j<=m;j++)a[i][j]=getchar()-'0';
		for(int j=1;j<=m;j++)
		if(a[i][j])
		{
			if(!l[i])l[i]=j;
			r[i]=j;
		}
		getchar();
		getchar();
	}
	for(;n&&!l[n];)n--;
	if(n==0)
	{
		printf("0");
		return 0;
	}
	if(n==1)
	{
		printf("%d",r[1]);
		return 0;
	}
	f[1][0]=r[1]*2;
	f[1][1]=m+1;
	for(int i=2;i<n;i++)
	if(l[i])
	{
		f[i][0]=min(f[i-1][0]+r[i]*2,f[i-1][1]+m+1)+1;
		f[i][1]=min(f[i-1][0]+m+1,f[i-1][1]+(m+1-l[i])*2)+1;
	}
	else
	{
		f[i][0]=f[i-1][0]+1;
		f[i][1]=f[i-1][1]+1;
	}
	printf("%d",min(f[n-1][0]+r[n],f[n-1][1]+(m+1-l[n]))+1);
	return 0;
}