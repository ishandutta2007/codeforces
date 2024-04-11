#include <bits/stdc++.h>
using namespace std;

const int N = 300000;
const int SN = sqrt(N);

int n, q;
vector<int> rides[N];

int solve() {
  scanf("%d", &n);
  scanf("%d", &q);
  for (int i=0; i<q; i++) {
    int k;
    scanf("%d", &k);
    
    rides[i].clear();
    while (k--) {
      int c;
      scanf("%d", &c);
      --c;
      
      rides[i].push_back(c);
    }
  }
  
  vector<pair<int, int>> v[n];

  for (int i=0; i<q; i++) {
    if (rides[i].size() < SN) {
      for (int j=0; j<rides[i].size(); j++) for (int k=j+1; k<rides[i].size(); k++) {
        v[rides[i][j]].push_back({rides[i][k], rides[i][j+1]});
      }
    } else {
      vector<int> pos(n, -1);
      for (int j=0; j<rides[i].size(); j++) pos[rides[i][j]] = j;
      
      for (int j=0; j<q; j++) {
        if (i == j) continue;
        
        int lst = -1;
        for (int k=0; k<rides[j].size(); ++k) {
          int p = pos[rides[j][k]];
          if (p == -1) continue;
          
          if (lst != -1 && p > lst+1 && pos[rides[j][k-1]] != lst) return 0 * printf("Human\n");
          lst = p;
        }
      }
    }
  }
  
  for (int i=0; i<n; i++) {
    sort(v[i].begin(), v[i].end());
    for (int j=1; j<v[i].size(); j++) {
      if (v[i][j].first == v[i][j-1].first && v[i][j].second != v[i][j-1].second) {
        // cerr << i << " " << v[i][j].first << " " << v[i][j-1].second << " " << v[i][j].second << endl;
        return 0 * printf("Human\n");
      }
    }
  }
  
  printf("Robot\n");
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}