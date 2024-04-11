#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long ll;

ll n,k;

int main()
{
	scanf("%lld%lld",&n,&k);
	double ans=(-1.5+sqrt(2.25+2*(k+n)));
	ll m=floor(ans);
	printf("%lld",n-m);
} 

/*
m*(m+1)/2-(n-m)=k
m^2/2+m/2-n+m=k
1/2*m^2+3/2m-n-k=0
*/