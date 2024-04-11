#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=255;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

bool is1[N*N],is2[N*N];
int a[N][N];

signed main()
{
	int n=read(),m=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) a[i][j]=read();
	for (int i=1;i<=n;i++)
	{
		int mx=0;
		for (int j=1;j<=m;j++) mx=max(mx,a[i][j]);
		is1[mx]=1;
	}
	for (int j=1;j<=m;j++)
	{
		int mx=0;
		for (int i=1;i<=n;i++) mx=max(mx,a[i][j]);
		is2[mx]=1;
	}
	memset(a,0,sizeof(a));
	queue<pair<int,int>>q;
	int r=0,c=0;
	for (int i=n*m;i>=1;i--)
	if (is1[i]&&is2[i])
	{
		a[++r][++c]=i;
		for (int j=r-1;j>=1;j--) q.push({j,c});
		for (int j=c-1;j>=1;j--) q.push({r,j});
	}
	else if (is1[i])
	{
		a[++r][c]=i;
		for (int j=c-1;j>=1;j--) q.push({r,j});
	}
	else if (is2[i])
	{
		a[r][++c]=i;
		for (int j=r-1;j>=1;j--) q.push({j,c});
	}
	else
	{
		auto [x,y]=q.front();
		a[x][y]=i;
		q.pop();
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) print(a[i][j]," \n"[j==m]);
	
	return 0;
}