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

ll mymod (ll a)
{
   if(a>0)
      return a;
   return -1*a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,d;
    cin>>n>>d;

    ll arr[n];
    ForA1(n)
    {
      cin>>arr[i];
    }
    if(n==1)
    {
      cout<<"2"<<endl;
      return 0;
    }
    sort(arr,arr+n);

    ll answer = 0;
    ll prev = arr[0]-3*d;

    for(ll i=0;i<n;i++)
    {
      ll possible = arr[i]-d;
      if(possible!= prev)
      {
         ll upper = *std::upper_bound(arr, arr+n, possible);
         ll lower = *(std::upper_bound(arr, arr+n, possible)-1);
         if(mymod(upper-possible)>=d && mymod(possible-lower)>=d)
         {
            prev = possible;
            //cout<<prev<<endl;
            answer++;
         }
      }
      possible = arr[i]+d;
      if(possible!= prev)
      {
         ll upper = *std::upper_bound(arr, arr+n, possible);
         ll lower = *(std::upper_bound(arr, arr+n, possible)-1);
         if(mymod(upper-possible)>=d && mymod(possible-lower)>=d)
         {
            prev = possible;
            //cout<<prev<<endl;
            answer++;
         }
      }
    }

    cout<<answer<<endl;
    return 0;
}