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

    string s;
    cin>>s;

    ll ans = 0;
    ll n = s.length();
    ll must;
    ll mini;
    for(ll i=0;i<n-2;i++)
    {
    	must= n-8-i;
    	if(must>0)
    		ans+=must;
    	must = min(i+7,n-1);
    	mini = must+1;

    	for(ll j=1;j<=3;j++)
    	{
    		for(ll k=i;k<must;k++)
    		{
    			if(k+(2*j) >= n)
    				break;
    			if(s[k]==s[k+j] && s[k]==s[k+(2*j)])
    			{
    				mini = min(mini,k+(2*j));
    			}
    		}
    	}

    	ans += (must+1)-mini;
    }

    cout<<ans<<endl;

    return 0;
}