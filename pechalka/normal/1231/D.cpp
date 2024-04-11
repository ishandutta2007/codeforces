#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <set>

using namespace std;

int ans = 0;

void gen(vector<int> &A, vector<vector<int>> &G, int i){
  if (i < G.size()){
    for (int j = 0; j < 6; ++j){
      A[i] = j;
      gen(A, G, i + 1);
    }
  } else {
    bool was[6][6];
    for (int a = 0; a < 6; ++a){
      for (int b = 0; b < 6; ++b)
        was[a][b] = false;
    }
    for (int a = 0; a < G.size(); ++a){
      for (int b : G[a]){
        was[A[a]][A[b]] = true;
        was[A[b]][A[a]] = true;
      }
    }
    int res = 0;
    for (int a = 0; a < 6; ++a){
      for (int b = 0; b <= a; ++b)
        res += was[a][b];
    }
    ans = max(ans, res);
  }
}

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> G(n);
  for (int i = 0; i < m; ++i){
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  vector<int> A(n);
  gen(A, G, 0);
  cout << ans;
  return 0;
}