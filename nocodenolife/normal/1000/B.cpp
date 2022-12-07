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

    int n,m;
    cin>>n>>m;
    int arr[n];
    ForA1(n)
    {
      cin>>arr[i];
    }

    if(n%2==1)
    {
      int increased = m - arr[n-1] -1;
      int on = 0;
      int off = m - arr[n-1];
      for(int i=n-2;i>=0;i--)
      {
         if(i%2==0)
         {
            if(arr[i+1]!=arr[i]+1)
            {
               int best = off - on + (arr[i+1]-arr[i]-1);
               if(best>increased)
                  increased = best;
            }
            off += arr[i+1]-arr[i];
         }
         else
         {
            if(arr[i+1]!=arr[i]+1)
            {
               int best = off - on -1;
               if(best>increased)
                  increased = best;
            }
            on += arr[i+1]-arr[i];
         }
      }
      if(arr[0]!=1)
      {
         int best = off-on-1;
         if(best>increased)
            increased = best;
      }
      on += arr[0];
      cout<<on+increased<<endl;
    }

    else
    {
      int increased = 0;
      int on = m - arr[n-1];
      int off = 0;
      for(int i=n-2;i>=0;i--)
      {
         if(i%2==0)
         {
            if(arr[i+1]!=arr[i]+1)
            {
               int best = off - on + (arr[i+1]-arr[i]-1);
               if(best>increased)
                  increased = best;
            }
            off += arr[i+1]-arr[i];
         }
         else
         {
            if(arr[i+1]!=arr[i]+1)
            {
               int best = off - on -1;
               if(best>increased)
                  increased = best;
            }
            on += arr[i+1]-arr[i];
         }
      }
      if(arr[0]!=1)
      {
         int best = off - on -1;
         if(best>increased)
            increased = best;
      }
      on += arr[0];
      cout<<on+increased<<endl;
    }

    return 0;
}