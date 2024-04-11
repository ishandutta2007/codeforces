#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 7;
int n, m, q, x[N], y[N];
ll ns[N], mn[N << 2], tag[N << 2];
vector< pair<int, int> > ve[N];
void add(int id, int L, int R, int l, int r, ll w) {
	if(l <= L && R <= r) return mn[id] += w, tag[id] += w, void();
	int mid = (L + R) >> 1;
	if(l <= mid) add(id << 1, L, mid, l, r, w);
	if(r > mid) add(id << 1 | 1, mid + 1, R, l, r, w);
	mn[id] = tag[id] + min(mn[id << 1], mn[id << 1 | 1]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> q;
	for(int i = 1; i < n; i++) cin >> x[i] >> y[i + 1];
	for(int i = 1, u, v, w; i <= m; i++) cin >> u >> v >> w, ve[u].push_back(make_pair(v, w));
	for(int i = 2; i <= n; i++) add(1, 1, n, i, i, y[i]);
	for(int i = 1; i <= n; ns[i++] = mn[1]) for(pair<int, int> g : ve[i]) add(1, 1, n, 1, g.first, g.second);
	for(int i = 1; i <= n * 4; i++) tag[i] = mn[i] = 0;
	for(int i = 1; i <= n; i++) add(1, 1, n, i, i, ns[i] + x[i]);
	cout << mn[1] << "\n";
	for(int i, w; q; q--) cin >> i >> w, add(1, 1, n, i, i, w - x[i]), x[i] = w, cout << mn[1] << "\n";
	return 0;
}