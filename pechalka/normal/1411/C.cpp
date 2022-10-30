#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <bitset>
#include <random>
#include <string>
#include <vector>
#include <complex>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

vector<int> used;
vector<int> go;
int ans;

void dfs(int v){
  used[v] = 1;
  if (go[v] != -1){
    if (used[go[v]] == 1)
      ++ans;
    else if (used[go[v]] == 0)
      dfs(go[v]);
  }
  used[v] = 2;
}

int main() {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int t;
  cin >> t;
  while (t--){
    int n, m;
    cin >> n >> m;
    ans = m;
    go = vector<int>(n, -1);
    for (int i = 0; i < m; ++i){
      int a, b;
      cin >> a >> b;
      if (a == b)
        --ans;
      else
        go[a - 1] = b - 1;
    }
    used = vector<int>(n, 0);
    for (int i = 0; i < n; ++i){
      if (!used[i])
        dfs(i);
    }
    cout << ans << '\n';
  }
  return 0;
}