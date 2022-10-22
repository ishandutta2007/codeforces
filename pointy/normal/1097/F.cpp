#include <bits/stdc++.h>
using namespace std;
const int N=100005,V=7005,v=7000;
bitset<V> w[V],r[V],a[N],mu;
int n,m;
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
void init()
{
	mu.set();
	for (int i=2;i*i<=v;i++)
	{
		for (int j=1;i*i*j<=v;j++)
		{
			mu[i*i*j]=0;
		}
	}
	for (int i=1;i<=v;i++)
	{
		for (int j=1;i*j<=v;j++)
		{
			r[i*j][i]=1;
			w[i][i*j]=mu[j];
		}
	}
}
int main()
{
	n=read(),m=read();
	init();
	while (m--)
	{
		int tp=read();
		if (tp==1)
		{
			int x=read(),y=read();
			a[x]=r[y];
		}
		else if (tp==2)
		{
			int x=read(),y=read(),z=read();
			a[x]=a[y]^a[z];
		}
		else if (tp==3)
		{
			int x=read(),y=read(),z=read();
			a[x]=a[y]&a[z];
		}
		else
		{
			int x=read(),y=read();
			int ans=((w[y]&a[x]).count()&1);
			printf("%d",ans);
		}
	}
	return 0;
}