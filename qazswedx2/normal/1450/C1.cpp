#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,f[3],g[3];
char a[505][505];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%s",a[i]+1);
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(a[i][j]=='O') f[(i+j)%3]++;
				else if(a[i][j]=='X') g[(i+j)%3]++;
			}
		int ans=1e9,id1=0,id2=0;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				if(i!=j&&ans>f[i]+g[j])
				{
					ans=f[i]+g[j];
					id1=i;
					id2=j;
				}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(a[i][j]=='.') continue;
				if((i+j)%3==id1)
					a[i][j]='X';
				if((i+j)%3==id2)
					a[i][j]='O';
			}
		for(int i=1;i<=n;i++)
			printf("%s\n",a[i]+1);
	}
	return 0;
}