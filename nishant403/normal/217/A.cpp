#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define F first
#define S second
#define pb push_back
#define f(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define vi vector<int>
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int M = 1e9+7;
const int N = 2*(1e5);

vector<int> graphx[1001],graphy[1001];
map<pii,bool> vis;

void dfs(pii x)
{
    vis[x] = 1;
    
    for(auto z : graphx[x.F])
    {
        if(vis.find({x.F,z}) == vis.end())
            dfs({x.F,z});
    }
    
    for(auto z : graphy[x.S])
    {
        if(vis.find({z,x.S}) == vis.end())
            dfs({z,x.S});    
    }
}

signed main()
{
Fast;    
    
int n;
    cin >> n;
    
    vector<pii> a(n);
    
    f(i,n)
    {
     cin >> a[i].F >> a[i].S;
     graphx[a[i].F].pb(a[i].S);   
     graphy[a[i].S].pb(a[i].F);   
    }
 
    int ans = 0;
    
     for(auto x : a)
         if(vis.find(x) == vis.end()) { ans++; dfs(x); }
     
        cout << ans-1;
}