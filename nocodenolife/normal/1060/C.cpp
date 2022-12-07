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

    ll n,m;
    cin>>n>>m;
    ll a[n+1], b[m+1], sum_a[n+1], sum_b[m+1];
    a[0] = b[0] = sum_a[0] = sum_b[0] = 0;

    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        sum_a[i] = sum_a[i-1] + a[i];
    }
    for(ll i=1;i<=m;i++)
    {
        cin>>b[i];
        sum_b[i] = sum_b[i-1] + b[i];
    }
    ll maxim;
    cin>>maxim;

    ll min_a[n+1];
    for(ll i=0;i<=n;i++)
    {
        min_a[i] = sum_a[i];
    }
    for(ll i=2;i<=n;i++)
    {
        for(ll j=i;j<=n;j++)
        {
            if((sum_a[j]-sum_a[i-1])<min_a[j-i+1])
            {
                min_a[j-i+1] = (sum_a[j]-sum_a[i-1]);
            }
        }
    }

    ll min_b[m+1];
    for(ll i=0;i<=m;i++)
    {
        min_b[i] = sum_b[i];
    }
    for(ll i=2;i<=m;i++)
    {
        for(ll j=i;j<=m;j++)
        {
            if((sum_b[j]-sum_b[i-1])<min_b[j-i+1])
            {
                min_b[j-i+1] = (sum_b[j]-sum_b[i-1]);
            }
        }
    }


    ll answer = 0;

    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            if(min_a[i]*min_b[j]<=maxim)
            {
                if(i*j > answer)
                    answer = i*j;
            }
        }
    }
    cout<<answer<<endl;
    return 0;
}