// By: Little09
// Problem: C. Madoka and Childish Pranks
// Contest: Codeforces - Codeforces Round #777 (Div. 2)
// URL: https://codeforces.ml/contest/1647/problem/C
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

const int N=105;
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
int ans[N*N][4],cnt;
void work()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			a[i][j]=readchar()-'0';
		}
	}
	cnt=0;
	if (a[1][1]==1)
	{
		printf("-1\n");
		return;
	}
	for (int i=n;i>=1;i--)
	{
		for (int j=m;j>=1;j--)
		{
			if (a[i][j]==0) continue;
			if (j!=1)
			{
				cnt++;
				ans[cnt][0]=i,ans[cnt][1]=j-1;
				ans[cnt][2]=i,ans[cnt][3]=j;
			}
			else 
			{
				cnt++;
				ans[cnt][0]=i-1,ans[cnt][1]=j;
				ans[cnt][2]=i,ans[cnt][3]=j;
			}
		}
	}
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++)
	{
		printf("%d %d %d %d\n",ans[i][0],ans[i][1],ans[i][2],ans[i][3]);
	}
	
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}