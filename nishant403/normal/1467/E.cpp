#include <bits/stdc++.h>
using namespace std;
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=1;i<=n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 2e5 + 10;

struct FenwickTree {
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

FenwickTree go(N);
int a[N];
vi g[N];
vi ids[N];
int n;
int p[N];

int tin[N],tout[N],tim = 0;

void dfs(int node,int par = -1)
{
   p[node] = par;
   tin[node] = tout[node] = tim++;
    
   for(auto x : g[node])
       if(x != par)
   {
       dfs(x,node);
       tout[node] = tout[x];
   }
}

int there(int num,int l,int r)
{
    if(l < 0 || r >= n) return 0;
    if(l > r) return 0;   
    
    auto idx = lower_bound(ids[num].begin(),ids[num].end(),l) - ids[num].begin();
    
    if(idx == (int)ids[num].size()) return 0;
    
    int ss = ids[num][idx];
    
    if(ss <= r) return 1;
    return 0;
}

signed main()
{
    fast;
    
    cin >> n;
    f(i,n) cin >> a[i];
    
    vi b;
    f(i,n) b.pb(a[i]);
    sort(b.begin(),b.end());
    f(i,n) a[i] = lower_bound(b.begin(),b.end(),a[i]) - b.begin();
    
    int u,v;
    
    f(i,n-1)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    dfs(1);
   
    f(i,n) ids[a[i]].pb(tin[i]);
    for(int i=0;i<n;i++) sort(ids[i].begin(),ids[i].end());
    
    f(i,n)
    {
        int cnt = ids[a[i]].size();
        if(cnt == 1) continue;
        
        go.add(tin[i],1);
        go.add(tin[i]+1,-1);
        
        int cc = 0;
        int vv = -1;
        
        for(auto x : g[i])
        {
            if(x != p[i])
            {
                if( there(a[i],tin[x],tout[x]) == 1)
                {
                    cc++;
                    vv = x;
                }
            }
            else
            {
                int fl = 0;
                fl+=there(a[i],0,tin[i]-1);
                fl+=there(a[i],tout[i]+1,n-1);
                if(fl > 0) cc++ , vv = x;
            }
        }
        
        if(cc > 1) 
        {
            cout << 0;
            exit(0);
        }
        
        for(auto x : g[i])
        {
            if(x == vv) continue;
            
            if(x != p[i])
            {
                go.add(tin[x],1);
                go.add(tout[x]+1,-1);
            }
            else
            {
                go.add(0,1);
                go.add(tin[i],-1);
                go.add(tout[i]+1,1);
            }
        }
    }
      
    
    int res = 0;
    for(int i=0;i<n;i++) res+=(go.sum(0,i) == 0);
    cout << res;
}