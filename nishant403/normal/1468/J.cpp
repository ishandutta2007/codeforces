#include <bits/stdc++.h>
using namespace std;
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 2e5 + 10;
int dsu[N],sz[N];

int find(int x)
{
    if(x == dsu[x]) return x;
    return dsu[x] = find(dsu[x]);
}

bool merge(int a,int b)
{
    int x = find(a);
    int y = find(b);
    
    if(x == y) return 0;
    
    if(sz[x] > sz[y]) swap(x,y);
    sz[y]+=sz[x];
    dsu[x] = y;
    return 1;
}

void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    
    f(i,n) dsu[i+1] = i+1,sz[i+1] = 1;
    
    vector< pair<int,pii> > g1,g2;
    int u,v,w;
    
    f(i,m)
    {
        cin >> u >> v >> w;
        
        if(w <= k) g1.push_back({w,{u,v}});
        else g2.push_back({w-k,{u,v}});
    }
    
    sort(g1.begin(),g1.end());
    reverse(g1.begin(),g1.end());
    sort(g2.begin(),g2.end());
    
    int cst = -1;
    
    if(!g1.empty())
    {
        cst = k - g1[0].F;
        
        for(auto x : g1)
            merge(x.S.F,x.S.S);
    }
    
    int flag = 1;
    f(i,n) if(find(i+1) != find(1))  flag = 0;
        
    if(flag)
    {
        if(!g2.empty()) cst = min(cst,g2[0].F);
        cout << cst << '\n';
        return;
    }
    
    int cst2 = 0;
    
    for(auto x : g2)
        if(merge(x.S.F,x.S.S)) cst2+=x.F;
        
    cout << cst2 << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}