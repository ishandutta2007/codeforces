#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct stmax{
	int n;
	vector<int> a;
	vector<int> tree;

	stmax(vector<int> a, int n) {
		this->a = a;
		this->n = n;
		tree.resize(4*n + 9);
	}

	void build(int node, int start, int end) {
		if(start == end) {
			tree[node] = a[start];
		} else {
			int mid = (start + end)/2;
			
			build(2*node, start, mid);
			build(2*node+1, mid+1, end);
			  
			tree[node] = max(tree[2*node], tree[2*node+1]);
		}
	}

	void update(int node, int start, int end, int index, int val) {
		if (start == end) {
			a[index] = val;
			tree[node] = val;
		} else {
			int mid = (start + end)/2;
			
			if (start <= index && index <= mid) {update(2*node, start, mid, index, val);}
			else {update(2*node+1, mid+1, end, index, val);}
			
			tree[node] = max(tree[2*node], tree[2*node+1]);
		}
	}

	int query(int node, int start, int end, int l, int r) {
		if (r < start || end < l) {
			return 0;
		}
		if (l <= start && end <= r) {
			return tree[node];
		}
		int mid = (start+end)/2;
		return max(query(2*node, start, mid, l, r), query(2*node+1, mid+1, end, l, r));
	}

	int query(int l, int r) {
		return query(1, 1, n, l, r);
	}
};

int clz(int N) {
	return N ? 32 - __builtin_clz(N) - 1 : -100000;
}

int n, m, q;
int p[200001];
int a[200001];
vector<int> lft(200001);

void input() {
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		p[x] = i;
	}
	for (int i = 1; i <= m; i++) {
		int x; cin >> x;
		a[i] = p[x];
	}
}

int succ(int i, int k, int f[][22]) {
	if (k == 0) return i;

	int b = clz(k);
	int x = f[i][b];

	return succ(x, k - (1 << b), f);
}

void solve() {
	int f[200001][22];
	int last[200001];
	memset(f, 0, sizeof(f));
	memset(last, 0, sizeof(last));

	for (int i = 1; i <= m; i++) {
		int k = a[i] - 1;
		if (k == 0) k = n;

		last[a[i]] = i;
		f[i][0] = last[k];
	}

	for (int j = 1; (1 << j) < m; j++) {
		for (int i = 1; i <= m; i++) {
			if(f[i][j-1] != 0){
				f[i][j] = f[f[i][j-1]][j-1] ;
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		lft[i] = succ(i, n-1, f);
	}
}

void output() {
	stmax st(lft, m);
	st.build(1, 1, m);

	while (q--) {
		int l, r; cin >> l >> r;
		cout << (st.query(l, r) >= l);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	input();
	solve();
	output();
	
	return 0;
}