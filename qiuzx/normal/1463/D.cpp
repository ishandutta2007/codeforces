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
#define N 400010
using namespace std;
ll n,a[N],al,ar;
bool vis[N];
vector<ll> ap,na;
bool check1(ll x)
{
	ll i,j=0;
	for(i=x;i<n;i++)
	{
		if(ap[i]<na[j])
		{
			return false;
		}
		j++;
	}
	return true;
}
bool check2(ll x)
{
	ll i,j=n-x;
	for(i=0;i<x;i++)
	{
		if(ap[i]>na[j])
		{
			return false;
		}
		j++;
	}
	return true;
}
int main(){
	ll t,i,mx,mn,l,r,mid;
	scanf("%lld",&t);
	while(t--)
	{
		ap.clear();
		na.clear();
		scanf("%lld",&n);
		for(i=0;i<=2*n;i++)
		{
			vis[i]=false;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			vis[a[i]]=true;
			ap.push_back(a[i]);
		}
		for(i=1;i<=2*n;i++)
		{
			if(!vis[i])
			{
				na.push_back(i);
			}
		}
		l=0;
		r=n;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(check1(mid))
			{
				r=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		al=l;
		l=0;
		r=n+1;
		while(l+1<r)
		{
			mid=(l+r)>>1;
			if(check2(mid))
			{
				l=mid;
			}
			else
			{
				r=mid;
			}
		}
		ar=l;
		printf("%lld\n",ar-al+1);
	}
	return 0;
}