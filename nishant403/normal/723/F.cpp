#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define ff first
#define ss second
#define f(i,n) for(int i=0;i<n;i++)

const int N = 2e5+10;

vector<int> g[N];
vector<int> dsu(N);
vector<bool> vis(N);
vector<int> tin(N),low(N);
vector<pii> bd;

vector<pii> ans;

int timer = 0;

int s,t,ds,dt;

int getp(int x)
{
    if(dsu[dsu[x]] != dsu[x])
        dsu[x] = getp(dsu[x]);
    
    return dsu[x];
}

void merge(int a,int b)
{
  int a1 = getp(a);
  int b1 = getp(b);
    
  dsu[a1] = b1;  
}

void dfs(int v, int p)
{
    vis[v] = 1;
    low[v] = tin[v] = timer++;
    
    for(auto it : g[v])
    {
        if(it == p) continue;
        
        else if(vis[it])
        {
            low[v] = min(low[v],tin[it]);
        }
            else
        { 
            dfs(it,v);
            low[v] = min(low[v] , low[it]);
        
           if(low[it] > tin[v] ) 
           {
            if(v == s || v==t || it== t || it == s)   
                bd.pb({it,v});
           }
        }    
                                              
    }
     return;
}

int main()
{
    int n,m,u,v;
    cin >> n >> m;
    
    f(i,m)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    cin >> s >> t >> ds >> dt;
    
    f(i,n+1) dsu[i] = i;
    
    dfs(1,-1);
   
    int cs = 0 , ct = 0;
    
    for(auto x : bd) 
    {
     if(x.ff ==s || x.ss == s) cs++;
     if(x.ff == t || x.ss == t) ct++;    
    }
    
    if(ct > dt || cs > ds) { cout << "No"; return 0;}
    
    dt-=ct;
    ds-=cs;
    
    for(auto x : bd) 
    {
        ans.pb(x);
     //   cout << x.ff << " " << x.ss << "\n";
        merge(x.ff,x.ss);   
    }
    
    for(int i=1;i<=n;i++)
    {
       if(i==s || i==t) continue; 
        
       for(auto x : g[i] )   
       {
         if(getp(x) != getp(i))
         {
             if(x==s)
             {
              if(ds <= 0) continue;
              else ds--;    
             }
             
             if(x==t)
             {
              if(dt<=0) continue;
              else dt--;
             }
             
             ans.pb({x,i});
             //cout << x << " " << i << "\n";
             merge(x,i);
         }
           
       }
    }
    
    if(ans.size()==n-1) {
    
    cout << "Yes\n";
        
    for(auto z : ans)
    {
        cout << z.ff <<  " " << z.ss << "\n";
    }
           
    }
    
    else cout << "No\n";
    
}