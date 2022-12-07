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

    ll n,m,num;
    cin>>n>>m;

    ll gcd;
    cin>>gcd;
    gcd--;
    ForA1(n-1)
    {
    	cin>>num;
    	num--;
    	gcd = __gcd(gcd,num);
    }

    while(gcd%2==0)
    	gcd/=2;

    ll ans = 0;
    ll i;
    for(i=1; i*i<gcd; i++)
    {
    	if(gcd%i!=0)
    		continue;
    	num = i;

    	while(num<m)
    	{
    		ans+= m-num;
    		num*=2;
    	}

    	num = gcd/i;
    	while(num<m)
    	{
    		ans+= m-num;
    		num*=2;
    	}
    }

    if(i*i==gcd)
    {
    	num = i;

    	while(num<m)
    	{
    		ans+= m-num;
    		num*=2;
    	}
    }

    cout<<ans<<endl;

    return 0;
}