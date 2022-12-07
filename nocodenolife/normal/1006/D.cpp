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
    ll n;
    cin>>n;

    string a,b;
    cin>>a>>b;
    ll ans = 0;
    for(ll i=0,j=n-1; i<n/2; j--,i++)
    {
        if((a[i]==b[j] && a[j]==b[i])||(a[j]==b[j]&&b[i]==a[i])||(a[j]==a[i]&&b[i]==b[j]))
        {
            continue;
        }
        else if(a[i]==b[i]||a[i]==b[j]||a[j]==b[i]||a[j]==b[j]||b[i]==b[j])
        {
            ans++;
            continue;
        }
        else
        {
            ans+=2;
        }
    }
    
    if(n%2==1)
    {
        ll mid = n/2;
        if(a[mid]!=b[mid])
            ans++;
    }
    
    cout<<ans<<endl;
    
    return 0;
}