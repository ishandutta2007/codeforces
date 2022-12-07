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

    ll n,q;
    cin>>n>>q;
    ll powers[41];
    for(ll i=0;i<41;i++)
    {
      powers[i] = pow(2,i);
    }

    ll numbers[41] = {0};

    ForA1(n)
    {
      ll k;
      cin>>k;
      ll base2 = log2(k);
      numbers[base2]++;
    }

    ForA1(q)
    {
      ll w;
      cin>>w;
      ll answer = 0;
      for(ll i = 40;i>=0;i--)
      {
         if(w>=powers[i] && numbers[i]>0)
         {
            ll can = w/powers[i];
            if(numbers[i]>=can)
            {
               w -= can*powers[i];
               answer+=can;
            }
            else
            {
               w -= numbers[i]*powers[i];
               answer+= numbers[i];
            }
         }
      }

      if(w==0)
      {
         cout<<answer<<endl;
      }
      else
      {
         cout<<"-1"<<endl;
      }

    }


    return 0;
}