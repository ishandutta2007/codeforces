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
    ll arr[n];
    ForA1(n)
      cin>>arr[i];
    sort(arr,arr+n);
    ll counter = 1;
    for(ll i=n-2;i>=0;i--)
    {
      if(arr[i]==arr[i+1])
         counter++;
      else
      {
         if(counter%2==1)
         {
            std::cout << "Conan" << '\n';
            return 0;
         }
         counter = 1;
      }
    }
    if(counter%2==1)
    {
      std::cout << "Conan" << '\n';
      return 0;
    }
    std::cout << "Agasa" << '\n';
    return 0;
}