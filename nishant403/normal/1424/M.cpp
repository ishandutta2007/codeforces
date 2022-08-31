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

vector<int> g[26];

void add(string s,string t)
{
    int n = s.length();
    int m = t.length();
    
    f(i,min(n,m))
    {
        if(s[i] != t[i])
        {
            g[s[i] - 'a'].pb(t[i] - 'a');
            return;
        }
    }
    
    if(n > m)
    {
        cout << "IMPOSSIBLE\n";
        exit(0);
    }
}

int vis[26];
int flag = 0;

vector<int> topo;

void dfs(int node)
{
    vis[node] = 1;
    
    for(auto x : g[node])
    {
        if(vis[x] == 0) dfs(x);
        else if(vis[x] == 1) flag = 1;
    }
    
    vis[node] = 2;
    
    topo.pb(node);
}

void solve()
{
   int n,k;
   cin >> n >> k;
    
   string s[n*k];
    
   f(i,26) vis[i] = 2; 
    
   f(i,n)
   {
       int x;
       cin >> x;
       
       f(j,k) cin >> s[(x*k) + j];
   }
    
   f(i,n*k) for(auto x : s[i])
       vis[x - 'a'] = 0;
    
   for(int i=1;i<n*k;i++) add(s[i-1],s[i]); 
 
   for(int i=0;i<26;i++)
       if(vis[i] == 0) dfs(i);
       
   if(flag == 1) cout <<"IMPOSSIBLE\n";
   else
   {
       reverse(all(topo));
       for(auto x : topo) cout << (char)('a' + x);
   }
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}