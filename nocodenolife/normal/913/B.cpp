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
    std::cin >> n;
    ll arr[n-1];
    ll counter[n];
    ForA1(n)
    {
      counter[i]=-1;
    }
    ForA1(n-1)
    {
      cin>>arr[i];
      counter[arr[i]-1] = 0;
    }
    ForA1(n-1)
    {
      if(arr[i]!=1)
      {
         arr[arr[i]-2]=0;
      }
    }
    ForA1(n-1)
    {
      if(arr[i]!=0)
      {
         if(counter[arr[i]-1] == -1)
            counter[arr[i]-1]++;
         counter[arr[i]-1]++;
      }
    }
    ForA1(n)
    {
      if(counter[i]!=-1 && counter[i]<3)
      {
         cout<<"No"<<endl;
         return 0;
      }
    }
    cout<<"Yes"<<endl;
    return 0;
}