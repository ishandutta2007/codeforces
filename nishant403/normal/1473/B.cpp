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
   string s,t;
    cin >> s >> t;
    
   string gc; 
    
   int n = s.length();
   int m = t.length();
    
   for(int i=1;i<=n;i++)
   {
       if(n % i != 0) continue;
       if(m % i != 0) continue;
       
       int flag = 1;
       
       string take = s.substr(0,i);
       
       for(int j=0;j<n;j+=i)
           if(s.substr(j,i) != take) flag = 0;
           
       for(int j=0;j<m;j+=i)
           if(t.substr(j,i) != take) flag = 0;
        
       if(flag) gc = take;    
   }
    
   if(gc.empty())
   {
       cout << -1 << '\n';
       return;
   }
    
   int len = gc.length();
    
   int a1 = m/len;
   int a2 = n/len;
   
   int l2 = (a1*a2)/__gcd(a1,a2); 
    
   f(i,l2) cout << gc;
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