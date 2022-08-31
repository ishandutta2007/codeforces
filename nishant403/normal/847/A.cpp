#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=1;i<=n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

void solve()
{
int n;
cin >> n;
   
int l[n],r[n];
    
f(i,n) cin >> l[i] >> r[i];
    
vi nu;
vector<pii> lis;
    
    f(i,n) 
    {
        if(l[i]==0 && r[i]==0) { nu.pb(i); continue; }
        
       if(l[i] == 0) 
       {
           int l1 = i,r1 = l1;
           
           while(r[r1]!=0)
           {
               r1 = r[r1];
           }
            
           lis.pb({l1,r1});
       }
    }
    
    if(nu.size() > 1)
    {
      for(int i=1;i<nu.size();i++)
      {
       l[nu[i]] = nu[i-1];
       r[nu[i-1]] = nu[i];   
      }
      
        lis.pb({nu[0],nu[nu.size()-1]});  
    }
    else if(nu.size() == 1)
    {
      if(lis.size() > 0)
      {
       r[nu[0]] = lis[0].F;   
       l[lis[0].F] = nu[0];
          
       lis[0].F = nu[0];   
      }
        
      else { cout << "0 0"; exit(0); }  
    }
    
    for(int i=1;i<lis.size();i++)
    {
     l[lis[i].F] = lis[i-1].S;
     r[lis[i-1].S] = lis[i].F;
    }
    
    f(i,n) cout << l[i] << " " << r[i] << "\n";
    
}

signed main()
{
    fast;
    solve();
}