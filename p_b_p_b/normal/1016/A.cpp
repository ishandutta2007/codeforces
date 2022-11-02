#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,rest;
int main()
{
	scanf("%I64d %I64d",&n,&m);
	ll x;
	while (n--)
	{
		scanf("%I64d",&x);
		rest+=x;
		printf("%I64d",rest/m);putchar(' ');
		rest%=m;
	}
}