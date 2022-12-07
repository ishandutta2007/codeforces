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

    ll arr[n];
    ForA1(n)
    {
        cin>>arr[i];
    }
    ll ans = 10000000000000000;
    for(int i=0;i<n;i++)
    {
        ll elec = 0;
        for(int j=0;j<n;j++)
        {
            elec += arr[j]*(abs(i-j) + abs(j) + abs(i));
            elec += arr[j]*(abs(i-j) + abs(j) + abs(i));
        }
        if(elec<ans)
            ans = elec;
    }
    cout<<ans<<endl;
    return 0;
}