#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<ll>> adj(200001);
vector<ll> col(200001);
vector<ll> v(200001, 0);
vector<ll> cnt;
ll ans = 0;

void dfs(int now) {
      v[now] = 1;
      cnt.push_back(col[now]);
      for (int i = 0; i < adj[now].size(); i++) {
            if (v[adj[now][i]]) {continue;}
            dfs(adj[now][i]);
      }
}

int main() {
	ios::sync_with_stdio(0);
	
	ll n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
	      cin >> col[i];
	}
	while (m--) {
	      ll x, y;
	      cin >> x >> y;
	      adj[x].push_back(y);
	      adj[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
	      if (v[i]) {continue;}
	      cnt.resize(0);
	      dfs(i);
	      if (cnt.size() == 1) {continue;}
	      sort(cnt.begin(), cnt.end());
	      ll count = 1;
	      ll countmax = 0;
	      for (int j = 1; j < cnt.size(); j++) {
	            if (cnt[j] == cnt[j-1]) {count++;}
	            else {count = 1;}
	            countmax = max(countmax, count);
	      }
	      ans += cnt.size() - countmax;
	}
	cout << ans;
	
	return 0;
}