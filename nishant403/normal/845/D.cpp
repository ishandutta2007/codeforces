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
    
   int speed = -1;
   int osigns = 0;
   int res = 0;
    
   int t,s;
    
   stack<int> st; 
    
   while(n--)
   {
       cin >> t;
       
       if(t == 1) cin >> speed;
       else if(t == 2) res+=osigns,osigns = 0;
       else if(t == 3)
       {
           cin >> s;
           st.push(s);
       }
       else if(t == 4) osigns = 0;
       else if(t == 5)
       {
           while(!st.empty()) st.pop();
       }

       else osigns++;
           
       while(!st.empty() && (st.top()) < speed) res++,st.pop();
   }
    
   cout << res;
}

signed main()
{
    fast;
    
    solve();
}