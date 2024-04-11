#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll a,b,c;
int main(){
	ll i,v;
	scanf("%lld%lld%lld",&a,&b,&c);
	puts("First");
	fflush(stdout);
	printf("%lld\n",v=max(max(a,b),c)-min(min(a,b),c));
	fflush(stdout);
	scanf("%lld",&i);
	if(i==1)
	{
		a+=v;
	}
	else if(i==2)
	{
		b+=v;
	}
	else
	{
		c+=v;
	}
	vector<ll> vv={a,b,c};
	sort(vv.begin(),vv.end());
	printf("%lld\n",v=vv[2]-vv[1]+vv[2]-vv[0]);
	fflush(stdout);
	scanf("%lld",&i);
	if(i==1)
	{
		a+=v;
	}
	else if(i==2)
	{
		b+=v;
	}
	else
	{
		c+=v;
	}
	vv={a,b,c};
	sort(vv.begin(),vv.end());
	printf("%lld\n",v=vv[2]-vv[1]);
	fflush(stdout);
	scanf("%lld",&i);
	return 0;
}