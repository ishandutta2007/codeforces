#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int n, m;
bitset < N > walk[N][70];
bitset < N > bike[N][70];

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  //  freopen("1.out", "w", stdout);
  #endif
  /// To[u][v] means u -> v
  /// From[u][v] means v -> u
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= m; ++i){
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    if(w == 0){
      walk[u][0][v] = 1;
    }
    else{
      bike[u][0][v] = 1;
    }
  }
  for(int up = 1; up <= 60; ++up){
    for(int u = 1; u <= n; ++u){
      for(int v = 1; v <= n; ++v){
        if(walk[u][up - 1][v] == 1){
          walk[u][up] |= bike[v][up - 1];
        }
        if(bike[u][up - 1][v] == 1){
          bike[u][up] |= walk[v][up - 1];
        }
      }
    }
  }
  long long answer = 0;
  for(int u = 1; u <= 1; ++u){
    vector < int > lst;
    lst.push_back(u);
    long long curr = 0;
    int isWalk = 1;
    for(int dwn = 60; dwn >= 0; --dwn){
      set < int > avail;
      for(int v : lst){
        for(int w = 1; w <= n; ++w){
          if(isWalk == 1){
            if(walk[v][dwn][w] == 1){
              avail.insert(w);
            }
          }
          else{
            if(bike[v][dwn][w] == 1){
              avail.insert(w);
            }
          }
        }
      }
      //
      if(avail.size() > 0){
        curr += (1LL << dwn);
        isWalk = 1 - isWalk;
        lst.clear();
        for(int v : avail){
          lst.push_back(v);
        }
      }
    }
    answer = max(answer, curr);
  }
  if(answer > (long long)1e18){
    puts("-1");
    return 0;
  }
  cout << answer;
  return 0;
}