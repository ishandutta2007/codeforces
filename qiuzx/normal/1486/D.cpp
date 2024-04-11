#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll n,k,a[N];
bool check(ll x)
{
	ll sum=0,sm,ot,sumk=0,i;
	set<ll> st;
	for(i=0;i<k;i++)
	{
		if(a[i]>=x)
		{
			sum++;
		}
	}
	ot=k-sum;
	if(sum>ot)
	{
		return true;
	}
	st.insert(1);
	for(i=k;i<n;i++)
	{
		if(a[i]>=x)
		{
			sum++;
		}
		if(a[i-k]>=x)
		{
			sumk++;
		}
		st.insert(2*sumk-(i-k));
		if(i-2*sum+(*st.begin())<0)
		{
			return true;
		}
	}
	return false;
}
int main(){
	ll i,l,r,mid;
	scanf("%lld%lld",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	l=0;
	r=n+100;
	while(l+1<r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid;
		}
	}
	printf("%lld\n",l);
	return 0;
}