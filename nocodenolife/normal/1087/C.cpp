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
    ll temp;
    ll x[3], y[3];
    ForA1(3)
    {
        cin>>x[i]>>y[i];
    }
    
    ForA2(3)
    {
        ForA1(2)
        {
            if(y[i]>y[i+1])
            {
                temp = x[i];
                x[i]=x[i+1];
                x[i+1]=temp;
                
                temp = y[i];
                y[i]=y[i+1];
                y[i+1]=temp;
            }
        }
    }
    ll mid = y[1];
    ll mini=x[0],maxi=x[0];
    ForA1(3)
    {
        // cout<<x[i]<<" "<<y[i]<<endl;
        if(x[i]>maxi)
            maxi=x[i];
        if(x[i]<mini)
            mini=x[i];
    }
    
    ll answer = maxi-mini+1;
    answer+=y[2]-y[1];
    answer+=y[1]-y[0];
   
    
    cout<<answer<<endl;
    for(ll i=mini;i<=maxi;i++)
    {
        cout<<i<<" "<<y[1]<<endl;
    }
    for(ll i=y[1]+1;i<=y[2];i++)
    {
        cout<<x[2]<<" "<<i<<endl;
    }
    for(ll i=y[1]-1;i>=y[0];i--)
    {
        cout<<x[0]<<" "<<i<<endl;
    }
    return 0;
}