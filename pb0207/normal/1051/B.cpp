#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll l,r;

int main()
{
	ll l,r;
	puts("YES");
	scanf("%lld%lld",&l,&r);
	for(ll i=l;i<=r;i+=2)
		printf("%lld %lld\n",i,i+1);
}