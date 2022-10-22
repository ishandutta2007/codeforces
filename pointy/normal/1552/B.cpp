// By: Little09
// Problem: B. Running for Gold
// Contest: Codeforces Global Round 15
// URL: https://codeforces.com/contest/1552/problem/B
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
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N][6];

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
bool cmp(int x,int y)
{
	int tot=0;
	for (int i=1;i<=5;i++)
	{
		if (a[x][i]<a[y][i]) tot++;
	}
	return (tot>=3);
}
void work()
{
	n=read();
	for (int i=1;i<=n;i++) 
	{
		for (int j=1;j<=5;j++)
		{
			a[i][j]=read();
		}
	}
	int u=1;
	for (int i=2;i<=n;i++)
	{
		if (cmp(i,u)) u=i;
	}
	for (int i=1;i<=n;i++)
	{
		if (i==u) continue;
		if (!cmp(u,i))
		{
			printf("-1\n");
			return;
		}
	}
	printf("%d\n",u);
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}