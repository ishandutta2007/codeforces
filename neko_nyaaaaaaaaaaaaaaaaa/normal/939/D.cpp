#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> v(256, 0);
vector<vector<char>> adj(256);
vector<pair<char, char>> ans;

void dfs(char now) {
      v[now] = 1;
      for (int i = 0; i < adj[now].size(); i++) {
            if (v[adj[now][i]]) continue;
            ans.push_back({now, adj[now][i]});
            dfs(adj[now][i]);
      }
}

int main() {
	ios::sync_with_stdio(0);

      int n;
      cin >> n;
      string s1, s2;
      cin >> s1 >> s2;
      for (int i = 0; i < n; i++) {
            adj[s1[i]].push_back(s2[i]);
            adj[s2[i]].push_back(s1[i]);
      }
      for (char i = 'a'; i <= 'z'; i++) {
            if (v[i] == 0) {dfs(i);}
      }
      cout << ans.size() << "\n";
      for (int i = 0; i < ans.size(); i++) {
            cout << ans[i].first << " " << ans[i].second << "\n";
      }
      
	return 0;
}