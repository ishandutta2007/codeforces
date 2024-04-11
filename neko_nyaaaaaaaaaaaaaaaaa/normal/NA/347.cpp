#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, start = 300300;
vector<int> adj[300301];
vector<int> indeg(300301);
vector<int> outdeg(300301);
vector<int> ans;

void input() {
      cin >> n;
      for (int i = 0; i < n; i++) {
            string s; cin >> s;
            int x = s[0]*1000 + s[1];
            int y = s[1]*1000 + s[2];
            adj[x].push_back(y);
            indeg[y]++; outdeg[x]++;
            start = min(x, start);
      }
}

void dfs(int now) {
      while (adj[now].size()) {
            int u = adj[now].back();
            adj[now].pop_back();
            dfs(u);
      }
      ans.push_back(now);
}

void solve() {
      int c = 0;
      for (int i = 0; i < 300301; i++) {
            c += abs(indeg[i] - outdeg[i]);
            if (outdeg[i] > indeg[i]) start = i;
      }
      if (c > 2) {cout << "NO"; return;}

      dfs(start);

      if (ans.size() != n+1) {cout << "NO"; return;}
      reverse(ans.begin(), ans.end());

      cout << "YES\n";
      for (int i = 0; i < ans.size(); i++) {
            if (i == 0) cout << char(ans[i]/1000);
            cout << char(ans[i] % 1000);
      }
}

int main() {
      ios::sync_with_stdio(0); cin.tie(0);

      input();
      solve();

      return 0;
}