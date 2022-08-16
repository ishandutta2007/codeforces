#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define f(i,n) for(i=0;i<n;i++)
#define F first
#define S second

int main()
{
 fast;   
 ll n,i;
 cin >> n;

    
  vector< pair<ll,pair<ll,ll> > > c(n);
    
  f(i,n) cin >> c[i].S.F >> c[i].S.S;    
  
  f(i,n) c[i].F=c[i].S.S-c[i].S.F;
  
  sort(c.begin(),c.end());
    
    ll sum=0;
    
  f(i,n) sum += (c[i].S.F)*(i) + c[i].S.S*(n-i-1);
    
  cout << sum;
    
}