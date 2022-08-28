#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a,b,ans=99999999999999ll,id=0;
ll gcd(ll x,ll y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}
void getans(ll x)
{
	ll c=(a/x+(a%x!=0))*x,d=(b/x+(b%x!=0))*x;
	if(ans>c*d/gcd(c,d))
	{
		ans=c*d/gcd(c,d);
		id=c-a;
	}
	else if(ans==c*d/gcd(c,d))
		id=min(id,c-a); 
}
int main()
{
	scanf("%I64d%I64d",&a,&b);
	if(a>b) swap(a,b);
	if(a==b)
	{
		printf("0");
		return 0;
	}
	for(ll i=1;i<=sqrt(b-a);i++)
		if((b-a)%i==0)
		{
			getans(i);
			getans((b-a)/i);
		}
	printf("%I64d",id);
	return 0;
}