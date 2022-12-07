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

    ll arr[n+1];
    arr[0] = 0;

    ForN1(n)
        cin>>arr[i];
    
    vector<ll> ans;

    for(ll i = n;i>0;i--)
    {
        arr[i]-=arr[i-1];
    }
    // for(ll i = 0;i<=n;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    ll flag;
    ll count =0;
    for(ll i=1;i<=n;i++)
    {
        flag = 1;
        for(ll j=1;j<=n;j++)
        {
            if(i+j>n)
                break;
            if(arr[i+j]!=arr[j])
            {
                flag = 0;
                break;
            }
        }
        if(flag==1)
        {
            count++;
            ans.push_back(i);
        }
    }

    cout<<count<<endl;
    for(ll i=0;i<count;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}