#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool np[10001111];
int p[1000111],pn;
int mu[10001111];

ll n,l,r;

ll mpow(ll x,ll y)
{
	ll ans=1;
	for(int i=0;i<y;i++)
	{
		if((1.0*ans)*x>1e8)return 1e8;
		ans=ans*x;
	}
	return ans;
}

ll pw[10011];

int main()
{
	cin>>n>>l>>r;
	if(n==1)
	  cout<<r-l+1<<endl;
	else if(n==2)
	  cout<<(r-l+1)*(r-l)<<endl;
	else
	{
		pw[1]=1;
		int lim;
		for(int i=2;i<=10000;i++)
		{
			pw[i]=mpow(i,n-1);
			if(pw[i]>r)
			{
				lim=i-1;
				break;
			}
		}
		ll ans=0;
		for(int p=1;p<=lim;p++)
		{
			for(int q=p+1;q<=lim;q++)
			{
				if(__gcd(p,q)>1)
				  continue;
				ans+=max(0ll,r/pw[q]-(l-1)/pw[p]);
			}
		}
		cout<<ans*2<<endl;
	}
	return 0;
}