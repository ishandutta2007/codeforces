#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> a(200001);
vector<int> tree(800001);

void build(int node, int start, int end) {
	if(start == end) {
      	tree[node] = a[start];
	} else {
		int mid = (start + end)/2;
		
	      build(2*node, start, mid);
	      build(2*node+1, mid+1, end);
	      
	      tree[node] = min(tree[2*node], tree[2*node+1]);
	}
}

int query(int node, int start, int end, int l, int r) {
	if (r < start || end < l) {
		return INT_MAX;
	}
	if (l <= start && end <= r) {
		return tree[node];
	}
	int mid = (start+end)/2;
	return min(query(2*node, start, mid, l, r), query(2*node+1, mid+1, end, l, r));
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 0) {a[i] = 1000000000;}
	}
	build(1, 1, n);
	
	vector<int> fi(q+1), se(q+1);
	for (int i = 1; i <= n; i++) {
		if (a[i] != 1000000000) se[a[i]] = i;
	}
	for (int i = n; i; i--) {
		if (a[i] != 1000000000) fi[a[i]] = i;
	}
	
	for (int i = 1; i <= q; i++) {
		if (fi[i] == 0 && se[i] == 0) continue;
		
		int k = query(1, 1, n, fi[i], se[i]);
		if (k < i) {cout << "NO"; return 0;}
	}
	
	if (fi[q] == 0 && se[q] == 0) {
		bool flag = 1;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1000000000) {
				a[i] = q; flag = 0; break;
			}
		}
		if (flag) {cout << "NO"; return 0;}
	}
	
	cout << "YES\n";
	int prev = 1; int pt = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] != 1000000000) {
			for (int j = pt+1; j < i; j++) {
				a[j] = min(prev, a[i]);
			}
			prev = a[i];
			pt = i;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1000000000) cout << "1 ";
		else cout << a[i] << " ";
	}
	
	return 0;
}