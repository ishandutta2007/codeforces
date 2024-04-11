#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long k2,k3,k5,k6,mn,z=0;
	
	scanf("%lld%lld%lld%lld",&k2,&k3,&k5,&k6);
	mn=min(min(k2,k5),k6);
	z+=mn*256;
	k2-=mn;
	z+=min(k2,k3)*32;
	printf("%lld\n",z);
}