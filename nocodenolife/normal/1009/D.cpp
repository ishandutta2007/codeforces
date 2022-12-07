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

ll phi(ll n)
{
    ll result = n;
    for (ll p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;
    cin>>n>>m;
    if(m<n-1)
    {
      cout<<"Impossible"<<endl;
      return 0;
    }
    ll max = 0;
    for(ll i=2;i<=n;i++)
    {
      max += phi(i);
    }
    if(max<m)
    {
      cout<<"Impossible"<<endl;
      return 0;
    }
    cout<<"Possible"<<endl;
    for(ll i=1;i<n;i++)
    {
      for(ll j=i+1;j<=n;j++)
      {
         if(__gcd(i,j)==1)
         {
            cout<<i<<" "<<j<<endl;
            m--;
            if(m==0)
               return 0;
         }
      }
    }

    return 0;
}