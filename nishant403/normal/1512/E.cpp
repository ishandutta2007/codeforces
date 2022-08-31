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
   int n,l,r,s;
    cin >> n >> l >> r >> s;
    
   int nums = r - l + 1;
    
   int mn = (nums*(nums + 1))/2;
   int mx = 0;
    
   f(i,nums) mx += n - i;
    
   if(s < mn || s > mx)
   {
       cout << -1 << '\n';
       return;
   }
   
   vector<int> rr;
   int ss = 0;
    
   for(int i=n;i>=1;i--)
   {
      int sum_need = s - ss;
      int elm_need = nums - (int)rr.size();
       
      if(elm_need == 0) break;
       
      if(sum_need >= i + ((elm_need*(elm_need - 1))/2))
      {
          rr.pb(i);
          ss += i;
      }
   }
    
   if(rr.size() != nums) 
   {
       cout << -1 << '\n';
       return;
   }
    
    assert(ss == s);
    
   vector<bool> vis(n+1,0);
    for(auto x : rr) vis[x] = 1;
    
   vector<int> num2;
    f(i,n) if(vis[i+1] == 0) num2.pb(i+1);
        
        
   f(i,l-1) cout << num2[i] << ' ';
   f(i,nums) cout << rr[i] << ' ';
   f(i,n - r) cout << num2[n - nums - i - 1] << ' ';
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