#include <bits/stdc++.h>
 
using namespace std;
 
#define int int64_t
#define all(x) begin(x), end(x)
const int maxn = 4e5 + 42;
 
int hashed[maxn];
vector<int> ops[2][maxn], cls[2][maxn];
int inter[2][maxn];
 
int xr[2][4 * maxn];
void add(int z, int p, int c, int v = 1, int l = 0, int r = maxn) {
	xr[z][v] ^= c;
	if(r - l > 1) {
		int m = (l + r) / 2;
		if(p < m) {
			add(z, p, c, 2 * v, l, m);
		} else {
			add(z, p, c, 2 * v + 1, m, r);
		}
	}
}
int get(int z, int a, int b, int v = 1, int l = 0, int r = maxn) {
	if(a <= l && r <= b) {
		return xr[z][v];
	} else if(r <= a || b <= l) {
		return 0;
	} else {
		int m = (l + r) / 2;
		return get(z, a, b, 2 * v, l, m) ^ get(z, a, b, 2 * v + 1, m, r);
	}
}
 
void process(int *op, int *cl, int n, int z) {
	for(int i = 0; i < n; i++) {
		ops[z][op[i]].push_back(i);
		cls[z][cl[i]].push_back(i);
	}
	for(int i = 0; i < maxn; i++) {
		for(auto it: ops[z][i]) {
			add(z, cl[it], hashed[it]);
		}
		for(auto it: cls[z][i]) {
			inter[z][it] = get(z, op[it], maxn);
		}
	}
}
 
signed main() {
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int sa[n], ea[n], sb[n], eb[n];
	vector<int> alls;
	for(int i = 0; i < n; i++) {
		cin >> sa[i] >> ea[i] >> sb[i] >> eb[i];
		alls.insert(end(alls), {sa[i], ea[i], sb[i], eb[i]});
		hashed[i] = rng();
	}
	sort(all(alls));
	alls.erase(unique(all(alls)), end(alls));
	for(int i = 0; i < n; i++) {
		sa[i] = lower_bound(all(alls), sa[i]) - begin(alls);
		ea[i] = lower_bound(all(alls), ea[i]) - begin(alls);
		sb[i] = lower_bound(all(alls), sb[i]) - begin(alls);
		eb[i] = lower_bound(all(alls), eb[i]) - begin(alls);
	}
	process(sa, ea, n, 0);
	process(sb, eb, n, 1);
	for(int i = 0; i < n; i++) {
		if(inter[0][i] != inter[1][i]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}