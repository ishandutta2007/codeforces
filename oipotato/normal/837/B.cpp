#include <cstdio>
using namespace std;
char ch;
int a[110][110],n,m;
bool flag;
int main()
{
	scanf("%d%d\n",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			ch=getchar();
			if(ch=='G')
				a[i][j]=1;
			else if(ch=='B')
				a[i][j]=2;
		}
		getchar();
	}
	if(n%3==0)
	{
		flag=1;
		for(int i=1;i<=n/3;i++)
			for(int j=1;j<=m;j++)
				if(a[i][j]!=a[1][1])
					flag=0;
		for(int i=n/3+1;i<=n/3*2;i++)
			for(int j=1;j<=m;j++)
				if(a[i][j]!=a[n/3+1][1])
					flag=0;
		for(int i=n/3*2+1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(a[i][j]!=a[n/3*2+1][1])
					flag=0;
		if(a[1][1]==a[n/3+1][1]||a[1][1]==a[n/3*2+1][1]||a[n/3+1][1]==a[n/3*2+1][1])
			flag=0;
		if(flag)
		{
			printf("YES\n");
			return 0;
		}
	}
	if(m%3==0)
	{
		flag=1;
		for(int j=1;j<=m/3;j++)
			for(int i=1;i<=n;i++)
				if(a[i][j]!=a[1][1])
					flag=0;
		for(int j=m/3+1;j<=m/3*2;j++)
			for(int i=1;i<=n;i++)
				if(a[i][j]!=a[1][m/3+1])
					flag=0;
		for(int j=m/3*2+1;j<=m;j++)
			for(int i=1;i<=n;i++)
				if(a[i][j]!=a[1][m/3*2+1])
					flag=0;
		if(a[1][1]==a[1][m/3+1]||a[1][1]==a[1][m/3*2+1]||a[1][m/3+1]==a[1][m/3*2+1])
			flag=0;
		if(flag)
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}