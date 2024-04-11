#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a,m;
int t;
ll gcd(ll a,ll b)
{
	if(!b) return a;
	return gcd(b,a%b);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%I64d%I64d",&a,&m);
		m/=gcd(a,m);
		ll tans=1;
		for(ll i=2;i*i<=m;i++)
			if(m%i==0)
			{
				m/=i;
				tans*=i-1;
				while(m%i==0) tans*=i,m/=i;
			}
		if(m!=1) tans*=m-1;
		printf("%I64d\n",tans);
	}
	return 0;
}