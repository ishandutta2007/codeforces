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
   int n,m;
   cin >> n >> m;
    
   int a[n][m];
    f(i,n) f(j,m) cin >> a[i][j];
    
   vector<pair<int,pii> > go;
    
   f(i,n) f(j,m) go.pb({a[i][j],{i,j}});
   sort(all(go));
    
   vector<vi> res(n,vi(m,-1));
    
   f(i,m)
   {
       auto z = go[i];
       a[z.S.F][z.S.S] = -1;
       res[z.S.F][i] = z.F; 
   }
    
   f(i,n)
   {
       int ptr = 0;
       
       f(j,m)
       {
           if(a[i][j] == -1) continue;
           while(ptr < m && res[i][ptr] != -1) ptr++;
           res[i][ptr] = a[i][j];
       }
   }
   
   f(i,n)
   {
       f(j,m) cout << res[i][j] << ' ';
       cout << '\n';
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