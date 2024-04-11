#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node{
	int a, b, c;
};

node operator + (const node& l, const node &r) {
	int t = min(l.b, r.c);
	node ans;
	ans.a = l.a + r.a + t;
	ans.b = l.b + r.b - t;
	ans.c = l.c + r.c - t;
	
	return ans;
}

int n, q; 
string s;
vector<node> tree(4000002);

void build(int p, int start, int end) {
	if (start == end) {
		if (s[start] == '(') {tree[p].b = 1;}
		else {tree[p].c = 1;}
	} else {
		int mid = (start + end)/2;
		
		build(p*2, start, mid);
		build(p*2+1, mid+1, end);
		
		tree[p] = tree[2*p] + tree[2*p + 1];
	}
}

node query(int p, int start, int end, int l, int r) {
	if (l > end || r < start) return {0, 0, 0};
	if (l <= start && end <= r) return tree[p];
	
	int mid = (start + end)/2;
	
	return query(2*p, start, mid, l, r) + query(2*p + 1, mid+1, end, l, r);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> s; n = s.size();
	s = ' ' + s;
	build(1, 1, n);
	
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		node ans = query(1, 1, n, l, r);
		cout << ans.a * 2 << "\n";
	}
	
	return 0;
}