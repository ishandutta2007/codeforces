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
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,m,ta,tb,k,g;
    cin>>n>>m>>ta>>tb>>k;

    ll a[n];
    vector<ll> b;
    ForA1(n)
    {
    	cin>>g;
    	a[i] = g+ta;
    }
    ForA1(m)
    {
    	cin>>g;
    	b.push_back(g);
    }

    if(k>=min(n,m))
    {
    	cout<<-1<<endl;
    	return 0;
    }

    ll ans = -1;
    ll num2;
    ll ini,val;
    std::vector<ll>::iterator low1, low2; 
    for(ll num1=0;num1<=k;num1++)
    {
    	num2 = k-num1;
    	ini = a[num1];

    	low1 = std::lower_bound(b.begin(), b.end(), ini);
    	val = low1 - b.begin();

    	val = val + num2;
    	if(val>=m)
    	{
    		cout<<-1<<endl;
    		return 0;
    	}

    	val = b[val]+tb;
    	ans = max(val,ans);
    }

    cout<<ans<<endl;
    return 0;
}