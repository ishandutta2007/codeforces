#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
ll a,b,c;
 
inline ll calc(ll a,ll b)
{
	if (a==b) return a+b;
	return 2*min(a,b)+1;
}
 
int main()
{
	scanf("%lld%lld%lld",&a,&b,&c);
	printf("%lld\n",2*c+calc(a,b));
 
	return 0;
}
//