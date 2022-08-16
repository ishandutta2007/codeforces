#include <bits/stdc++.h>
using namespace std;
 
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define vi vector<int>
#define all(x) x.begin(),x.end()
 
const int N = 4e3 + 10;

vi g[N];
int marked[N];
int done[2*N];
 
vi res;
 
void dfs(int node)
{
    for(;marked[node] < g[node].size();)
    {
        marked[node]++;
        dfs(g[node][marked[node]-1]);
    }
    
    res.pb(node);
}
 
int vis[N];
int in[N];
int out[N];
 
void dfs2(int node)
{
    vis[node] = 1;
    
    for(auto x : g[node])
        if(!vis[x]) dfs2(x);
}

int to_num(char c)
{
    if(c >= '0' && c <= '9') return c - '0';
    else if(c >= 'a' && c <= 'z') return 10 + (c - 'a');
    else return 36 + (c - 'A');
}

char to_char(int x)
{
    if(x <= 9) return x + '0';
    else if(x <= 35) return (x-10) + 'a';
    else return (x-36) + 'A';
}

int encode(string s)
{
    return to_num(s[0])*62 + to_num(s[1]);
}
    
void solve()
{
   int n = (62*62); 
   
   int m;
   cin >> m;
    
   f(i,m)
   {
       string s;
       cin >> s;
       
       int u = encode(s.substr(0,2));
       int v = encode(s.substr(1,2));
       
       g[u].pb(v);
       
       in[v]++;
       out[u]++;
   }
    
   int st = -1;
   int en = -1;
   int flag = 1;
    
   for(int i=0;i<n;i++)
   {
       if(in[i] != out[i])
       {
           if(in[i] - out[i] == 1)
           {
               if(en == -1) en = i;
               else flag = 0;
           }
           else if(out[i] - in[i] == 1)
           {
               if(st == -1) st = i;
               else flag = 0;
           }
           else flag = 0;
       }
   }
    
   if(st == -1 && en == -1)
   {
       f(i,n) if(g[i].size() > 0)
           st = en = i;
   }
    
   dfs2(st);
    
   for(int i=0;i<n;i++)
       if(vis[i] == 0 && g[i].size() > 0) 
   {
       flag = 0;
   }
    
   if(en == -1 || st == -1) flag = 0;
       
   if(flag == 0)
   {
      cout <<"NO\n";
      return;
   }
    
   cout <<"YES\n";
    
   dfs(st); 
    
   reverse(all(res)); 
    
   cout << (char)to_char(res[0] / 62); 
   for(auto x : res) cout << (char)to_char(x % 62);
}
 
signed main()
{
    fast;
    solve();
}