#include <bits/stdc++.h>

using namespace std;

const int N = 220;

int mark[N];
vector < int > g[N];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n;
  vector < long long > a;

  for(int i = 0; i < n; ++i) {
    long long x; cin >> x;
    if(x != 0) a.push_back(x);
  }

  vector < int > count_bit(60, 0);

  for(int x : a) {
    for(int i = 0; i < 60; ++i) {
      count_bit[i] += (x >> i) & 1;
      if(count_bit[i] >= 3) {
        cout << 3;
        return 0;
      }
    }
  }

  for(int i = 0; i < a.size(); ++i) {
    for(int j = 0; j < a.size(); ++j) {
      if((a[i] & a[j]) > 0) g[i].push_back(j);
    }
  }


  int ans = 1e9;

  for(int i = 0; i < a.size(); ++i) {
    for(int j : g[i]){
      if(i == j) continue;
      memset(mark, 60, sizeof mark);
      mark[i] = mark[j] = 0;
      queue < int > bfs;
      bfs.push(j);
      while(!bfs.empty()) {
        int x = bfs.front(); bfs.pop();
        for(int y : g[x]) {
          if(y == i) {
            if(x != j) {
              ans = min(ans, mark[x] + 2);
            }
            continue;
          }
          if(mark[y] > mark[x] + 1) {
            mark[y] = mark[x] + 1;
            bfs.push(y);
          }
        }
      }
    }
  }

  if(ans > n) cout << -1;
  else cout << ans << endl;

  return 0;
}