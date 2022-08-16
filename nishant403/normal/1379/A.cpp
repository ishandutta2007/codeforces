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

string a = "abacaba";

bool check(string s)
{
    int cnt = 0;
    int n = s.length();
    
    f(i,n-6)
    {
        int ff = 1;
        
        f(j,7) if(s[i+j] != a[j]) ff = 0;
            
        cnt+=ff;
    }
    
    if(cnt == 1)
    {
        cout <<"Yes\n";
        cout << s << '\n';
        return 1;
    }
    
    return 0;
}

void solve()
{
   int n;
   string s;
 cin >> n >> s;
    
   for(int i=0;i<n-6;i++) 
   {
       int f = 1;
       
       for(int j=0;j<7;j++)
       {
          if(s[i+j] == '?') continue;
          if(s[i+j] == a[j]) continue;
          f = 0; 
       }
       
       if(f == 1)
       {
           string t = s;
           for(int j=0;j<7;j++) t[i+j] = a[j];
           for(auto & x : t) if(x == '?') x = 'd';
           if( check(t) ) return;
       }
   }
    
   cout <<"No\n"; 
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}