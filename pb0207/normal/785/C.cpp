#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long ll;

ll n,m;

int main()
{
	cin>>n>>m;
	if(m>=n)
	{
		cout<<n;
		exit(0);
	}
	else
	{
		ll l=0,r=2e9;
		while(r-l>1)
		{
			ll mid=(l+r)>>1;
			if(mid*(mid+1)/2>=n-m)
				r=mid;
			else
				l=mid;
		}
		cout<<r+m;
	}
}