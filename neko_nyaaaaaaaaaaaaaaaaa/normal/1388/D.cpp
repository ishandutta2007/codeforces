#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, b[MAXN];
vector<int> adj[MAXN];
long long a[MAXN];

vector<int> pf, pb;

void dfs(int now) {
	for (int u: adj[now]) {
		dfs(u); 
		if (a[u] > 0) a[now] += a[u];
	}
	if (a[now] > 0) pf.push_back(now);
	else pb.push_back(now);
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	vector<int> rt;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		if (b[i] != -1) {
			adj[b[i]].push_back(i);
		} else {
			rt.push_back(i);
		}
	}

	for (int i: rt) dfs(i);
	reverse(pb.begin(), pb.end());

	cout << accumulate(a+1, a+1+n, 0LL) << '\n';
	for (int i: pf) cout << i << ' ';
	for (int i: pb) cout << i << ' ';

	return 0;
}