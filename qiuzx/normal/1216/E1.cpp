//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll k;
ll calc(ll x)
{
	ll ret=0,l=1,r,i,tl,tr;
	for(i=0;i<18;i++)
	{
		if(l>x)
		{
			break;
		}
		r=min(x,l*10-1);
		tl=x-r+1;
		tr=x-l+1;
		ret+=((tr-tl+1)*(tl+tr)/2)*(i+1);
		l*=10;
	}
	return ret;
}
ll calc2(ll x)
{
	ll ret=0,l=1,r,i;
	for(i=0;i<18;i++)
	{
		if(l>x)
		{
			break;
		}
		r=min(x,l*10-1);
		ret+=(r-l+1)*(i+1);
		l*=10;
	}
	return ret;
}
void solve()
{
	ll l,r,mid;
	scanf("%lld",&k);
	l=1;
	r=INF;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(calc(mid)<k)
		{
			l=mid+1;
		}
		else
		{
			r=mid;
		}
	}
	k-=calc(l-1);
	r=l;
	l=1;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(calc2(mid)<k)
		{
			l=mid+1;
		}
		else
		{
			r=mid;
		}
	}
	k-=calc2(l-1);
	vector<ll> v;
	while(l>0)
	{
		v.push_back(l%10);
		l/=10;
	}
	reverse(v.begin(),v.end());
	printf("%lld\n",v[k-1]);
	return;
}
int main(){
	ll q;
	scanf("%lld",&q);
	while(q--)
	{
		solve();
	}
	return 0;
}