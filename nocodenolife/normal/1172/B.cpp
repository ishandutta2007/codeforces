#include <bits/stdc++.h>

typedef unsigned long long int ull;
typedef long double ldb;
typedef long long int ll;

#define ForA1(n)  for (ll i=0; i<n; i++)
#define ForA2(n)  for (ll j=0; j<n; j++)
#define ForA3(n)  for (ll k=0; k<n; k++)
#define ForN1(n)  for (ll i=1; i<=n; i++)
#define ForN2(n)  for (ll j=1; j<=n; j++)
#define ForN3(n)  for (ll g=1; g<=n; g++)

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
ll n;
vector<ll> edges[200005];
ll num[200005];
ll ans;

void solve(ll ver)
{
    ll val = num[ver];
    ForN1(val)
    {
        ans*=i;
        ans%=mod;
    }
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

    cin>>n;
    ForN1(n)
    {
        num[i]=0;
        edges[i].clear();
    }
    ans = 1;
    ll u,v;
    ll mini,maxi;
    ForN1(n-1)
    {
        cin>>u>>v;
        mini = min(u,v);
        maxi = max(u,v);
        num[mini]++;
        num[maxi]++;
        edges[mini].push_back(maxi);
    }
    ForN1(n)
        solve(i);
    ans%=mod;
    ans*=n;
    ans%=mod;
    
    cout<<ans<<endl;
    return 0;
}