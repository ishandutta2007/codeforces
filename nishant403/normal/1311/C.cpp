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
   int n,m;
   cin >> n >> m;
       
   string s;
   cin >> s;
    
   int cn[26] = {0};
    int res[26] = {0};
    
   int a[m];
   f(i,m) cin >> a[i];
   f(i,m) a[i]--;
    
   sort(a,a+m); 
   int gone = 0;
    
   f(i,m)
   {
       while(gone <= a[i])
       {
           cn[s[gone]-'a']++;
           gone++;
       }
       
       f(j,26) res[j]+=cn[j];
   }
   
   while(gone <= n-1)
   {
       
           cn[s[gone]-'a']++;
           gone++;
   }
    
       f(j,26) res[j]+=cn[j];
   
    
    
   f(i,26) cout << res[i] <<" ";
   cout << '\n'; 
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}