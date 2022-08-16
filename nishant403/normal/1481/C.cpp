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

const int N = 1e5 + 10;
queue<int> need[N]; 

void solve()
{
    int n,m;
    cin >> n >> m;
    
    f(i,n+5) 
        while(!need[i].empty()) need[i].pop();
    
    int a[n],b[n];
    f(i,n) cin >> a[i];
    f(i,n) cin >> b[i];
    
    int c[m];
    f(i,m) cin >> c[i];
    
    vi res;
    
    reverse(c,c+m);
    
    f(i,n)
        if(a[i] != b[i]) need[b[i]].push(i);
   
    f(i,n)
        if(a[i] == b[i]) need[b[i]].push(i);
        
    int ext = -1;    
        
    f(i,m)
    {
        int col = c[i];
        
        if(!need[col].empty())
        {
            auto x = need[col].front(); 
            need[col].pop();
            
            res.pb(x);
            
            need[col].push(x);
            
            ext = x;
        }
        else if(ext != -1)
        {
           res.pb(ext); 
        }
        else
        {
            cout <<"NO\n";
            return;
        }
        
    }
    
    int flag = 1;
    
    reverse(all(res));
    reverse(c,c+m);
    
    f(i,m)
        a[res[i]] = c[i];
    
    f(i,n)
        if(a[i] != b[i]) flag = 0;
    
    if(flag == 1)
    {
    
    cout <<"YES\n";
    
    f(i,m) cout << res[i] + 1 << ' ';
    cout << '\n';
    }
    else cout <<"NO\n";
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}