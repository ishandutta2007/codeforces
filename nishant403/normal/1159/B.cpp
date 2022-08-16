#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define f(i,n) for(i=0;i<n;i++)
#define F first
#define S second
#define pb push_back
#define pll pair<long long,long long>
#define vl vector<ll> 
#define int long long  

signed main()
{
 fast;   
 ll n,k,i,j;
 string s;
    
  cin >> n;
    
  vector<pll> a(n);
    
    f(i,n) { cin >> a[i].F; a[i].S=(i+1); }
    
    sort(a.begin(),a.end());
    
    set<ll,greater<ll> > x;
    f(i,n) x.insert(i+1);
    
   k = 999999999999;
    
    f(i,n-1)
    {
     x.erase(a[i].S);
        
     ll pp = *(x.begin());
     ll kk = *(x.rbegin());
        
    if(pp!=a[i].S) k = min(k,a[i].F/(ll)abs(a[i].S - pp)); 
    if(kk!=a[i].S) k = min(k,a[i].F/(ll)abs(a[i].S - kk));
    }
    cout << k;
}