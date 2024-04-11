#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,m,r,c;
char s[1005][1005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&m,&r,&c);
		for(int i=1;i<=n;i++)
			scanf("%s",s[i]+1);
		int fl0=0,fl1=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(s[i][j]=='B')
				{
					fl0=1;
					if(i==r||j==c) fl1=0;
				}
			}
		if(!fl0)
		{
			printf("-1\n");
			continue;
		}
	/*	int fl2=0,fl3=0;
		for(int i=1;i<=n;i++)
			if(s[i][c]!='B') fl2=1;
		for(int i=1;i<=m;i++)
			if(s[r][i]!='B') fl3=1;*/
		if(s[r][c]=='B') printf("0\n");
		else printf("%d\n",fl1+1);
	//	printf("%d\n",fl2+fl3+fl1);
	}
	return 0;
}