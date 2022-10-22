#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

typedef long long ll;

ll n;

int main()
{
	cin>>n;
	ll dd=0;
	for(ll i=1;i<=n;i++)
	{
		ll s,d;
		cin>>s>>d;
		ll l=0,r=1e15;
		while(l!=r)
		{
			int mid=l+r>>1;
			if(dd<s+d*mid)
				r=mid;
			else    
				l=mid+1;
		}
		dd=s+d*l;
	}
	cout<<dd;
}