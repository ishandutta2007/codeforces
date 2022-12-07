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
#define mem(x) memset(x,-1,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll a,b,i;
    cin>>a>>b;
    
    vector<ll> factor_a;
    vector<ll> factor_b;
    
    for(i=1;i*i<a;i++)
    {
        if(a%i==0)
        {
            factor_a.push_back(i);
            factor_a.push_back(a/i);
        }
    }
    if(i*i==a)
    {
        factor_a.push_back(i);
    }
    
    for(i=1;i*i<b;i++)
    {
        if(b%i==0)
        {
            factor_b.push_back(i);
            factor_b.push_back(b/i);
        }
    }
    if(i*i==b)
    {
        factor_b.push_back(i);
    }
    
    sort(factor_a.begin(), factor_a.end());
    sort(factor_b.begin(), factor_b.end());
    
    ll fact1,fact2,fir,sec;
    ll c=b+a;
    ll ans = c+1+1+c;
    for(i=2;i*i<=c;i++)
    {
        if(c%i==0)
        {
            fact1 = i;
            fact2 = c/i;
            
            fir = (upper_bound(factor_a.begin(), factor_a.end(),fact1) - factor_a.begin())-1;
            fir = factor_a[fir];
            sec = a/fir;
            
            if((fir<=fact1 && sec<=fact2)||(fir<=fact2&&sec<=fact1))
            {
                ans = fact1+fact2+fact1+fact2;
            }
            
            fir = (upper_bound(factor_b.begin(), factor_b.end(),fact1) - factor_b.begin())-1;
            fir = factor_b[fir];
            sec = b/fir;
            
            if((fir<=fact1 && sec<=fact2)||(fir<=fact2&&sec<=fact1))
            {
                ans = fact1+fact2+fact1+fact2;
            }
        }
    }
    cout<<ans<<endl;
    
    
    return 0;
}