// By: Little09
// Problem: CF1580C Train Maintenance
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1580C
// Memory Limit: 500 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=200005,B=450;
int n,m,T; 
int x[N],y[N],las[N];
int d[B+5][B+5],f[N],tot,I;
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
namespace sub1
{
	inline void add(int x,int y)
	{
		if (x<=m) f[x]+=y;
		if (x<I) tot+=y;
	}
	void change(int x,int y,int z,int u)
	{
		while (u<=m)
		{
			add(u+x,z),add(u+x+y,-z);
			u+=x+y;
		}
	}
}
namespace sub2
{
	void change(int x,int y,int z,int u)
	{
		for (int i=x;i<x+y;i++)
		{
			d[x+y][(u+i)%(x+y)]+=z;
		}
	}
}
int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) x[i]=read(),y[i]=read();
	for (int i=1;i<=m;i++)
	{
		I=i;
		int tp=read(),k=read();
		int t=x[k]+y[k];
		if (tp==1)
		{
			las[k]=i;
			if (t>B) sub1::change(x[k],y[k],1,i);
			else sub2::change(x[k],y[k],1,i);
		}
		else 
		{
			int u=las[k];
			if (t>B) sub1::change(x[k],y[k],-1,u);
			else sub2::change(x[k],y[k],-1,u);
		}
		int ans=0;
		for (int j=2;j<=B;j++) ans+=d[j][i%j];
		tot+=f[i];
		printf("%d\n",tot+ans);
	}
	return 0;
}