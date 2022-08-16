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
   int n,q;
   cin >> n >> q;
    
   string s;
   cin >> s;
    
    vector<int> plus(n,0),minus(n,0);
    f(i,n) if(s[i] == '+') plus[i]++;
        else minus[i]++;
        
    for(int i=n-3;i>=0;i--)
    {
        plus[i] +=  plus[i+2];
        minus[i] += minus[i+2];
    }
        
   while(q--)
   {
       int l,r;
       cin >> l >> r;
       l--,r--;
       
       if(l == r) cout << 1 << '\n';
       else
       {
           int res = plus[l] - plus[l+1];
           
           res -= minus[l] - minus[l+1];
           
           r++;
           
           if(r < n)
           {
               int res2 = plus[r];
               if(r+1 < n) res2 -= plus[r+1];
                   
               res2 -= minus[r];
               if(r+1 < n) res2 += minus[r+1];
                   
               if((r-l) & 1) res += res2;
                   else res -= res2;
           }
           
           if(res == 0) cout << 0 << '\n';
           else if(res & 1) cout << 1 << '\n';
           else cout << 2 << '\n';
       }
       
   }
    
    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}