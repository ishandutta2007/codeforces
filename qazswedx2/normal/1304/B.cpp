#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,f[105][105],vis[105],tans[100005][2],t;
char s[105][105];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	/*for(int i=1;i<=n;i++)
	{
		a[i]=1;
		for(int j=1,k=m;j<=m;j++,k--)
			if(s[i][j]!=s[i][k])
				a[i]=0;
	}*/
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[i][j]=1;
			for(int k=1,l=m;k<=m;k++,l--)
				if(s[i][k]!=s[j][l])
					f[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
			if(f[i][j]&&!vis[j])
			{
				vis[i]=vis[j]=1;
				tans[++t][0]=i;
				tans[t][1]=j;
				break;
			}
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]&&f[i][i])
		{
			tans[++t][0]=i;
			break;
		}
	if(!t)
	{
		printf("0\n");
		return 0;
	}
	if(tans[t][1])
	{
		printf("%d\n",2*t*m);
		for(int i=1;i<=t;i++)
			printf("%s",s[tans[i][0]]+1);
		for(int i=t;i;i--)
			printf("%s",s[tans[i][1]]+1);
		return 0;
	}
	printf("%d\n",2*t*m-m);
	for(int i=1;i<=t;i++)
		printf("%s",s[tans[i][0]]+1);
	for(int i=t-1;i;i--)
		printf("%s",s[tans[i][1]]+1);
	return 0;
}