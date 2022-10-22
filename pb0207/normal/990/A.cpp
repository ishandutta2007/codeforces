#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

typedef long long ll;

ll n,m,a,b;

int main()
{
	cin>>n>>m>>a>>b;
	ll x=n/m;
		printf("%lld",min((n-m*x)*b,(m*(x+1)-n)*a));
}