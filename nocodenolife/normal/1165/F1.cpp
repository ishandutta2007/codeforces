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

#define mod 998244353 
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
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,m;
    cin>>n>>m;

    ll arr[n];
    ll temp[n];
    ll sum=0;
    set <ll, greater <ll> > offers[200005];
    set <ll, greater <ll> > :: iterator itr;
    ForA1(n)
    {
    	cin>>arr[i];
    	sum+=arr[i];
    }

    ll day, type;
    ForA1(m)
    {
    	cin>>day>>type;
    	offers[day].insert(type);
    }
    ll temSum;
    ll low = sum-1;
    ll high = 2*sum,mid;
    ll tokens;
    ll extra;
    int checker;
    ll x;
    while(high-low>1)
    {
    	mid = (high+low)/2;
    	//cout<<low<<" "<<mid<<" "<<high<<endl;
    	checker = 0;

    	//checking
    	ForA1(n)
    	{
    		temp[i]=arr[i];
    	}
    	temSum = sum;
    	tokens = mid;
    	extra = 0;
    	for(ll d=min(mid,200003ll);d>=1;d--)
    	{
    		if(tokens>d)
    		{
    			extra += tokens - d;
    			tokens = d;
    		}
    		for(itr = offers[d].begin(); itr!=offers[d].end(); ++itr)
    		{
    			if(temp[*itr-1]==0)
    				continue;
    			x = min(temp[*itr-1],tokens);
    			temp[*itr-1] -= x;
    			tokens -= x;
    			temSum-=x;
    		}
    	}
    	extra += tokens;
    	if(extra>=temSum*2)
    		checker = 1;
    	else
    		checker = 0;

    	if(checker==0) //cant get all
    	{
    		low = mid;
    	}
    	else
    	{
    		high = mid;
    	}
    }

    cout<<high<<endl;

    return 0;
}