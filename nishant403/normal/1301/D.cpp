#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    int res = 1;
    
    while(b)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}
    
vector<pair<int,char> > ans;

void print()
{
   cout << ans.size() << '\n';
    
   for(auto z : ans) cout << z.F << " "<<z.S<<'\n';
    
   exit(0);
}

void solve()
{
   int n,m,k;
   cin >> n >> m >> k;
    
   int tot = (4*n*m) - (2*n) - (2*m);
    
   if(k>tot)
   {
       cout <<"NO\n";
       return;
   }
    
   cout << "YES\n";
    
   if(n==1) 
   {
       ans.pb({min(k,m-1),'R'});
       k-=ans.back().F; 
       if(k == 0) print();
       
       ans.pb({min(k,m-1),'L'});
       k-=ans.back().F; 
       if(k == 0) print();
   }
    
   if(m == 1)
   {
       ans.pb({min(k,n-1),'D'});
       k-=ans.back().F; 
       if(k == 0) print();
       
       ans.pb({min(k,n-1),'U'});
       k-=ans.back().F; 
       if(k == 0) print();
   }
    
    
    
    
   for(int i=1;i<n;i++)
   {
       
   ans.pb({1,'D'});
   k-=ans.back().F; 
   if(k == 0) print();
    
   ans.pb({min(k,m-1),'R'}); 
   k-=ans.back().F; 
   if(k == 0) print();
   
   ans.pb({min(k,m-1),'L'}); 
   k-=ans.back().F; 
   if(k == 0) print();    
   }
    
   //go up
   ans.pb({min(k,n-1),'U'});
   k-=ans.back().F; 
   if(k == 0) print();    
    
   f(i,m-1)
   {
    ans.pb({1,'R'});  
    k-=ans.back().F; 
    if(k == 0) print();    
   
   ans.pb({min(k,n-1),'D'}); 
   k-=ans.back().F; 
   if(k == 0) print();
   
   ans.pb({min(k,n-1),'U'}); 
   k-=ans.back().F; 
   if(k == 0) print();    
   }
    
  ans.pb({min(k,m-1),'L'}); 
  print();  
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}