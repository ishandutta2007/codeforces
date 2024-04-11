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

    ll powers[41];
    for(ll i=0;i<41;i++)
    {
      powers[i] = pow(2,i);
    }

    ll n;
    cin>>n;
    ll arr[n];
    ForA1(n)
    {
      cin>>arr[i];
    }
    sort(arr,arr+n);
    ll answer = 0;
    ForA1(n)
    {
      ll rem = 1;
      for(ll j=0;j<41;j++)
      {
         ll c = powers[j]-arr[i];
         if(c<0)
            continue;
         if(c==arr[i] && (((i-1>=0)&&(arr[i-1]==arr[i]))||((i+1<n)&&(arr[i+1]==arr[i]))))
         {
            rem = 0;
            break;
         }
         if(c==arr[i])
            continue;
         if (binary_search(arr, arr + n, c))
         {
            rem = 0;
            break;
         }
      }
      answer+=rem;
    }

    cout<<answer<<endl;
    return 0;
}