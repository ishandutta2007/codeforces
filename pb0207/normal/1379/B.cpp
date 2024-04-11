#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;

ll l,r,m;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		cin>>l>>r>>m;
		ll a,b,c;
		ll L=max(m+l-r,1ll),R=m+r-l;
		for(ll i=l;i<=r;i++)
		{
			ll lb=L/i+(L%i!=0),rb=R/i;
			if(rb>=lb)
			{
				ll n=lb;
				ll a=i;
				ll d=n*a-m;
				ll b=d>0?l:r,c=b+d;
				cout<<a<<" "<<b<<" "<<c<<endl;
				break;
			}
		}		
	}
} 
//(m+c-b)/a
/*
L=m+l-r,R=m+r-l

*/