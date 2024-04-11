// By: Little09
// Problem: F. Defender of Childhood Dreams
// Contest: Codeforces - Codeforces Round #749 (Div. 1 + Div. 2, based on Technocup 2022 Elimination Round 1)
// URL: https://codeforces.ml/contest/1586/problem/F
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
const int N=1e3+5;
int col[N][N],a[N],cnt;
int c[N][N];
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
int f(int x,int y)
{
	a[++cnt]=x;
	if (x==1) return 0;
	if (x==2) return 1;
	return 1+f((x+y-1)/y,y);
}
int s(int x)
{
	return (x+m-1)/m;
}

int main()
{
	n=read(),m=read();
	cout << f(n,m) << endl;
	if (a[cnt]==2) col[1][2]=1;
	for (int i=cnt-1;i>=1;i--)
	{
		int w=a[i];
		for (int j=1;j<=w;j++)
		{
			for (int k=1;k<=w;k++)
			{
				c[j][k]=0;
			}
		}
		for (int j=1;j<=w;j++)
		{
			for (int k=1;k<=w;k++)
			{
				if (j==k) continue;
				if (s(j)==s(k)) c[j][k]=1;
				else c[j][k]=col[s(j)][s(k)]+1;
			}
		}
		for (int j=1;j<=w;j++)
		{
			for (int k=1;k<=w;k++)
			{
				col[j][k]=c[j][k];
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			printf("%d ",col[i][j]);
			//assert(col[i][j]!=4);
		}
	}
	return 0;
}