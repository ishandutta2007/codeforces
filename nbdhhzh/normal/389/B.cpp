#include<cstdio>
#include<cstring>
using namespace std;
int n,i,j,a[110][110],set,p;
char st[110];
void do1(int x,int y)
{
	if (a[x-1][y]&&a[x][y-1]&&a[x+1][y]&&a[x][y+1]&&a[x][y])
	a[x-1][y]=a[x][y-1]=a[x+1][y]=a[x][y+1]=a[x][y]=0,set+=5;return;
}
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%s",st);
		for (j=0;j<n;j++)if (st[j]=='#')a[i][j+1]=1,p++;else a[i][j+1]=0; 
	}
	for (i=2;i<n;i++)
		for (j=2;j<n;j++)
			do1(i,j);
	if (set==p)printf("YES");else printf("NO");
}