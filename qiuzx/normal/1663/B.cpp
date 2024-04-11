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
ll x;
int main(){
	ll i;
	cin>>x;
	if(x>=2600)
	{
		puts("3000");
	}
	else if(x>=2400)
	{
		puts("2600");
	}
	else if(x>=2300)
	{
		puts("2400");
	}
	else if(x>=2100)
	{
		puts("2300");
	}
	else if(x>=1900)
	{
		puts("2100");
	}
	else if(x>=1600)
	{
		puts("1900");
	}
	else if(x>=1400)
	{
		puts("1600");
	}
	else if(x>=1200)
	{
		puts("1400");
	}
	else
	{
		puts("1200");
	}
	return 0;
}