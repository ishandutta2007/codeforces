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
#define vll vector<ll>
#define F first
#define S second
#define debug(x)    cerr << #x << " = " << x << endl;
#define mem(x) memset(x,0,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    ll n;
    cin>>n;

    ll val[n];
    ForA1(n)
    {
        cin>>val[i];
    }
    ll siz = n * (n-1) /2;
    ll sec[siz];
    ll k = 0;

    ForA1(n)
    {
        for(ll j=i+1;j<n;j++)
        {
            sec[k] = val[i]+val[j];
            k++;
        }
    }


    sort(sec,sec+siz);

    ll ans = 0;
    ll count = 1;
    ForN1(siz-1)
    {
        if(sec[i]==sec[i-1])
        {
            count++;
        }
        else
        {
            if(count>ans)
                ans = count;
            count = 1;
        }
    }
    if(count>ans)
        ans = count;

    cout<<ans<<endl;

    return 0;
}