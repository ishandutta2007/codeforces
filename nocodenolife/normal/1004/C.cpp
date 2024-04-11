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

    int n;
    cin>>n;

    int arr[n];
    map<int, int> m;

    ll answer = 0;
    ll right = 0;
    ForA1(n)
    {
      cin>>arr[i];
      m[arr[i]]++;
      if(m[arr[i]]==1)
         right++;
    }

    ForA1(n-1)
    {
      if(m[arr[i]]==1)
      {
         right--;
         answer+= right;
         continue;
      }
      else if(m[arr[i]]==-1)
      {
         right--;
         continue;
      }
      else if(m[arr[i]]<0)
      {
         m[arr[i]]++;
      }
      else
      {
         answer+= right;
         m[arr[i]] = -(m[arr[i]]-1);
         continue;
      }
    }
    cout<<answer<<endl;
    return 0;
}