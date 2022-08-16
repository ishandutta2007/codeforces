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
    
    int a[n];
    f(i,n) cin >> a[i];
    
    int flag = 1;
    
    f(i,n) if(a[i] != a[0]) flag =0;
        
        if(flag == 1)
    {
        cout << 1;
        cout << "\n";
        f(i,n) cout << 1 <<" ";
        cout << '\n';
        
        return;
    }
    
    int last = a[0];
    int cnt = 1;
    
    if(n%2 == 0 || a[0] == a[n-1])
    {
        cout << 2 << '\n';
        f(i,n) cout << ((i%2)+1) <<" ";
        cout << '\n';
        return;
    }
    
    flag = 0;
    
    f(i,n-1) if(a[i] == a[i+1]) flag = 1;
        
    if(flag == 1)
    {
       int col = 1;
        
        cout << 2 << '\n';
        
       f(i,n)
       {
          if(i>0 && a[i] == a[i-1] && flag == 1)
          {
              flag = 0;
              if(col == 1) col = 2;
              else col = 1;
          }
           
           cout << col << " ";
           
            if(col == 1) col = 2;
            else col = 1;
       }
        
        cout << '\n';
        return;
    }
    
    f(i,n)
    {
        if(a[i] != last)
        {
            cnt++;
        }
        
        last = a[i];
    }
    
    if(a[n-1] == a[0]) cnt--;
    
    if(cnt % 2 == 0)
    {
        cout << 2 << '\n';
        
        int cur = a[0];
        int col = 1;
        
        f(i,n) 
        {
            if(a[i] != cur)
            {
                if(col == 1) col=2;
                else col = 1;
            }
            
            cout << col << ' ';
            cur = a[i];
        }
        
        cout << '\n';
     
        return;
    }
    else 
    {
        cout << 3 << '\n';
        
        cout << 3 << " ";
        f(i,n-1) cout << ((i%2) +1) <<" ";
        
        cout << '\n';
        return;
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