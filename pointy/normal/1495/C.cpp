// By: Little09
// Problem: CF1495C Garden of the Sun
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1495C
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=505;
int n,m; 
char a[N][N];

inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}
inline int raed(){return read();}

void work()
{
	n=read(),m=read();
	for (int i=0;i<=n+2;i++)
	{
		for (int j=0;j<=m+2;j++)
		{
			a[i][j]=0;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			a[i][j]=readchar();
		}
	}
	
	if (n%3==1||n%3==2)
	{
		for (int i=1;i<=n;i+=3)
		{
			for (int j=1;j<=m;j++) a[i][j]='X';
			bool flag=0;
			for (int j=1;j<=m;j++) 
			{
				if (a[i+1][j]=='X')
				{
					a[i+2][j]='X',flag=1;
					break;
				}
				if (a[i+2][j]=='X')
				{
					a[i+1][j]='X',flag=1;
					break;
				}
			}
			if (flag==0&&i+2<=n) a[i+1][1]=a[i+2][1]='X';
		}	
	}
	else
	{
		for (int i=1;i<=n-2;i+=3)
		{
			for (int j=1;j<=m;j++) a[i][j]='X';
			bool flag=0;
			for (int j=1;j<=m;j++) 
			{
				if (a[i+1][j]=='X')
				{
					a[i+2][j]='X',flag=1;
					break;
				}
				if (a[i+2][j]=='X')
				{
					a[i+1][j]='X',flag=1;
					break;
				}
			}
			if (flag==0) a[i+1][1]=a[i+2][1]='X';
		}	
		for (int i=n-2;i<=n-2;i++) 
		{
			for (int j=1;j<=m;j++) 
			{
				if (a[i+1][j]=='X')
				{
					a[i+2][j]='X';
				}
				if (a[i+2][j]=='X')
				{
					a[i+1][j]='X';
				}
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
 }

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}