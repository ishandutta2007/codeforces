#include <bits/stdc++.h>
using namespace std;

struct johnwick_tree{
	int n;
	vector<long long> tree;
 
	johnwick_tree(int n) {
		this->n = n;
		tree.resize(n+3);
	}
 
	void update(int p, long long val){
		for (int i = p; i <= n; i += i & -i) {
			tree[i] += val;
		}
	}
	
	long long sum(int p) {
		long long ans = 0;
		for (int i = p; i; i -= i & -i) {
			ans += tree[i];
		}
		return ans;
	}
} tr(400000);

const int MAXN = 400008;
const long long M = 2e9;

int petr = 1;
int l[MAXN], r[MAXN];
long long c[MAXN];
int ans[MAXN];
int lst[MAXN];

void intake(int id) {
	int k; cin >> k;
	l[id] = petr;
	vector<int> x, y;
	for (int i = 0; i < k; i++) {
		int xx, yy; cin >> xx >> yy;
		x.push_back(xx);
		y.push_back(yy);
	}
	x.push_back(x[0]);
	y.push_back(y[0]);
	
	for (int i = 1; i <= k; i++) {
		int xv = x[i] - x[i-1];
		int yv = y[i] - y[i-1];
		
		int g = abs(__gcd(xv, yv));
		xv /= g;
		yv /= g;
		
		long long kk = 1LL*xv*M + 1LL*yv;
		c[petr++] = kk;
	}
	
	r[id] = petr;
}

void coordinateCompression() {
	set<long long> s;
	for (int i = 1; i < petr; i++) {
		s.insert(c[i]);
	}
	map<long long, int> mp;
	int id = 0;
	for (long long cc: s) {
		mp[cc] = id++;
	}
	for (int i = 1; i < petr; i++) {
		c[i] = mp[c[i]];
	}
}
 
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
 
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		intake(i);
	}
	coordinateCompression();
	
	vector<tuple<int, int, int>> que;
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int x, y; cin >> x >> y;
		que.emplace_back(r[y] - 1, l[x], i);
	}
	sort(que.begin(), que.end());
	
	memset(lst, -1, sizeof(lst));
	int p = 0;
	for (int i = 1; i < petr; i++) {
		if (lst[c[i]] != -1) {
			tr.update(lst[c[i]] + 1, -1);
		}
		
		lst[c[i]] = i;
		tr.update(i+1, 1);
		
		while (p < q && get<0>(que[p]) == i) { 
			ans[get<2>(que[p])] = tr.sum(get<0>(que[p]) + 1) - tr.sum(get<1>(que[p])); 
			p++; 
		} 
	}
	
	for (int i = 0; i < q; i++) {
		cout << ans[i] << '\n';
	}
 
	return 0;
}