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
#define all(x) x.begin(),x.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    if(a == 0) return 0;
    b %= (M - 1);  //M must be prime here
    
    int res = 1;
    
    while(b > 0)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}

bool check(pii x,pii y,pii z)
{
    pii xx ,yy;
    
    xx.F = y.F - x.F;
    xx.S = y.S - x.S;
    
    yy.F = z.F - y.F;
    yy.S = z.S - y.S;
    
    int rr = (xx.F*yy.F) + (xx.S*yy.S);
    
    if(rr >= 0) return 0;
    
    return 1;
}

void solve()
{
   int n;
    cin >> n;
    
   pii a[n];
    f(i,n) cin >> a[i].F >> a[i].S;
    
   vi res;
   res.pb(0);
   res.pb(1);
   
   for(int i=2;i<n;i++) 
   {
       //find a good position to insert a[i]
       int pos = -2;
       
       //case 1 : initially
       if(check(a[i],a[res[0]],a[res[1]])) pos = 0;
       
       //case 2 : middle 
       for(int j=1;j<res.size();j++)
       {
           int ff = 1;
           
           if(!check(a[res[j-1]],a[i],a[res[j]])) ff = 0;
           
           if(j > 1)
           {
               if(!check(a[res[j-2]],a[res[j-1]],a[i])) ff = 0;
           }
           
           if(j + 1 < (int)res.size())
           {
               if(!check(a[i],a[res[j]],a[res[j+1]])) ff = 0;
           }
           
           if(ff) pos = j;
       }
       
       //case 3 : ending
       if(check(a[res[(int)res.size()-2]],a[res.back()],a[i])) pos = -1;
       
       assert(pos != -2);
           
       vi nex;
       
       if(pos == 0)
       {
           nex.pb(i);
           for(auto v : res) nex.pb(v);
           swap(nex,res);
       }
       else if(pos == -1) 
       {
           res.pb(i);
       }
       else
       {
           f(j,pos) nex.pb(res[j]);
           nex.pb(i);
           for(int j=pos;j<res.size();j++) nex.pb(res[j]);
           swap(nex,res);
           
       }
   }
    
   for(auto x : res) cout << x + 1 << ' '; 
}

signed main()
{
    fast;
    
    int t = 1;
    
  //  cin >> t;
    
    while(t--)
        
    solve();
}