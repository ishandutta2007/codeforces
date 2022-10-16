#include <bits/stdc++.h>
using namespace std;

vector<int> tree(900000, 0);
vector<int> lazy(900000, 0);

void update(int node, int start, int end, int l, int r, int val) {

	if (lazy[node] != 0) {
		tree[node] += lazy[node];   // Update
		if(start != end) {
			lazy[node*2] += lazy[node];                  // Mark child as lazy
			lazy[node*2+1] += lazy[node];                // Mark child as lazy
		}
		lazy[node] = 0;						// Reset
	}

	if (start > end || start > r || end < l) {return;}

	if (start >= l && end <= r) {
		tree[node] += val;
		if(start != end) {
			lazy[node*2] += val;
			lazy[node*2+1] += val;
		}
		return;
	}

	int mid = (start + end) / 2;
	update(node*2, start, mid, l, r, val);        // Updating left child
	update(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child

	tree[node] = max(tree[2*node], tree[2*node+1]);
}

int query(int node, int start, int end, int l, int r) {
	if (lazy[node] != 0) {
		tree[node] += lazy[node];
		if (start != end) {
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if (start > end || start > r || end < l) {return 0;}

	if (start >= l && end <= r) {return tree[node];}

	int mid = (start + end)/2;
	int p1 = query(node*2, start, mid, l, r);
	int p2 = query(node*2 + 1, mid+1, end, l, r);
	return max(p1, p2);
}
 
int rot = 0;
void process(int n, vector<int> &a) {
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			rot = (n-i);
			rotate(a.begin(), a.begin()+i, a.end());
			a.push_back(1);
			return;
		}
	}
}
 
vector<int> solve(int n, vector<int> a) {
	for (auto &i: tree) i = 0;
	for (auto &i: lazy) i = 0;

	vector<int> res(n);
	res[0] = 1;
 
	stack<int> st;
	st.push(0);
	for (int i = 1; i < n; i++) {
		while (a[i] < a[st.top()]) {
			st.pop();
		}
		update(1, 0, n-1, i, i, st.size());
		update(1, 0, n-1, st.top() + 1, i, 1);
		st.push(i);
		res[i] = query(1, 0, n-1, 0, i);
	}
	res.push_back(0);
 
	return res;
}
 
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
 
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	process(n, a);
 
	vector<int> pre = solve(n, a);
	reverse(a.begin(), a.end());
	vector<int> suf = solve(n, a);
	reverse(a.begin(), a.end());
	reverse(suf.begin(), suf.end());
 
	//for (int i: pre) cout << i << ' '; cout << endl;
	//for (int i: suf) cout << i << ' '; cout << endl;
 
	int idx = 0, rl = 0;
	for (int i = 0, j = n-1; i < n; i++, j = (j - 1 + n) % n) {
		if (max(pre[i], suf[i+1]) < max(pre[idx], suf[idx+1])) {
			idx = i;
			rl = j;
		}
	}
 
	//cout << rot << '\n';
	cout << max(pre[idx], suf[idx+1]) << ' ' << (n - ((rl + rot) % n)) % n << '\n';
 
	return 0;
}