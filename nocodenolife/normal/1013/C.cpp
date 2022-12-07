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
    map<ll,ll> mp;
    ll n;
    cin >> n;
    vector <ll> a(n * 2);
    for(int i = 0; i < n * 2; i++){
        cin >> a[i];
        mp[a[i]]++;
        if(mp[a[i]] >= n)
        {
            cout<<0;
            return 0;
         }
    }
    sort(a.begin(),a.end());
    ll ans = (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
    for(int i = 1; i < n; i++)ans = min(ans, (a[n * 2 - 1] - a[0]) * (a[i + n - 1] - a[i]));
    cout<<ans;
    return 0;
}