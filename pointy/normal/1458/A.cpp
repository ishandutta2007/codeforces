#include<bits/stdc++.h>
using namespace std;
int n,m;
#define ll long long
ll a[200005],b[200005],p;
inline ll read()
{
	char C=getchar();
	ll F=1,ANS=0;
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
ll gcd(ll x,ll y)
{
	if (y==0) return x;
	return gcd(y,x%y);
}
int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for (int i=1;i<=m;i++) b[i]=read();
	if (n==1)
	{
		for (int i=1;i<=m;i++)
		{
			cout << b[i]+a[1] <<" ";
		}
		return 0;
	}
	p=a[2]-a[1];
	for (int i=3;i<=n;i++)
	{
		p=gcd(p,a[i]-a[i-1]);
	}
	ll q;
	for (int i=1;i<=m;i++)
	{
		q=a[1]+b[i];
		q=gcd(q,p);
		cout << q <<" ";
	}
	return 0;
}