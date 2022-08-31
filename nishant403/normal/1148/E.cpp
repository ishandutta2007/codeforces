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


void solve()
{
   int n;
   cin >> n;
    
   vector<pii> a(n); 
    f(i,n) cin >> a[i].F;
    f(i,n) a[i].S = i + 1;
    
   vector<pii> b(n);
    f(i,n) cin >> b[i].F;
    f(i,n) b[i].S = i + 1;
  
   sort(all(a));
   sort(all(b));
   
   vector<pair<int,pii> > res; 
   
   vector<pii> go;
    
   f(i,n)
   {
       pii z = {b[i].F - a[i].F , a[i].S};
       
       if(z.F > 0) go.pb(z);
       
       while(!go.empty() && z.F < 0)
       {
           auto x = go.back();

           int d_move = min(-z.F,x.F);

           res.pb({d_move,{x.S,z.S}});
           
           if(x.F > d_move)
           {
               go.back().F -= d_move;
               z.F = 0;
           }
           else
           {
               go.pop_back();
               z.F += d_move;
           }
        }
       
        if(z.F < 0)
        {
            cout <<"NO\n";
            return;
        }
   }
    
   if(!go.empty())
   {
       cout <<"NO\n";
       return;
   }
    
   cout << "YES\n";
   cout << res.size() << '\n';
   for(auto x : res) cout << x.S.F << ' ' << x.S.S <<  ' ' << x.F << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}