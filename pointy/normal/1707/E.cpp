// Author: Little09
// Problem: CF1707E Replace
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1707E
// Memory Limit: 1000 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int n,m;
int a[N],lg[N];
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
struct point
{
	int l,r;
	point operator + (const point &o) const
	{
		return {min(l,o.l),max(r,o.r)};
	}
}f[35][17][N];
inline bool check(point x)
{
	return (x.l==1&&x.r==n);
}
point ask(int k,int l,int r)
{
	if (l>=r) return {n,1};
	int t=lg[r-l];
	return f[k][t][l]+f[k][t][r-(1<<t)];
}
ll query(int l,int r)
{
	if (l==1&&r==n) return 0;
	if (check(ask(34,l,r))==0) return -1;
	ll res=0;
	for (int i=34;i>=0;i--) 
	{
		point tmp=ask(i,l,r);
		if (check(tmp)==0) res+=(1ll<<i),l=tmp.l,r=tmp.r;
	}
	return res+1;
}

int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	for (int k=0;k<=34;k++)
	{
		if (k==0) for (int i=1;i<n;i++) f[k][0][i]={min(a[i],a[i+1]),max(a[i],a[i+1])};
		else for (int i=1;i<n;i++) f[k][0][i]=ask(k-1,f[k-1][0][i].l,f[k-1][0][i].r);
		int t=lg[n-1];
		for (int j=1;j<=t;j++)
		{
			for (int i=1;i<=n-(1<<j);i++)
			{
				f[k][j][i]=f[k][j-1][i]+f[k][j-1][i+(1<<(j-1))];
			}
		}
	}
	while (m--)
	{
		int l=read(),r=read();
		printf("%lld\n",query(l,r));
	}
	return 0;
}