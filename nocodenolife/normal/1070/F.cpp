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

    vector<ll> Alice;
    vector<ll> Bob;
    vector<ll> None;

    ll answer =0;
    ll counter =0;

    string type;
    ll inf;
    ForA1(n)
    {
        cin>>type>>inf;
        if(type=="11")
        {
            answer+=inf;
            counter++;
        }
        else if(type=="01")
        {
            Bob.push_back(inf);
        }
        else if(type=="10")
        {
            Alice.push_back(inf);
        }
        else
        {
            None.push_back(inf);
        }
    }
    
    ll min_length = min(Alice.size(), Bob.size());

    sort(Alice.begin(), Alice.end(), greater<ll>());
    sort(Bob.begin(), Bob.end(), greater<ll>());

    for(ll i=0;i<min_length;i++)
    {
        answer+= Alice[i] + Bob[i];
    }
    for(ll i=min_length;i<Alice.size();i++)
    {
        None.push_back(Alice[i]);
    }
    for(ll i=min_length;i<Bob.size();i++)
    {
        None.push_back(Bob[i]);
    }

    sort(None.begin(), None.end(), greater<ll>());

    min_length = min(counter, ll(None.size()));
    for(ll i=0;i<min_length;i++)
    {
        answer+= None[i];
    }

    cout<<answer<<endl;
    return 0;
}