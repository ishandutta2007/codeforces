#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
using namespace std;
ll t,a,b,l,r,q,g;
ll hmn(ll x)
{
	ll md=x%g,dv=x/g;
	return dv*b+min(md+1,b);
}
int main(){
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>q;
		if(a>b)
		{
			swap(a,b);
		}
		g=a*b/(__gcd(a,b));
		while(q--)
		{
			cin>>l>>r;
			cout<<r-l+1-(hmn(r)-hmn(l-1))<<endl;
		}
	}
	return 0;
}