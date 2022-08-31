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

const int N = 2e5 + 10;
vector<pii> g[N];

class DSU {
  int n;
  vector <int> root, sz;
  public :
    DSU(int _n) : n(_n) {
      root.resize(n);
      sz.resize(n);
      for (int i = 0; i < n; i++) {
        root[i] = i;
        sz[i] = 1;
      }
    }
    
    int get_root(int u) {
      return (u == root[u]? u: (root[u] = get_root(root[u])));
    }
    
    bool connected(int u, int v) {
      if (get_root(u) == get_root(v))
        return true;
      return false;
    }
    
    void merge(int u, int v) {
      if (connected(u, v))
        return ;
      u = get_root(u);
      v = get_root(v);
      if (sz[v] > sz[u])
        swap(u, v);
      root[v] = u;
      sz[u] += sz[v];
    }
    
    int total_comp() {
      vector <int> mark(n, 0);
      int tot_component = 0;
      for (int i = 0; i < n; i++) {
        int u = get_root(i);
        if (!mark[u])
          tot_component++;
        mark[u] = 1;
      }
      return tot_component;
    }
    
    int comp_size(int u) {
      u = get_root(u);
      return sz[u];
    }
    
    int max_size_comp() {
      int max_sz = 0;
      for (int i = 0; i < n; i++)
        max_sz = max(max_sz, sz[get_root(i)]);
      return max_sz;
    }
};

void solve()
{
   int n,m;
   cin >> n >> m;

   int u,v,w;

   f(i,m) {
       cin >> u >> v >> w;

       g[u].pb({v,w});
       g[v].pb({u,w});
   }

   int orr = 0;

   int lim = 30;

   while(lim >= 0) {
       //find minimum bits required from 0 to lim - 1 such that graph gets connected
       //then, we know that this bit (x) is necessary and lim = x - 1, ignoring all bits >= lim
       int msk = (1 << lim) - 1;

       vector<pair<int,pii> > edges;

       for(int i=1;i<=n;i++) {
           for(auto x : g[i]) {
               if(x.F < i) {
                   w = x.S;

                   w -= (w & orr);

                   if(w <= msk) {
                       edges.pb({w , {x.F , i }});
                   }
               }
           }
       }


       sort(all(edges));

       int lst = 0;

        DSU go(n + 1);

       for(auto x : edges) {
           if(go.connected(x.S.F , x.S.S) == 0) {
               go.merge(x.S.F , x.S.S);
               lst = x.F;
           }
       }

       if(lst == 0) break;

       int mx_bit = -1;

       for(int i=lim-1;i>=0;i--) {
           if((lst >> i) & 1) {
               orr |= (1 << i);
               lim = i;
               break;
           }
       }

   }
    
   cout << orr << '\n';  

   for(int i=1;i<=n;i++) g[i].clear();
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}