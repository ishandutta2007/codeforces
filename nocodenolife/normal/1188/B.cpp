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

ll findVal(ll x, ll k, ll p)
{
	x%=p;
	k%=p;

	ll ans = x;
	ans%=p;
	ans*=x;
	ans%=p;
	ans*=x;
	ans%=p;
	ans*=x;
	ans%=p;

	ll val = x*k;
	val%=p;
	val*=-1;
	val+=p;
	val%=p;

	ans+=val;
	ans%=p;

	return ans;
}

bool isValid(ll x, ll k, ll p)
{
	x%=p;
	k%=p;

	ll ans = 4;
	ans%=p;
	ans*=x;
	ans%=p;
	ans*=x;
	ans%=p;
	ans*=x;
	ans%=p;

	if(ans==k)
		return true;
	return false;
}



int main()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll p, n, k;

    cin>>n>>p>>k;

    ll arr[n+1];
    ForN1(n)
    	cin>>arr[i];
    arr[0] = -1;
    map<ll,ll> val;
    ll ans = 0;
    ll v;
    sort(arr,arr+n+1);
    ll count =1;
    ForN1(n)
    {
    	if(arr[i]==arr[i-1])
    	{
    		count++;
    	}
    	else
    	{
    		v = findVal(arr[i],k,p);
    		ans+= count*val[v];
    		val[v]+=count;

    		if(isValid(arr[i],k,p))
    		{
    			v = count;
    			v*= (count-1);
    			v/=2;
    			ans+=v;
    		}

    		count = 1;
    	}
    }
    cout<<ans<<endl;
    return 0;
}