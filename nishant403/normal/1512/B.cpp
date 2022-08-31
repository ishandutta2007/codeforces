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
   
   string s[n];
   f(i,n) cin >> s[i];
    
   pii a={-1,-1},b = {-1,-1};
   
   f(i,n) f(j,n)
       if(s[i][j] == '*')
   {
       if(a.F == -1) a = {i,j};
       else b = {i,j};
   }
    
   if(a.F == b.F)
   {
       if(a.F == 0) s[1][a.S] = s[1][b.S] = '*';
       else s[0][a.S] = s[0][b.S] = '*';
   }
   else if(a.S == b.S)
   {
       if(a.S == 0) s[a.F][1] = s[b.F][1] = '*';
       else s[a.F][0] = s[b.F][0] = '*';
   }
   else
   {
      s[a.F][b.S] = s[b.F][a.S] = '*';
   }
    
   f(i,n) cout << s[i] << '\n'; 
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}