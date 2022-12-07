#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 500500;
 
int n; 
int a[N];
int jump[N][22];
vector < int > g[N];
 
int main(){
  
  int root = 1;
  
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    if(a[i] < a[root]) root = i;
  } 
  
  for(int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  
  queue < int > bfs; 
  bfs.push(root); 
  
  long long answer = 0;
  
  while(!bfs.empty()) {
    int v = bfs.front(); bfs.pop();
    
    if(v != root) {
      for(int u : g[v]) if(a[u] < a[v]) jump[v][0] = u;
      for(int i = 1; i < 22; ++i) {
        jump[v][i] = jump[jump[v][i - 1]][i - 1];
      }
      
      long long w = 1e18;
      
      for(int i = 0; i < 22; ++i) {
        if(jump[v][i] == 0) {
          w = min(w, 1LL * i * a[root] + a[root] + a[v]);
        }
        else w = min(w, 1LL * i * a[jump[v][i]] + a[jump[v][i]] + a[v]);
      }
      
      answer += w;      
    }
    
    for(int u : g[v]) if(a[u] > a[v]) {
      bfs.push(u);
    }
  }
  
  cout << answer << endl;
 
	return 0;
}