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
struct porufu{
   ll val;
   ll idx;
};
typedef struct porufu point;

bool wayto(point a, point b)
{
   return a.val<b.val;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,x;
    cin>>n>>x;
    point arr[n];
    ForA1(n)
    {
      cin>>arr[i].val;
      arr[i].idx = i;
    }
    sort(arr,arr+n,wayto);

    ForN1(n-1)
    {
      if(arr[i].val==arr[i-1].val)
      {
         std::cout << "0" << '\n';
         return 0;
      }
    }

    point arr2[n];
    ForA1(n)
    {
      arr2[i].val = (arr[i].val & x);
      arr2[i].idx = arr[i].idx;
    }
    sort(arr2,arr2+n,wayto);
    ll one = 0;
    ll two = 0;
    while(one!=n && two!=n)
    {
      if(arr[one].val>arr2[two].val)
         two++;
      else if(arr[one].val<arr2[two].val)
         one++;
      else
      {
         if(arr[one].idx == arr2[two].idx)
         {
            two++;
         }
         else
         {
            std::cout << "1" << '\n';
            return 0;
         }
      }
    }

    ForN1(n-1)
    {
      if(arr2[i].val==arr2[i-1].val)
      {
         std::cout << "2" << '\n';
         return 0;
      }
    }

    std::cout << "-1" << '\n';
    return 0;
}