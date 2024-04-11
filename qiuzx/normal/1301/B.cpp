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
#define N 100010
using namespace std;
ll n,a[N],x,y;
bool check(ll m)
{
	ll i,ta,tb;
	for(i=0;i<n;i++)
	{
		ta=0;
		tb=INF;
		if(a[i]==-1)
		{
			if(i-1>=0)
			{
				if(a[i-1]!=-1)
				{
					ta=max(ta,a[i-1]-m);
					tb=min(tb,a[i-1]+m);
				}
				else
				{
					ta=max(ta,x-m);
					tb=min(tb,y+m);
				}
			}
			if(i+1<n)
			{
				if(a[i+1]!=-1)
				{
					ta=max(ta,a[i+1]-m);
					tb=min(tb,a[i+1]+m);
				}
				else
				{
					ta=max(ta,x-m);
					tb=min(tb,y+m);
				}
			}
		}
		x=max(x,ta);
		y=min(y,tb);
		if(x>y)
		{
			return false;
		}
	}
	return true;
}
int main(){
	ll t,i,l,r,mid;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		l=0;
		r=INF;
		for(i=0;i+1<n;i++)
		{
			if(a[i]!=-1&&a[i+1]!=-1)
			{
				l=max(l,abs(a[i]-a[i+1]));
			}
		}
		while(l<r)
		{
			mid=(l+r)/2;
			x=0;
			y=INF;
			if(check(mid))
			{
				r=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		x=0;
		y=INF;
		check(l);
		cout<<l<<" "<<x<<endl;
	}
	return 0;
}