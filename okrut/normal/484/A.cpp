#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug //
using namespace std;
typedef long long ll;
ll res (ll l, ll r, int i=60)
{
	int x=0;
	ll a=0;
	while (i>=0)
	{
		if (l&(1ll<<i) && r&(1ll<<i)) 
		{
			a+=1ll<<i;
			l-=1ll<<i;
			r-=1ll<<i;
		}
		if (!(l&(1ll<<i)) && r&(1ll<<i)) 
		{
			if (r+1==1ll<<(i+1)) return a+r; 
			else return a+=(1ll<<i)-1;
		}
		i--;
	}
	return a;
}
int main ()
{
	int n;
	ll a, b;
	cin>>n;
	rep(i,0,n)
	{
		cin>>a >>b;
		cout<<res(a,b) <<"\n";
	}
}