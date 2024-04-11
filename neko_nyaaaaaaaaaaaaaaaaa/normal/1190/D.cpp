#include <bits/stdc++.h>
using namespace std;
 
#define int long long

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
} tr(300000);
 
int ptr = 0;
map<int, int> indexer;
 
void coordinateCompression(vector<int> y) {
	sort(y.begin(), y.end());
 
	for (int i = 0; i < y.size(); i++) {
		if (i == 0 || y[i] != y[i-1]) {
			indexer[y[i]] = ++ptr;
		}
	}
}

int ans = 0;

int query(int l, int r) {
	if (l > r) return 0;
	return tr.sum(r) - tr.sum(l - 1);
}
 
void solve(vector<int> xk) {
	for (int i: xk) {
		int id = indexer[i];
		if (!query(id, id)) {
			tr.update(id, 1);
		}
	}
	
	int cnt = query(1, ptr);
	ans += cnt*(cnt + 1)/2;
	
	sort(xk.begin(), xk.end());
	for (int i = 1; i < xk.size(); i++) {
		int l = indexer[xk[i-1]], r = indexer[xk[i]];
		
		cnt = query(l + 1, r - 1);
		ans -= cnt*(cnt + 1)/2;
	}
	
	int l = 0, r = indexer[xk[0]];
	cnt = query(l + 1, r - 1);
	ans -= cnt*(cnt + 1)/2;
	
	l = indexer[xk.back()], r = ptr+1;
	cnt = query(l + 1, r - 1);
	ans -= cnt*(cnt + 1)/2;
	
	//for (int i: xk) cout << i << ' ';
	//cout << endl;
}
 
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
 
	int n;
	cin >> n;
	map<int, vector<int>> v;
	vector<int> yy;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> y >> x;
		v[x].push_back(y);
		yy.push_back(y);
	}
	coordinateCompression(yy);
	
	johnwick_tree tr(n);
	vector<vector<int>> xk;
	for (auto u: v) {
		xk.push_back(u.second);
	}
	while (xk.size()) {
		solve(xk.back());
		xk.pop_back();
	}
	cout << ans;
 
	return 0;
}