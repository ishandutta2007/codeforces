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
#define mem(x) memset(x,false,sizeof(x))
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
    ll b[n];
    ll maxb=0;
    ll max2b=0;
    ll sumb=0;
    
    ForA1(n)
    {
        cin>>b[i];
        if(b[i]>maxb)
        {
            max2b = maxb;
            maxb = b[i];
        }
        else if(b[i]>max2b)
            max2b = b[i];
        sumb += b[i];
    }
    ll ans = 0;
    ans+= sumb*m;
    
    ll a[m];
    ll suma=0;
    ll flag=0;
    ForA1(m)
    {
        cin>>a[i];
        if(a[i]<maxb)
        {
            cout<<-1<<endl;
            return 0;
        }
        if(a[i]==maxb)
            flag=1;
        suma+=a[i];
    }
    
    ans+= suma - (m*maxb);
    if(flag==0)
    {
        ans+= maxb - max2b;
    }
    
    cout<<ans<<endl;
    return 0;
}