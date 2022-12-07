// A Quick implementation of BFS using 
// vectors and queue 
#include <bits/stdc++.h> 
#define pb push_back 
  
using namespace std; 
  
vector<bool> v; 
vector<vector<int> > g; 
vector<int> ans;
void edge(int a, int b) 
{ 
    g[a].pb(b); 
  
    // for undirected graph add this line 
    g[b].pb(a); 
} 



void DFSUtil(int u, vector<bool> &visited) 
{ 
    visited[u] = true; 
    //cout << u << " "; 
    for (int i=0; i<g[u].size(); i++) 
    {
        if (visited[g[u][i]] == false) 
        {
            if(u==1)
                ans.push_back(g[u][i]);
            DFSUtil(g[u][i], visited);
        } 
    }
} 
  
// This function does DFSUtil() for all  
// unvisited vertices. 
void DFS(int V) 
{ 
    vector<bool> visited(V+1, false); 
    for (int u=1; u<=V; u++) 
        if (visited[u] == false) 
            DFSUtil(u, visited); 
} 
  
void bfs(int d) 
{ 
    queue<int> q; 
  
    v[1] = true; 
    
    for(int i=0;i<ans.size();i++)
    {
        v[ans[i]] = true;
        q.push(ans[i]);
        cout<<1<<" "<<ans[i]<<endl;
        d--;
    }
    for (auto i = g[1].begin(); i != g[1].end(); i++) { 
        if (v[*i]==false && d>0) { 
            q.push(*i); 
            v[*i] = true; 
            cout<<1<<" "<<*i<<endl;
            d--;
        } 
    } 
  
    while (!q.empty()) { 
  
        int f = q.front(); 
        q.pop(); 
    
        //cout << f << " "; 
  
        // Enqueue all adjacent of f and mark them visited  
        for (auto i = g[f].begin(); i != g[f].end(); i++) { 
            if (!v[*i]) { 
                q.push(*i); 
                v[*i] = true; 
                cout<<f<<" "<<*i<<endl;
            } 
        } 
    } 
} 
  
// Driver code 
int main() 
{ 
    int n, e,d; 
    cin >> n >> e>>d; 
  
    v.assign(n+1, false); 
    g.assign(n+1, vector<int>()); 
  
    int a, b; 
    
    int val[n+1] = {0};
    for (int i = 0; i < e; i++) { 
        cin >> a >> b; 
        edge(a, b); 
        
        val[a]++;
        val[b]++;
        
    } 
    DFS(n);
    
    if(d>val[1])
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if(d<ans.size())
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    bfs(d);
  
    return 0; 
}