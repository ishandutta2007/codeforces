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
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int N = 1e5+10;
const int MX = 1e16;
const int MN = 0;

//min and max
pair<pii,pii> seg[4*N];

void build(int node,int ss,int se)
{
    seg[node].F.F = MX;
    seg[node].S.F = MN;
    
    if(ss == se) return;
   
    int mid = (ss+se)/2;
    build(node*2+1,ss,mid);
    build(node*2+2,mid+1,se);   
}

//val.F is height, val.S is index
void update(int node,int ss,int se,int id,pii val)
{
    if(ss > id || se < id) return;
    
    if(ss == id && se == id)
    {
        seg[node].F = min(seg[node].F,val);
        seg[node].S = max(seg[node].S,val);
        return;
    }
    
    int mid = (ss+se)/2;
    
    update(node*2+1,ss,mid,id,val);
    update(node*2+2,mid+1,se,id,val);
    
    seg[node].F = min(seg[node*2+1].F,seg[node*2+2].F);
    seg[node].S = max(seg[node*2+1].S,seg[node*2+2].S);
}

int n,d;

pii query(int node,int ss,int se,int val)
{
    if( val-seg[node].F.F < d && seg[node].S.F-val < d) return {0,-1};
    
    if(ss == se) 
    {
        if( val-seg[node].F.F >= d ) return {ss,seg[node].F.S};
        if( seg[node].S.F-val >= d ) return {ss,seg[node].S.S};
        assert(1==0);
    }
    
    int mid = (ss+se)/2;
    
    if(val-seg[node*2+2].F.F < d && seg[node*2+2].S.F-val < d)
       return query(node*2+1,ss,mid,val);
    else 
       return query(node*2+2,mid+1,se,val);
}

int h[N];
int dp[N];
int par[N];

void solve()
{
   cin >> n >> d;
    
   f(i,n) cin >> h[i];    
   
   build(0,0,n-1);
    
   dp[0] = 1;
   par[0] = -1;
   update(0,0,n-1,dp[0],{h[0],0});
    
   for(int i=1;i<n;i++)
   {
       pii go = query(0,0,n-1,h[i]);
       dp[i] = go.F + 1;
       par[i] = go.S;
       update(0,0,n-1,dp[i],{h[i],i});
   }
    
    pii mx = {-1,-1};
    f(i,n) mx = max(mx,{dp[i],i});
    
    vi res;
    
    res.pb(mx.S);
    
    while(par[res.back()] != -1)
    {
        res.pb(par[res.back()]);
    }
    
    cout << res.size() << '\n';
    
    reverse(res.begin(),res.end());
    
    for(auto x : res) cout << x+1 <<" ";
}

signed main()
{
    fast;
    solve();
}