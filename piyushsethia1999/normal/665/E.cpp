#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

struct node
{
	int cnt;
	node *n[2];
	node() : cnt(0) {
		n[0] = NULL;
		n[1] = NULL;
	};
};

void add(node *root, int val) {
	root->cnt++;
	for (int i = 30; i >= 0; --i) {
		if (val & (1 << i)) {
			root = (root->n[1] ? root->n[1] : (root->n[1] = new node()));
			root->cnt++; 
		} else {
			root = (root->n[0] ? root->n[0] : (root->n[0] = new node()));
			root->cnt++; 
		}
	} 
}

int query(node *root, int val, int def) {
	int re = 0;
	for (int i = 30; i >= 0; --i) {
		if (val & (1 << i)) {
			if (def & (1 << i))	root = (root->n[0] ? root->n[0] : (root->n[0] = new node()));
			else root = (root->n[1] ? root->n[1] : (root->n[1] = new node()));
		} else {
			if (def & (1 << i)) {
				re += (root->n[0] ? root->n[0]->cnt : 0);
				root = (root->n[1] ? root->n[1] : (root->n[1] = new node()));
			} else {
				re += (root->n[1] ? root->n[1]->cnt : 0);
				root = (root->n[0] ? root->n[0] : (root->n[0] = new node()));
			}
		}
	}
	return re;
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	node *root = new node();
	int n; cin >> n;
	int k; cin >> k; k--;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	int re = 0;
	int t = 0;
	for (int i = 0; i < n; ++i) {
		add(root, t);
		t ^= a[i];
		re += query(root, k, t);
	}
	cout << re << "\n";
}