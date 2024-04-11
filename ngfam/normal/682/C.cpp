#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int w[N];
vector < pair < int, int > > g[N];

int dfs(int v, int p, long long mxDist) {
  if(w[v] < mxDist) return 0;
  int ans = 1;

  for(auto t : g[v]) if(t.first != p) {
    long long new_dist = max(mxDist + t.second, 0LL);
    ans += dfs(t.first, v, new_dist);
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> w[i];

  for(int i = 2; i <= n; ++i) {
    int p, c;
    cin >> p >> c;
    g[p].emplace_back(i, c);
    g[i].emplace_back(p, c);
  }

  cout << n - dfs(1, 0, 0) << endl;

  return 0;
}