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
    if(n==1)
    {
        cin>>n;
        cout<<n<<endl;
        return 0;
    }
    ll arr[n];
    ll neg = 0;
    ll zer = 0;
    ll pos = 0;
    ForA1(n)
    {
        cin>>arr[i];
        if(arr[i]<0)
            neg++;
        else if(arr[i]==0)
            zer++;
        else
            pos++;
    }
    if(neg==0)
    {
        ll mini = 10000000000;
        ll sum = 0;
        for(ll i=0;i<n;i++)
        {
            if(arr[i]<mini)
                mini = arr[i];
            sum+=arr[i];
        }
        ll answer = sum - 2*mini;
        cout<<answer<<endl;
        return 0;

    }
    if(pos==0)
    {
        ll maxi = -10000000000;
        ll sum = 0;
        for(ll i=0;i<n;i++)
        {
            if(arr[i]>maxi)
                maxi = arr[i];
            sum-=arr[i];
        }
        ll answer = sum+ 2*maxi;
        cout<<answer<<endl;
        return 0;
    }

    ll sum = 0;
    for(ll i=0;i<n;i++)
    {
        if(arr[i]<=0)
        {
            sum-= arr[i];
        }
        else{
            sum+=arr[i];
        }
    }
    cout<<sum<<endl;

    

    return 0;
}