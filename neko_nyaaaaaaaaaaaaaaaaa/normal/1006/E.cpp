#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

int n, q;
vector<vector<int>> adj(200001);
vector<int> tour(1);
vector<int> subtree(200001, 1);
vector<int> ind(200001);

void dfs(int now) {
      ind[now] = tour.size();
	tour.push_back(now);
	for (auto u: adj[now]) {
		dfs(u);
		subtree[now] += subtree[u];
	}
}

int main() {
      ios::sync_with_stdio(0); cin.tie(0);
      
      cin >> n >> q;
      for (int i = 2; i <= n; i++) {
      	int x; cin >> x;
      	adj[x].push_back(i);
      }
      dfs(1);
      
      while (q--) {
      	int x, y;
      	cin >> x >> y;
      	if (subtree[x] < y) {cout << "-1\n";}
      	else {cout << tour[ind[x] + y - 1] << '\n';}
      }
      
      return 0;
}