// By: Little09
// Problem: C. OKEA
// Contest: Codeforces - Codeforces Round #770 (Div. 2)
// URL: https://codeforces.com/contest/1634/problem/C
// Memory Limit: 256 MB
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

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N];

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
	if (m==1)
	{
		printYES;
		for (int i=1;i<=n;i++)
		{
			printf("%d\n",i);
		}
		return;
	}
	if (n%2==1) 
	{
		printNO;
		return;
	}
	printYES;
	int x=1,y=2;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (i%2==1)
			{
				printf("%d ",x);
				x+=2;
			}
			else
			{
				printf("%d ",y);
				y+=2;
			}
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