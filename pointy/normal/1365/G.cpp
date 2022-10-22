// Author: Little09
// Problem: CF1365G Secure Password
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1365G
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
#define ll long long
int cnt,n,p=0;
int a[N];
ll b[N];

inline ll read()
{
    ll F=1,ANS=0;
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
ll ask(int x)
{
	p=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]&(1<<x)) p++;
	}
	if (p==0) return 0;
	printf("? %d ",p);
	for (int i=1;i<=n;i++)
	{
		if (a[i]&(1<<x)) printf("%d ",i);
	}
	printf("\n");
	fflush(stdout);
	return read();
}
int main()
{
	n=read();
	
	for (int i=0;i<(1<<13);i++)
	{
		if (__builtin_popcount(i)==6) a[++cnt]=i;
	}
	for (int i=0;i<13;i++) b[i]=ask(i);
	printf("! ");
	for (int i=1;i<=n;i++)
	{
		ll ans=0;
		for (int j=0;j<13;j++)
		{
			if ((a[i]&(1<<j))==0) ans|=b[j];
		}
		printf("%lld ",ans);
	}
	return 0;
}