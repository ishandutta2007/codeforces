// By: Little09
// Problem: CF627A XOR Equation
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF627A
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
inline ll lowbit(ll x)
{
	return x&(-x);
}
int main()
{
	ll a=read(),b=read();
	ll c=a-b;
	if (c<0||c%2!=0)
	{
		puts("0");
		return 0;
	}
	c/=2;
	if (b&c)
	{
		puts("0");
		return 0;
	}
	ll ans=0;
	while (b)
	{
		ans++;
		b-=lowbit(b);
	}
	ans=(1ll<<ans);
	if (c==0) ans-=2;
	cout << ans;
	return 0;
}