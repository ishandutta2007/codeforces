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

struct FenwickTree 
{
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

const int N =3e5 + 10;
vi g[N];
vi g2[N];
int timer = 0;
int tin[N];
int tout[N];

int tin2[N];
int tout2[N];
int timer2 = 0;

FenwickTree path(N+N),subtree(N);

int res = 0;

void dfs2(int node,int par = -1)
{
    tin2[node] = timer2++;
    
    tin[node] = timer++;
    
    for(auto x : g2[node])
        if(x != par) dfs2(x,node);
    
    tout[node] = timer - 1;
    
    tout2[node] = timer2++;
}

void dfs(int node,int par = -1)
{
    int sub_count = subtree.sum(tin[node],tout[node]);
   
    int f1 = -1;
    int f2 = -1;
    
    if(sub_count == 0)
    { 
        int path_count = path.sum(tout2[node],tout2[1]);
       
        subtree.add(tin[node],1);
        path.add(tin2[node],-node);
        path.add(tout2[node],node);
        
        f1 = 1;
        
        if(path_count != 0)
        {
            subtree.add(tin[path_count],-1); 
            path.add(tin2[path_count],path_count);
            path.add(tout2[path_count],-path_count); 
            f2 = path_count;
        }
    }
    
    
    res = max(res,subtree.sum(tin[1],tout[1]));
    
    for(auto x : g[node])
        if(x != par) dfs(x,node);
    
    if(f1 != -1) 
    {
        subtree.add(tin[node],-1);
        path.add(tin2[node],node);
        path.add(tout2[node],-node);
    }
    
    if(f2 != -1)
    {
        subtree.add(tin[f2],1); 
        path.add(tin2[f2],-f2);
        path.add(tout2[f2],f2); 
    }
}

void solve()
{
   int n;
   cin >> n;
    
   int x;
  
   for(int i=2;i<=n;i++)
   {
       cin >> x;
       g[i].pb(x);
       g[x].pb(i);
   }
    
   for(int i=2;i<=n;i++)
   {
       cin >> x;
       g2[i].pb(x);
       g2[x].pb(i);
   }
    
   res = 0; 
    
   dfs2(1); 
   dfs(1);
    
   cout << res << '\n';
    
   for(int i=1;i<=n;i++) g[i].clear(),g2[i].clear(); 
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}