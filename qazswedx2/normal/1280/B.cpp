#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,m;
char s[105][105];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%s",s[i]+1);
		int fl0=0,fl1=0,fl2=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(s[i][j]=='P') fl0=1;
				if(s[i][j]=='A') fl1=1;
			}
		if(!fl0)
		{
			printf("0\n");
			continue;
		}
		if(!fl1)
		{
			printf("MORTAL\n");
			continue;
		}
		fl0=fl1=1;
		for(int i=1;i<=m;i++)
		{
			if(s[1][i]=='P') fl0=0;
			if(s[n][i]=='P') fl1=0;
		}
		if(fl0||fl1)
		{
			printf("1\n");
			continue;
		}
		fl0=fl1=1;
		for(int i=1;i<=n;i++)
		{
			if(s[i][1]=='P') fl0=0;
			if(s[i][m]=='P') fl1=0;
		}
		if(fl0||fl1)
		{
			printf("1\n");
			continue;
		}
		if(s[1][1]=='A'||s[1][m]=='A'||s[n][1]=='A'||s[n][m]=='A')
		{
			printf("2\n");
			continue;
		}
		fl2=0;
		for(int i=1;i<=n;i++)
		{
			int tfl=1;
			for(int j=1;j<=m;j++)
				if(s[i][j]=='P')
					tfl=0;
			if(tfl) fl2=1;
		}
		if(fl2)
		{
			printf("2\n");
			continue;
		}
		fl2=0;
		for(int i=1;i<=m;i++)
		{
			int tfl=1;
			for(int j=1;j<=n;j++)
				if(s[j][i]=='P')
					tfl=0;
			if(tfl) fl2=1;
		}
		if(fl2)
		{
			printf("2\n");
			continue;
		}
		fl0=fl1=0;
		for(int i=1;i<=m;i++)
		{
			if(s[1][i]=='A') fl0=1;
			if(s[n][i]=='A') fl1=1;
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i][1]=='A') fl0=1;
			if(s[i][m]=='A') fl1=1;
		}
		if(fl0||fl1)
		{
			printf("3\n");
			continue;
		}
		printf("4\n");
	}
	return 0;
}