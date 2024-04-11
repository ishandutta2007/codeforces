#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> a(1000018);
vector<ll> v(1000007, 0);
vector<vector<ll>> adj(1000007);
vector<ll> ans(1000007);
set<ll> ss;
priority_queue<ll> q;

void answer() {
      for (auto it = ss.begin(); it != ss.end(); it++) {
            ans[*it] = q.top();
            q.pop();
      }
      ss.clear();
}

void dfs(ll now) {
      v[now] = 1;
      q.push(a[now]);
      ss.insert(now);
      for (ll i = 0; i < adj[now].size(); i++) {
            if (v[adj[now][i]]) continue;
            dfs(adj[now][i]);
      }
}

int main() {
	ios::sync_with_stdio(0);

      ll n, m;
      cin >> n >> m;
      for (ll i = 1; i <= n; i++) {
            cin >> a[i];
      }
      while (m--) {
            ll x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
      }
      for (ll i = 1; i <= n; i++) {
            if (v[i]) continue;
            dfs(i);
            answer();
      }
      for (ll i = 1; i <= n; i++) {
            cout << ans[i] << " ";
      }
      
	return 0;
}