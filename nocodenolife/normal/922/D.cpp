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

struct point{
   ll s;
   ll h;
};
typedef struct point str;

bool waytosort(str a, str b)
{
   ll check = a.s * b.h;
   ll check2 = b.s * a.h;
   if(check>check2)
      return true;
   return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll  n;
    ll answer = 0;
    cin>>n;
    str arr[n];
    ForA1(n)
    {
      string k;
      cin>>k;
      ll si = 0;
      ll len = k.length();
      for(ll j=0;j<len;j++)
      {
         if(k[j]=='s')
            si++;
         else
         {
            answer+=si;
         }
      }
      arr[i].s = si;
      arr[i].h = len - si;
   }
   sort(arr,arr+n,waytosort);
   ll si = 0;
   ForA1(n)
   {
      answer+= si*arr[i].h;
      si+= arr[i].s;
   }
    cout<<answer<<endl;

    return 0;
}