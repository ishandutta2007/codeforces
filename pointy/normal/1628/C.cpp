// By: Little09
// Problem: C. Grid Xor
// Contest: Codeforces - Codeforces Round #767 (Div. 1)
// URL: https://codeforces.com/contest/1628/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

const int N=1005;
int n,m; 
int a[N][N];

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
bool check(int x,int y)
{
	int tot=0;
	if (x!=1&&a[x-1][y]==1) tot^=1;
	if (x!=n&&a[x+1][y]==1) tot^=1;
	if (y!=1&&a[x][y-1]==1) tot^=1;
	if (y!=n&&a[x][y+1]==1) tot^=1;
	if (tot) return 0;
	return 1;
}
void work()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			a[i][j]=0;
		}
	}
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (check(i-1,j)) a[i][j]=1;
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			ans=(ans^(a[i][j]*read()));
		}
	}
	cout << ans << endl;
	return;
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}