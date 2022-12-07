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

ll powmodp(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
       if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
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

    ll n;
    cin>>n;

    ll arr[n];
    vector<pair<ll,ll>> segments;

    map<ll,ll> mini;
    map<ll,ll> maxi;
    ForA1(n)
    {
    	cin>>arr[i];
    	if(mini[arr[i]]==0)
    		mini[arr[i]] = i+1;
    	maxi[arr[i]] = i+1;
    }

    ForA1(n)
    {
    	if(mini[arr[i]] == i+1)
    	{
    		segments.push_back(make_pair(mini[arr[i]],maxi[arr[i]]));
    	}
    }

    sort(segments.begin(),segments.end());

    ll num = 1;
    ll cur_min = segments[0].first;
    ll cur_max = segments[0].second;

    // for(ll i=0;i<segments.size();i++)
    // {
    // 	cout<<segments[i].first<<" "<<segments[i].second<<endl;
    // }

    for(ll i=1;i<segments.size();i++)
    {
    	if(segments[i].first <= cur_max)
    	{
    		cur_max = max(cur_max,segments[i].second);
    	}
    	else
    	{
    		num++;
    		cur_min = segments[i].first;
    		cur_max = segments[i].second;
    	}
    }
    // cout<<num<<endl;

    num--;
    ll ans = powmodp(2,num,mod);

    cout<<ans<<endl;
    return 0;
}