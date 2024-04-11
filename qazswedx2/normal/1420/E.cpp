#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,l,a[105],b[105],f[85][4005][85],tans[100005];
int F(int x)
{
	return x>0?x:-x;
}
int G(int x)
{
	return x*(x-1)/2;
}
int main()
{
	//freopen("CF1420E.in","r",stdin);
	memset(f,0x3f,sizeof(f));
	scanf("%d",&n);
	int las=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x)
		{
			a[++m]=i-las-1;
			las=i;
		}
	}
	a[++m]=n-las;
	for(int i=1;i<=m;i++)
		a[i]+=a[i-1];
	l=(n-1)*n/2;
//	for(int i=1;i<=m;i++)
	//	printf("i=%d,a=%d\n",i,a[i]);
	f[0][0][0]=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<=l;j++)
			for(int k=0;k<=a[m];k++)
			{
				for(int kk=k;kk<=a[m];kk++)
					f[i+1][j+F(k-a[i])][kk]=min(f[i+1][j+F(k-a[i])][kk],f[i][j][k]+G(kk-k));
			}
	}
	for(int i=0;i<=l;i++)
		tans[i]=f[m][i][a[m]];
	for(int i=1;i<=l;i++)
		tans[i]=min(tans[i],tans[i-1]);
	for(int i=0;i<=l;i++)
	{
		tans[i]=G(n-m+1)-tans[i];
		printf("%d ",tans[i]);
	}
	return 0;
}