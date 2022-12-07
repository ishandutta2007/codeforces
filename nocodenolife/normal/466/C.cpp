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

#define modder 1000000007
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define F first
#define S second
#define mem(x) memset(x,-1,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    ll sum=0;
    
    cin>>n;
    ll arr[n];
    ForA1(n)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    if(sum%3!=0)
    {
        cout<<0<<endl;
        return 0;
    }
    
    sum/=3;
    // cout<<sum<<endl;
    vector<ll> possible;
    
    ll temp=0;
    ForA1(n)
    {
        temp+=arr[i];
        if(temp==sum)
            possible.push_back(i);
    }
    
    temp=0;
    ll c;
    ll answer =0;
    for(ll i=n-1;i>=0;i--)
    {
        temp+=arr[i];
        if(temp==sum)
        {
            c = lower_bound(possible.begin(), possible.end(), i-1) - possible.begin();
            // c--;
            if(c>0)
                answer+=c;
        }
    }
    
    cout<<answer<<endl;
    return 0;
}