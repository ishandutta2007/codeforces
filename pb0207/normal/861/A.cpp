#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long ll;

ll n,k,a,b,t;

ll gcd(ll a,ll b)
{
	return b==0?a:gcd(b,a%b);
}

int main()
{
	cin>>n>>k;
	t=1;
	for(ll i=1;i<=k;i++)
		t*=10;
	cout<<n/(gcd(n,t))*t;
}