#include<iostream>
#include<cstdio> 
using namespace std;

typedef long long ll;

ll T;

int main()
{
	cin>>T;
	while(T--)
	{
		ll a,b;
		scanf("%I64d%I64d",&a,&b);
		ll now=a*b;
		ll l=1,r=1e6;
		while(l!=r)
		{
			ll mid=l+r+1ll>>1ll;
			if(mid*mid*mid<=now)
				l=mid;
			else    
				r=mid-1ll;
		}
		ll ans=-1;
		ll aa,bb;
		if(l*l*l!=now)
		{
			printf("no\n");
			continue;
		}
		aa=a/l;bb=b/l;
		if(a==aa*aa*bb&&b==bb*bb*aa)
			printf("yes\n");
		else    
			printf("no\n");
	}
}