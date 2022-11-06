#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

struct node
{
	std::vector<int> s;
	node *n[2];
	node() {
		n[0] = NULL;
		n[1] = NULL;
	};
};

int vs(node *r) {
	if (r) return r->s.size();
	return 0;
}

int ans = 0;

void add(node *root, int val) {
	root->s.pb(val);
	for (int i = 30; i >= 0; --i) {
		if (val & (1 << i)) {
			root = (root->n[1] ? root->n[1] : (root->n[1] = new node()));
			root->s.pb(val);
		} else {
			root = (root->n[0] ? root->n[0] : (root->n[0] = new node()));
			root->s.pb(val);
		}
	}
}

int query(node *root, int val, int in) {
	int re = 0;
	for (int i = in; i >= 0; --i) {
		if (val & (1 << i)) {
			if (root->n[1])
				root = root->n[1];
			else
				root = root->n[0],
				re = re | (1 << i);
		} else {
			if (root->n[0])
				root = root->n[0];
			else
				root = root->n[1],
				re = re | (1 << i);
		}
	}
	return re;
}

void dfs(node *root, int i) {
	if (root->n[0]) dfs(root->n[0], i - 1);
	if (root->n[1]) dfs(root->n[1], i - 1);
	if (root->n[1] && root->n[0]) {
		if (vs(root->n[1]) > vs(root->n[0])) {
			int mi = (1 << 30) + 1;
			for (int v : root->n[0]->s)
				mi = min(mi, query(root->n[1], v, i - 1));
			ans += (mi | (1 << i));
		} else {
			int mi = (1 << 30) + 1;
			for (int v : root->n[1]->s)
				mi = min(mi, query(root->n[0], v, i - 1));
			ans += (mi | (1 << i));
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	node *root = new node();
	int n; cin >> n;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	for (int i = 0; i < n; ++i) add(root, a[i]);
	dfs(root, 30);
	cout << ans;
}