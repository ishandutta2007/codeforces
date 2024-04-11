#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read()
{
	ll s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}

int main()
{
	ll x=read(),y=read(),z=read();
	ll MAX=(x+y)/z,now=x/z+y/z;
	if (MAX==now) printf("%lld 0\n",MAX);
	else
	{
		ll X=x%z,Y=y%z;
		if (X>Y) swap(X,Y);
		printf("%lld %lld\n",MAX,z-Y);
	}

	return 0;
}