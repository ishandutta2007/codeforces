#include <deque>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main(){
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; ++i){
    cin >> A[i];
  }
  vector<int> ans(n, INF);
  deque<int> Q;
  for (int i = 0; i < n; ++i){
    if (i >= A[i]){
      if (A[i] % 2 != A[i - A[i]] % 2){
        ans[i] = 1;
        Q.emplace_back(i);
      }
    }
    if (i + A[i] < n){
      if (A[i] % 2 != A[i + A[i]] % 2){
        ans[i] = 1;
        Q.emplace_back(i);
      }
    }
  }
  vector<vector<int>> G(n);
  for (int i = 0; i < n; ++i){
    if (i >= A[i] && A[i] % 2 == A[i - A[i]] % 2)
      G[i - A[i]].emplace_back(i);
    if (i + A[i] < n && A[i] % 2 == A[i + A[i]] % 2)
      G[i + A[i]].emplace_back(i);
  }
  while (!Q.empty()){
    int now = Q.front();
    Q.pop_front();
    for (int i: G[now]){
      if (ans[i] > ans[now] + 1){
        ans[i] = ans[now] + 1;
        Q.emplace_back(i);
      }
    }
  }
  for (int i = 0; i < n; ++i){
    if (ans[i] == INF)
      cout << -1 << ' ';
    else
      cout << ans[i] << ' ';
  }
  cout << '\n';
  return 0;
}