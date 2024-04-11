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

    string a,b;
    cin>>a>>b;

    ll n = a.length();
    ll m = b.length();

    ll ans = 0;
    ll count = 0;

    ll adder = 0;
    for(ll i=m-1;i>0;i--)
    {
        if(b[i]!=b[i-1])
            adder++;
    }
    adder%=2;

    for(ll i=0;i<m;i++)
    {
        if(a[i]!=b[i])
            count++;
    }
    count%=2;
    if(count==0)
        ans++;
    for(ll i = m; i<n;i++)
    {
        count+=adder;
        if(a[i]!=b[m-1])
            count++;
        if(a[i-m]!=b[0])
            count++;
        count%=2;
        if(count==0)
            ans++;
    }
    cout<<ans<<endl;

    return 0;
}