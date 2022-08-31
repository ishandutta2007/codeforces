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
   int n,m;
   cin >> n >> m;
    
   string s;
   cin >> s;
    
   pii x_range = {0,0},y_range = {0,0}, cord = {0,0};
   
   pii cell = {1,1};
    
   for(auto x : s)
   {
       if(x == 'R') cord.F++;
       else if(x == 'L') cord.F--;
       else if(x == 'U') cord.S++;
       else cord.S--;
           
       x_range.F = min(x_range.F, cord.F);
       x_range.S = max(x_range.S, cord.F);
       
       y_range.F = min(y_range.F, cord.S);
       y_range.S = max(y_range.S, cord.S);
       
       //here determine the cell that works upto this point
       if((x_range.S - x_range.F + 1) <= m && (y_range.S - y_range.F + 1) <= n)
       {
           cell = {- x_range.F + 1, y_range.S + 1};
       }
   }
    
   cout << cell.S  << ' ' << cell.F  << '\n'; 
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}