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

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    ll a,b;
    ll first, second;
    cin>>a>>b;
    ll answer = a*b;
    first = a;
    second = b;
    ll min = 4000000000000000001;
    ForA1(n-1)
    {
        cin>>a>>b;
        ll mul = a*b / gcd(a,b);
        a = max(a,b);
        if(a<min)
            min = a;
        answer = gcd(answer,mul);
    }
    if(answer==1)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    ll i;
    if(gcd(answer,first)!=1)
    {
        answer = gcd(answer,first);
    }
    else
    {
        answer = gcd(answer,second);
    }
    for(ll i=2;i*i<=answer;i++)
    {
        if(answer%i==0)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<answer<<endl;
    return 0;
}