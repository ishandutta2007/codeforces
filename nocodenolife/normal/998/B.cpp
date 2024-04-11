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
int mymod(int a)
{
   if(a>0)
      return a;
   return -1*a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,b;
    cin>>n>>b;
    int arr[n];
    int odd = 0;
    int even = 0;
    vector<int> costs;

    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    for(int i=0;i<n-1;i++)
    {
      if(arr[i]%2==0)
      {
         even++;
      }
      else
         odd++;
      if(even == odd)
      {
         int topay = mymod(arr[i]-arr[i+1]);
         costs.pb(topay);
      }
    }
    int answer=0;
    sort(costs.begin(),costs.end());

    for(int i=0;i<costs.size();i++)
    {
      if(costs[i]<=b)
      {
         b-=costs[i];
         answer++;
         //cout<<costs[i]<<endl;
      }
      else
      {
         break;
      }
    }
    cout<<answer<<endl;

    return 0;
}