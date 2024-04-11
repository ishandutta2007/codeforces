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

    ll n,req;
    std::cin >> n>>req;
    ll price[n];
    ForA1(n)
    {
      std::cin >> price[i];
    }

    ForN1(n-1)
    {
      if(price[i]>price[i-1]*2)
         price[i] = price[i-1]*2;
    }
    for(ll i=n-2;i>=0;i--)
    {
      if(price[i]>price[i+1])
         price[i] = price[i+1];
    }

    ll counter = n-1;
    ll answer = 0;
    ll max = -1;
    while(counter>=0 && req!=0)
    {
      ll can = req/((ll)(pow(2,counter)));
      ll possible = answer + ((can+1)*price[counter]);
      if(max==-1)
         max = possible;
      else
         if(max>possible)
            max = possible;
      answer += can*price[counter];
      req -= can * ((ll)(pow(2,counter)));
      counter--;
    }

    if(max==-1)
    {
      cout<<answer<<endl;
      return 0;
    }
    answer = answer>max?max:answer;
    cout<<answer<<endl;
    return 0;
}