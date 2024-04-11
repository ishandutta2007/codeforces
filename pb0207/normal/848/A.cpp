#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

ll k;

int main()
{
	cin>>k;
	char now='a';
	if(k==0)
		puts("ab");
	else
	while(k)
	{
		ll l=1ll,r=100000ll+1;
		while(r-l>1)
		{
			ll mid=(l+r)>>1;
			if(mid*(mid-1)/2ll<=k)
				l=mid;
			else
				r=mid;
		}
		for(int i=1;i<=l;i++)
			cout<<now;
		now+=1;
		k-=l*(l-1)/2ll;
	}
}