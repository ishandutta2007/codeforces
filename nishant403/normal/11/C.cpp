#include <bits/stdc++.h>
using namespace std;
  
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

const int N = 1e3 + 10;

vi g[N*N];
int vis[N*N];

int n,m;
string s[N];

inline int encode(int x,int y)
{
    return (x*m) + y;
}

int xx[] = {0,1,0,-1,1,-1,-1,1};
int yy[] = {1,0,-1,0,1,1,-1,-1};

bool valid(int x,int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m && s[x][y] == '1');
}

vector<pii> go;

void dfs(int node)
{
    vis[node] = 1;
    
    go.pb({node/m,node%m});
    
    for(auto x : g[node])
        if(!vis[x]) dfs(x);
}

int temp[N][N];

int process()
{
    int sz = go.size();
    
    if(sz % 4 != 0) return 0;
    
    assert(sz > 0);
    
    pii fir = go[0];
    
    //type 1
    if(temp[fir.F + 1][fir.S] != 0)
    {
        int len = (sz / 4) + 1;
        
        f(i,len)
            if(temp[fir.F][fir.S + i] == 0) return 0;
            
        f(i,len)
            if(temp[fir.F + len - 1][fir.S + i] == 0) return 0;
        
        f(i,len)
            if(temp[fir.F + i][fir.S] == 0) return 0;
            
        f(i,len)
            if(temp[fir.F + i][fir.S + len - 1] == 0) return 0;
        
        return 1;
    }
    else //type 2 
    {
        int len = (sz / 4) + 1;
        
        if(fir.S - len + 1 < 0) return 0;
        
        f(i,len) 
            if(temp[fir.F + i][fir.S - i] == 0) return 0;
            
        f(i,len) 
            if(temp[fir.F + i][fir.S + i] == 0) return 0;
            
        f(i,len) 
            if(temp[fir.F + len - 1 + i][fir.S - len + 1 + i] == 0) return 0;
            
        f(i,len) 
            if(temp[fir.F + len - 1 + i][fir.S + len - 1 - i] == 0) return 0;
            
       return 1;
    }
}

void solve()
{
   cin >> n >> m;
   f(i,n) cin >> s[i];
    
   f(i,n) f(j,m)
   {
      if(s[i][j] != '1') continue;
       
      f(k,8)
          if(valid(i + xx[k],j + yy[k]))
              g[encode(i,j)].pb(encode(i+xx[k],j+yy[k]));
   }
    
   int res = 0;
    
   f(i,n) f(j,m)
   {
       if(s[i][j] == '0') continue;
       
       if(vis[encode(i,j)] == 1) continue;
       
       dfs(encode(i,j));
      
       for(auto x : go)
          temp[x.F][x.S] = 1;
       
       res += process();

       for(auto x : go)
          temp[x.F][x.S] = 0;
       
       go.clear();
   }
   
   cout << res << '\n'; 
    
   f(i,n*m) 
   {
       vis[i] = 0; 
       g[i].clear();
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