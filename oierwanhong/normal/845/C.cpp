#include<iostream>
#include<cstdio>
#include<map>
typedef long long ll;
typedef std::map<int,int> mii;
mii p;
ll n;
int main()
{
	scanf("%lld",&n);
	ll l,r,sum=0;
	for(ll i=1;i<=n;++i)
	{
		scanf("%lld%lld",&l,&r);
		++p[l];--p[r+1];
	}
	for(mii::iterator i=p.begin();i!=p.end();++i)
	{
		sum+=i->second;
		if(sum>2)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}