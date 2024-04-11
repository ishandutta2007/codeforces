#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, q;
vector<vector<string>> adj(256);
set<string> ans;

void dfs(string s) {
      if (s.size() == n) ans.insert(s);
      else {
            char c = s.back();
            s.pop_back();
            for (string u: adj[c]) {
                  dfs(s + u);
            }
      }
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

      cin >> n >> q;
      for (int i = 1; i <= q; i++) {
            string s; char c;
            cin >> s >> c;
            reverse(s.begin(), s.end());
            adj[c].push_back(s);
      }
      dfs("a");

      cout << ans.size();
	return 0;
}