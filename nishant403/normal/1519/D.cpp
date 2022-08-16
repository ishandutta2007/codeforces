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
    
   int a[n];
    f(i,n) cin >> a[i];
                      
   int b[n];
    f(i,n) cin >> b[i];
    
   int res = 0;
    f(i,n) res += a[i]*b[i];
    
   int c[n];
    f(i,n) c[i] = a[i];
   reverse(c,c+n);
    
   int tmp[n];
    f(i,n) tmp[i] = 0;
    
   int pos[n];
    
   int sum = res; 
    
   f(i,n) a[i]*=b[i];
   f(i,n-1) a[i+1] += a[i];
    
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++) tmp[j] = (c[(j + i)%n]*b[j]);
       for(int j=0;j<n;j++) pos[j] = (n - 1 - j - i + n)%n;
       for(int j=1;j<n;j++) tmp[j] += tmp[j-1];
       
       for(int j=0;j<n;j++)
       {
           int cur_pos = pos[j];
           
           if(cur_pos < j) continue;
           
           int nex_pos = pos[cur_pos];
           
           //we have a match
           if(nex_pos == j)
           {
               int tt = sum;
               
               if(nex_pos < cur_pos) swap(cur_pos,nex_pos);
             
               //we reversed from cur_pos to nex_pos
               tt -= a[nex_pos];
               if(cur_pos > 0) tt += a[cur_pos - 1];
               
               tt += tmp[nex_pos];
               if(cur_pos > 0) tt -= tmp[cur_pos - 1];
               
               res = max(tt,res);
           }
       }
   }
   
   cout << res ;
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}