#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[100005][3],b[100005],bt,f[105][505],g[505],p[100005];
int tmp[100005][3];
int cmp(int x,int y)
{
	return a[x][1]<a[y][1];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d%d",&a[i][1],&x);
		a[i][0]=a[i][1]-x;
		a[i][2]=a[i][1]+x;
		b[++bt]=a[i][0];
		b[++bt]=a[i][1];
		b[++bt]=a[i][2];
		p[i]=i;
	}
	sort(b+1,b+bt+1);
	bt=unique(b+1,b+bt+1)-b-1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<3;j++)
			a[i][j]=lower_bound(b+1,b+bt+1,a[i][j])-b;
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++)
		for(int j=0;j<3;j++)
			tmp[i][j]=a[p[i]][j];
/*	printf("bt=%d\n",bt);
	for(int i=1;i<=bt;i++)
		printf("%d ",b[i]);
	printf("\n");*/
	memcpy(a,tmp,sizeof(a));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=bt;j++)
			f[i][j]=f[i-1][j];
		int l=a[i][0],mid=a[i][1],r=a[i][2];
	//	printf("i=%d,a=%d,%d,%d\n",i,l,mid,r);
		for(int j=mid;j<=r;j++)
			f[i][j]=max(f[i][j],f[i-1][mid]+b[j]-b[mid]);
		/*printf("f=");
		for(int j=1;j<=bt;j++)
			printf("%d ",f[i][j]);
		printf("\n");*/
		memset(g,0,sizeof(g));
		int nw=mid;
		for(int j=i-1;j>=0;j--)
		{
			g[nw]=max(g[nw],f[j][l]+b[nw]-b[l]);
			nw=max(nw,a[j][2]);
		}
		for(int j=bt-1;j>0;j--)
			g[j]=max(g[j],g[j+1]-b[j+1]+b[j]);
		for(int j=1;j<=bt;j++)
			f[i][j]=max(f[i][j],g[j]);
		for(int j=2;j<=bt;j++)
			f[i][j]=max(f[i][j],f[i][j-1]);
	}
	printf("%d\n",f[n][bt]);
	return 0;
}