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
    
    vector<ll> arr[n];
    ll m,num;
    ll largest = 0;
    ForA1(n)
    {
        cin>>m;
        for(ll j=0;j<m;j++)
        {
            cin>>num;
            arr[i].push_back(num);
            if(num>largest)
                largest = num;
        }
    }
    
    ForA1(n)
    {
        sort(arr[i].begin(), arr[i].end());
    }
    
    ll answer = 0;
    ForA1(n)
    {
       answer+=( largest - arr[i][arr[i].size()-1]) * arr[i].size();
    }
    cout<<answer<<endl;
    
    return 0;
}