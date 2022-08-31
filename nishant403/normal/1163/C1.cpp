#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lld double
#define f(i,n) for(i=0;i<n;i++)
#define F first
#define S second
#define pll pair<long long ,long long >

ll g(set<lld> & s)
{
 ll ans = s.size();
  ans=(ans*(ans-1))/2;
    return ans;
}

int main()
{
ll n,i,j;
    cin >> n;
    ll x[n],y[n];
    
    f(i,n) cin >> x[i] >> y[i];
    
    set<lld> in;
    map<lld,set<lld> > NS;
     
    f(i,n)
     for(j=i+1;j<n;j++)
     {
      if(x[i]==x[j]) in.insert(x[i]); 
      else 
      {
       lld m = ((lld)(y[i]-y[j]))/(x[i]-x[j]);
       lld c = (lld)y[i]-(m*x[i]);   
          NS[m].insert(c);    
      }
     }
      
    ll ans = in.size();
    ll fin= 0;
    
    for(auto z : NS) ans+=(z.second.size());
    
    fin = (ans - in.size() ) *(in.size());
    for(auto z : NS) fin+=(ans - z.second.size())*(z.second.size());
    
    cout << fin/2;
}