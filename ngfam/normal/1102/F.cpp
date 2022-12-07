#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 16;
const int M = 10011;
 
int n, m;
int a[N][M];
int edge[N][N];
int f[N][1 << N];
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
  cin >> n >> m;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
 
  int low = 0, high = 1000000000, ans = 0;
 
  while(low <= high) {
    int mid = (low + high) >> 1;
    
    for(int i = 0; i < n; ++i) {
      for(int j = i + 1; j < n; ++j) {
        edge[i][j] = edge[j][i] = 1;
        for(int k = 0; k < m; ++k) {
          if(abs(a[i][k] - a[j][k]) < mid) edge[i][j] = edge[j][i] = 0; 
        }
      }
    
    }
    bool able = false;
      
    for(int start = 0; start < n; ++start) {
      memset(f, 0, sizeof f);
 
      f[start][1 << start] = 1;
 
      for(int mask = 0; mask < (1 << n); ++mask) {
        for(int v = 0; v < n; ++v) {
          if(!(mask & (1 << v))) continue;
          if(!f[v][mask]) continue;
          for(int u = 0; u < n; ++u) {
            if(mask & (1 << u)) continue;
            if(!edge[u][v]) continue;
            f[u][mask | (1 << u)] = 1;
          }
        }
      }
 
      for(int v = 0; v < n; ++v) {
        if(able) break;
        if(f[v][(1 << n) - 1]) {
          able = true;
          for(int j = 0; j < m - 1; ++j) {
            if(abs(a[v][j] - a[start][j + 1]) < mid) {
              able = false;
              break;
            }
          }
        }
      } 
      if(able) break; 
    }
    
 
 
    
 
    if(able) {
      ans = mid;
      low = mid + 1;
    }
    else{
      high = mid - 1;
    }
  }
 
  cout << ans;
 
	return 0;
}