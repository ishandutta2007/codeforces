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

const int inf = 1e9 + 10;

void solve()
{
   int n,k;
   cin >> n >> k;
    
   pair<pii,pii> a[n];
   f(i,n) cin >> a[i].F.F >> a[i].F.S >> a[i].S.F;
   f(i,n) a[i].S.S = i;
   
   sort(a,a+n);
    
   //add edges in horizontal  
   DSU go(n); 
    
   f(i,n-1) if(a[i].F.F == a[i+1].F.F && a[i+1].F.S - a[i].F.S <= k)
   {
       go.merge(a[i].S.S,a[i+1].S.S);
   }
    
   f(i,n) swap(a[i].F.F,a[i].F.S);
    
   sort(a,a+n);
    
   //add edges in vertical  
   f(i,n-1) if(a[i].F.F == a[i+1].F.F && a[i+1].F.S - a[i].F.S <= k)
   {
       go.merge(a[i].S.S,a[i+1].S.S);
   }
    
   vector<int> min_time(n,inf);
    
   f(i,n)
   {
       int rt = go.get_root(a[i].S.S);
       min_time[rt] = min(min_time[rt],a[i].S.F);
   }
     
   vector<int> arr;
    
   f(i,n) if(min_time[i] != inf) arr.pb(min_time[i]);
       
   sort(all(arr));
   reverse(all(arr));
    
   for(int i=0;i<arr.size();i++)
   {
       if(i == (int)arr.size() -1 || i >= arr[i+1])
       {
           cout<< i << '\n';
           return;
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