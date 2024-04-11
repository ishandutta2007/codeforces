#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,m;
char s[1005][1005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				s[i][j]='B';
		s[1][1]='W';
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				printf("%c",s[i][j]);
			printf("\n");
		}
	}
	return 0;
}