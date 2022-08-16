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


vi base4(int x)
{
    vi res;
    
    while(x>0)
    {
        res.pb(x%4);
        x/=4;
    }
    
    return res;
}

vi seq;

int get(vi & x)
{
    int res = 0;
    
    reverse(x.begin(),x.end());
    
    for(auto z : x)
    {
        res<<=2;
        res+=z;
    }
    
    return res;
}

void solve()
{
   int n;
    cin >> n;
    
   int tot = (n+2)/3;
   
   int start = 1;
   
   for(auto x : seq)
   {
       if(tot > x)
       {
           tot-=x;
       }
       else
       {
           start = x;
           break;
       }
   }
    
   int first = start + tot-1;
   
   vi go = base4(first);
   vi go1;
   vi go2;
    
   for(auto x : go) 
   {
       if(x == 0) go1.pb(0),go2.pb(0);
       else if(x == 1) go1.pb(2),go2.pb(3);
       else if(x == 2) go1.pb(3),go2.pb(1);
       else go1.pb(1),go2.pb(2);
   }
    
    
   if(n%3 == 1) cout << first << '\n';
   else if(n%3 == 2) cout << get(go1) << '\n';
   else cout << get(go2) << '\n'; 
    
}

signed main()
{
    int num = 1;
    
    while(num < (1e17))
    {
        seq.pb(num);
        num<<=2;
    }
    
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}