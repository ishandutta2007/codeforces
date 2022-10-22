// By: Little09qwq
// Problem: CF1687B Railway System
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1687B
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e5+5;
struct point
{
	int id,x;
}a[N];
bool vis[N];


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


int print()
{
	printf("? ");
	for (int i=1;i<=m;i++) printf("%d",(int)vis[i]);
	printf("\n");
	fflush(stdout);
	return read();
}
bool cmp(point x,point y)
{
	return x.x<y.x;
}
int main()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		a[i].id=i;
		vis[i]=1;
		a[i].x=print();
		vis[i]=0;
	}
	sort(a+1,a+m+1,cmp);
	vis[a[1].id]=1,vis[a[2].id]=1;
	int res=a[1].x;
	for (int i=2;i<=m;i++)
	{
		vis[a[i].id]=1;
		if (print()!=res+a[i].x)
		{
			vis[a[i].id]=0;
		}
		else res+=a[i].x;
	}
	printf("! %d\n",res);
	fflush(stdout);
	return 0;
}