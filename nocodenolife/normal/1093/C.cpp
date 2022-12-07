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
#define vi vector<int>
#define pair pair<int,int>
#define F first
#define S second
#define mem(x) memset(x,0,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    ll b[n/2];
    ll a[n];

    ForA1(n/2)
    {
        cin>>b[i];
    }

    ll max = -1;
    ll large,small;
    for(ll i=0;i<n/2;i++)
    {
        large = b[i];
        if(max!=-1 && large>max)
        {
            large = max;
        }
        small = b[i]-large;
        if(i>0 && small < a[i-1])
        {
            small = a[i-1];
            large = b[i] - small;
        }

        a[i] = small;
        a[n-i-1] = large;

        max = large;
    }

    for(ll i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}