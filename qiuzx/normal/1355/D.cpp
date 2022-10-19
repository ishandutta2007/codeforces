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
ll n,s;
void csr(ll x,ll l,ll r)
{
	ll i,p;
	if(r>=n)
	{
		p=s/n;
		for(i=0;i+1<n;i++)
		{
			cout<<p<<" ";
		}
		cout<<s-(n-1)*p<<endl;
		return;
	}
	for(i=0;i+1<r;i++)
	{
		cout<<x+1<<" ";
	}
	cout<<s-l-(r-1)*(x+1)<<" ";
	p=l/(n-r);
	for(i=0;i+1<n-r;i++)
	{
		cout<<p<<" ";
	}
	cout<<l-(n-r-1)*p<<endl;
}
int main(){
	ll i,jn,kn;
	cin>>n>>s;
	for(i=s/2;i>=0;i--)
	{
		jn=max((ll)0,i-1);
		kn=max((ll)0,(s-jn)/max(i+1,s-i+1));
		if(jn+kn>=n)
		{
			puts("YES");
			csr(i,jn,kn);
			cout<<i<<endl;
			return 0;
		}
	}
	puts("NO");
	return 0;
}