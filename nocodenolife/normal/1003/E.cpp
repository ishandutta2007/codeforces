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

    ll n,d,k;
    cin>>n>>d>>k;
    if(d==1)
    {
      if(n==2)
      {
         cout<<"YES"<<endl<<"1 2"<<endl;
      }
      else
      {
         cout<<"NO"<<endl;
      }
      return 0;
    }
    if(k==1)
    {
      cout<<"NO"<<endl;
      return 0;
    }
    if(n<=d)
    {
      cout<<"NO"<<endl;
      return 0;
    }

    if(k==2)
    {
      if(n!=d+1)
      {
         cout<<"NO"<<endl;
         return 0;
      }
      else
      {
         cout<<"YES"<<endl;
         for(ll i=1;i<=d;i++)
         {
           cout<<i<<" "<<i+1<<endl;
         }
         return 0;
      }
    }

    if(d%2==0)
    {
      d = d/2;
      double checker = log((n-1)*(k-2)+k);
      double maximum = (d)*log(k-1) + log(k);
      if(checker-maximum > pow(10,-14))
      {
         cout<<"NO"<<endl;
         return 0;
      }
      d*=2;
    }
    else
    {
      d = d/2;
      double checker = log((n-1)*(k-2)+k);
      double maximum = (d+1)*log(k-1) + log(2);
      if(checker-maximum > pow(10,-14))
      {
         cout<<"NO"<<endl;
         return 0;
      }
      d = d*2+1;
    }


    cout<<"YES"<<endl;



    vector<ll> avail;
    vector<ll> next;
    for(ll i=1;i<=d;i++)
    {
      cout<<i<<" "<<i+1<<endl;
    }
    n-=d+1;
    if(n==0)
      return 0;


    ll g = d+2;
    for(ll i=2;i<=d;i++)
    {
      avail.clear();
      next.clear();
      ll looper = min(i-1,d+1-i);
      for(ll j=0;j<k-2;j++)
      {
         cout<<i<<" "<<g<<endl;
         avail.pb(g);
         g++;
         n--;
         if(n==0)
           return 0;
      }
      looper--;
      while(looper!=0)
      {
         for(ll c=0;c<avail.size();c++)
         {
            ll start = avail[c];
            for(ll j=0;j<k-1;j++)
            {
               cout<<start<<" "<<g<<endl;
               next.pb(g);
               g++;
               n--;
               if(n==0)
                 return 0;
            }
         }
         avail = next;
         next.clear();
         looper--;
      }
    }

    return 0;
}