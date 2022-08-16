#include <bits/stdc++.h>
using namespace std;
 
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
 
const int N = 1e5+10;
vector<pii> g[N];
int marked[N];
int done[2*N];

vector<int> seq;
 
void dfs(int node)
{
    for(;marked[node] < g[node].size();)
    {
        marked[node]++;
        
        if(done[ g[node][marked[node]-1].S ] == 1) continue;
        
        done[g[node][marked[node]-1].S] = 1;
        
        dfs(g[node][marked[node]-1].F);
    }
    
    seq.pb(node); 
}

int vv[100];
    
void solve()
{
   int N,K;
   cin >> N >> K;
    
   if(K == 1)
   {
       while(N--) cout << 'a';
       return;
   }
    
   int n = K;
   int m = (K*K) - K;
    
   int id = 0; 
    
   for(int i=1;i<=K;i++)
   {
       for(int j=1;j<=K;j++)
       {
           if(i == j) continue;
           
           g[i].pb({j,id});
           id++;
       }
   }
    
   dfs(1); 
  
   seq.pop_back();
    
   string res;
    
   vector<int> seq2;
    
   for(auto x : seq)
   {
       if(vv[x] == 0)
       {
           vv[x] = 1;
           seq2.pb(x);
       }
       
       seq2.pb(x);
   }
    
   int tot = seq2.size();
    
   for(int i=0;i<N;i++)
   {
       cout << (char)('a' + seq2[i % tot] - 1);
   }
}
 
signed main()
{
    fast;
    solve();
}