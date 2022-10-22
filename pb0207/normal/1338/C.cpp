#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7;

int T;

int BB[4]={0,2,3,1};

ll solve(ll a,ll b)
{
	ll A=0,B=0;
	ll x=a;
	ll t=1;
	while(t<x)
	{
		x-=t;
		t<<=2; 
	}
	A=t+x-1;
	for(int i=0;i<=60;i+=2)
		B+=(1ll<<i)*BB[(A>>i)%4];
	if(!b)
		return A;
	else if(b==1)
		return B;
	else
		return A^B;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ll x;
		scanf("%lld",&x);
		ll a=(x-1)/3+1,b=(x-1)%3;
		printf("%lld\n",solve(a,b));
	}
}