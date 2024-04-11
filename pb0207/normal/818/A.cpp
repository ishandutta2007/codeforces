#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

ll n,k;

int main()
{
	cin>>n>>k;
	ll t=n/2;
	t=t/(k+1);
	cout<<t<<" "<<t*k<<" "<<n-t-t*k;
}