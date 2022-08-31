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


void solve()
{
   int n;
    cin >> n;
    
   string s;
    cin >> s;
    
   int ff = 1;
    
   for(auto x : s)
       if(x != s[0]) ff = 0;
       
   if(ff == 1)
   {
       cout << (n+2)/3 << '\n';
       return;
   }
    
   int id = -1;
    
   f(i,n-1)
       if(s[i] == 'L' && s[i+1] == 'R') id = i+1;
   
   if(s[n-1] == 'L' && s[0] == 'R') id = 0;     
  
   string t;
    
   f(i,n) t+=s[(id+i)%n];
       
   int res = 0;
    
   f(i,n)
   {
       int cnt = 0;
       
       int j = i;
       
       while(j < n && t[j] == t[i]) cnt++,j++;
       
       res+=cnt/3;
       
       i = j-1;
   }
    
   cout << res << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}