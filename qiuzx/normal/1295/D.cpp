#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define F first
#define S second
#define ll long long
using namespace std;
vector<ll> pm;
void getprime(ll x)
{
	ll i,t=x;
	for(i=2;i*i<=t;i++)
	{
		if(x%i==0)
		{
			pm.push_back(i);
			while(x%i==0)
			{
				x/=i;
			}
		}
	}
	if(x!=1)
	{
		pm.push_back(x);
	}
	return;
}
int main(){
	ll T,i,a,m,g,k,r;
	cin>>T;
	while(T--)
	{
		cin>>a>>m;
		pm.clear();
		g=__gcd(a,m);
		k=m/g;
		r=a/g;
		m=(m+a)/g;
		getprime(k);
		for(i=0;i<pm.size();i++)
		{
			m-=m/pm[i];
			r-=r/pm[i];
		}
		cout<<m-r<<endl;
	}
	return 0;
}