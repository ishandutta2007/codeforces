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
    cout<<n+1<<endl;
    
    ll mod;
    ll make,toadd;
    ll added = 0;
    
    for(ll i=n-1;i>=0;i--)
    {
        make = i;
        mod = (arr[i]+added)%n;
        toadd = (n-mod)+make+n;
        
        cout<<"1 "<<i+1<<" "<<toadd<<endl;
        added+=toadd;
    }
    cout<<"2 "<<n<<" "<<n<<endl;
    return 0;
}