#include <bits/stdc++.h>

typedef unsigned long long int ull;
typedef long double ldb;
typedef long long int ll;

#define ForA1(n)  for (ll i=0; i<n; i++)
#define ForA2(n)  for (ll j=0; j<n; j++)
#define ForA3(n)  for (ll k=0; k<n; k++)
#define ForN1(n)  for (ll i=1; i<=n; i++)
#define ForN2(n)  for (ll j=1; j<=n; j++)
#define ForN3(n)  for (ll k=1; k<=n; k++)

#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vll vector<ll>
#define F first
#define S second
#define debug(x)    cerr << #x << " = " << x << endl;
#define mem(x) memset(x,0,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;

int main()
{
	ll k,p;
	cin>>p>>k;
	
	if(p<k)
	{
	    cout<<1<<endl<<p<<endl;
	    return 0;
	}
	
	vector<ll> hehe;
	ll isneg=0;
	ll prev= p;
	ll next;
	
	while(prev>=k || isneg!=0)
	{
	    if(isneg==0)
	    {
	        next = prev/k;
	        prev = next;
	        isneg=1;
	        next*=-1;
	        hehe.push_back(next);
	    }
	    else
	    {
	        next = (prev+k-1)/k;
	        isneg=0;
	        prev = next;
	        hehe.push_back(next);
	    }
	   // cout<<next<<" ";
	}
	if(prev!=0)
	    hehe.push_back(0);
	ll ans = hehe.size();
	cout<<ans<<endl;
	
	cout<<p+(hehe[0]*k)<<" ";
	
	for(ll i=1;i<ans;i++)
	{
	    cout<<hehe[i-1] + (hehe[i]*k)<<" ";
	}
	cout<<endl;

    // while(p!=0)
    // {
    //     p=p/k;
    //     cout<<p<<endl;
    // }

    return 0;
}