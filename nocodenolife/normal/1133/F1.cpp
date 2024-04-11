// A Quick implementation of BFS using 
// vectors and queue 
#include <bits/stdc++.h> 
#define pb push_back 
  
using namespace std; 
  
vector<bool> v; 
vector<vector<int> > g; 
  
void edge(int a, int b) 
{ 
    g[a].pb(b); 
  
    // for undirected graph add this line 
    g[b].pb(a); 
} 
  
void bfs(int u) 
{ 
    queue<int> q; 
  
    q.push(u); 
    v[u] = true; 
  
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
    int n, e; 
    cin >> n >> e; 
  
    v.assign(n+1, false); 
    g.assign(n+1, vector<int>()); 
  
    int a, b; 
    int max = 0;
    int ed = -1;
    int val[n+1] = {0};
    for (int i = 0; i < e; i++) { 
        cin >> a >> b; 
        edge(a, b); 
        
        val[a]++;
        val[b]++;
        
        if(val[a]>max)
        {
            max = val[a];
            ed = a;
        }
        if(val[b]>max)
        {
            max = val[b];
            ed = b;
        }
    } 
    
    bfs(ed);
  
    return 0; 
}