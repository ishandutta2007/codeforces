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
    int a,b;
    cin >> a >> b;
    
    int n = a + b;
    
    string s;
    cin >> s;
   
    int one = 0,zero = 0;
    f(i,n) if(s[n-i-1] == '?') s[n-i-1] = s[i];
   
    f(i,n) if(s[i] == '0') zero++;
           else if(s[i] == '1') one++;
        
    if(zero > a || one > b)
    {
        cout << -1 << '\n';
        return;
    }
        
    if((b - one) % 2 == 0)
    {
        int id = (b - one)/2;
        
        f(i,n) 
         if(s[i] == '?' && i != n-i-1 && id > 0) 
        {
            s[i] = s[n-i-1] = '1';
            id--;
        }
        
        f(i,n) if(s[i] == '?') s[i] = '0';
    }
    else
    {
        int id = (a - zero)/2;
        
        
        f(i,n) 
         if(s[i] == '?' && i != n-i-1 && id > 0) 
        {
            s[i] = s[n-i-1] = '0';
            id--;
        }
        
        f(i,n) if(s[i] == '?') s[i] = '1';
    }
    
    f(i,n) if(s[i] != s[n-i-1])
    {
        cout << -1 << '\n';
        return;
    }
    
    //now check
    f(i,n) assert(s[i] == '0' || s[i] == '1');
    
    f(i,n) if(s[i] == '1') b--;
            else a--;
        
        if(a == 0 && b == 0)
    {
        cout << s << '\n';
    }
    else cout << -1 << '\n';
                  
      
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}