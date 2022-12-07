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

    ll n,x,y;
    ll answer=0;
    cin>>n>>x>>y;
    ll dist=0;

    char prev = 'd';
    for(ll i=0;i<n;i++)
    {
      char a;
      cin>>a;
      if(a=='0' && prev !='0')
      {
         dist++;
      }
      prev = a;
    }
    if(dist==0)
    {
      cout<<"0"<<endl;
      return 0;
    }

    ll cost1 = ((dist-1)*x) + y;
    ll cost2 = dist*y;

    answer = cost1>cost2?cost2:cost1;

    cout<<answer<<endl;

    return 0;
}