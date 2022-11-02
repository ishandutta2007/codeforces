#include <deque>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int MAXN = 100000;

vector<int> G[MAXN];

long double dfs(int v, int p){
  long double sum = 0;
  int cnt = 0;
  for (int u: G[v]){
    if (u == p)
      continue;
    sum += dfs(u, v);
    ++cnt;
  }
  if (cnt == 0)
    return 0;
  return 1 + sum / cnt;
}

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
  for (int i = 0; i + 1 < n; ++i){
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  cout << setprecision(30) << dfs(0, 0) << '\n';
  return 0;
}