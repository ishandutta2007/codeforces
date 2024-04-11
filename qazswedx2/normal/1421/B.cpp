#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,vis[15],tans[15][2],tt;
char s[1005][1005];
void print(int x,int y)
{
	tt++;
	tans[tt][0]=x;
	tans[tt][1]=y;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf(" %c",&s[i][j]);
		int c0=s[1][2]-'0',c1=s[2][1]-'0',c2=s[n-1][n]-'0',c3=s[n][n-1]-'0';
		vis[0]=vis[1]=0;
		c2^=1,c3^=1;
		vis[c0]++;
		vis[c1]++;
		vis[c2]++;
		vis[c3]++;
		tt=0;
		if(vis[0]>=2)
		{
			if(c0==1) print(1,2);
			if(c1==1) print(2,1);
			if(c2==1) print(n-1,n);
			if(c3==1) print(n,n-1);
		}
		else
		{
			if(c0==0) print(1,2);
			if(c1==0) print(2,1);
			if(c2==0) print(n-1,n);
			if(c3==0) print(n,n-1);
		}
		printf("%d\n",tt);
		for(int i=1;i<=tt;i++)
			printf("%d %d\n",tans[i][0],tans[i][1]);
	}
	return 0;
}