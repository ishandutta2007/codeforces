// By: Little09
// Problem: H. Permutation and Queries
// Contest: Codeforces Round #762 (Div. 3)
// URL: https://codeforces.com/contest/1619/problem/H
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,B=350;
int t[N],pre[N],f[N];
int n,m;
void work(int x)
{
	int y=t[x];
	for (int i=1;i<B;i++) x=pre[x];
	for (int i=1;i<=B;i++)
	{
		f[x]=y;
		x=t[x],y=t[y];
	}
}
int ask(int x,int y)
{
	while (y>=B)
	{
		y-=B;
		x=f[x];
	}
	for (int i=1;i<=y;i++) x=t[x];
	return x;
}
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

int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) t[i]=read(),pre[t[i]]=i;
	for (int i=1;i<=n;i++)
	{
		int x=i;
		for (int j=1;j<=B;j++) x=t[x];
		f[i]=x;
	}
	for (int i=1;i<=m;i++)
	{
		int tp=read(),x=read(),y=read();
		if (tp==1)
		{
			swap(t[x],t[y]);
			swap(pre[t[x]],pre[t[y]]);
			work(x),work(y);
		}
		else printf("%d\n",ask(x,y));
	}
	return 0;
}