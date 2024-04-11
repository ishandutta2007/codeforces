#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,l,m,a[100005],d[100005],f[1005][1005];
int main()
{
	memset(f,0x3f,sizeof(f));
	scanf("%d%d%d",&n,&l,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&d[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	d[n+1]=l;
	for(int i=0;i<=m;i++)
		f[1][i]=0;
	for(int i=2;i<=n+1;i++)
	{
		for(int k=0;k<=m;k++)
			for(int j=1;j<i;j++)
				if(k-(i-j-1)>=0)
				{
					f[i][k]=min(f[i][k],f[j][k-(i-j-1)]+a[j]*(d[i]-d[j]));
				//	printf("i=%d,k=%d,f=%d\n",i,k,f[i][k]);
				}
	}
	printf("%d\n",f[n+1][m]);
	return 0;
}