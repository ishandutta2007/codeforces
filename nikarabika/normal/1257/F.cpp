//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

struct Node {
	int val;
	map<short int, Node *> adj;
};

const int maxn = 100 + 10,
	  maxl = 30,
	  maxl2 = 15;
int vec[maxn][maxn];
int sum[1 + (1 << maxl2)][maxn];
int a[maxn];
int n;
Node *root;

Node *insert(int id, int pos = 0, Node *node = root) {
	if (node == nullptr)
		node = new Node();
	if (pos == n) {
		node->val = id;
		return node;
	}
	node->adj[sum[id][pos]] = insert(id, pos + 1, node->adj[sum[id][pos]]);
	return node;
}

int find(int id, int pos = 0, Node *node = root) {
	if (node == nullptr) return -1;
	if (pos == n) return node->val;
	return find(id, pos + 1, node->adj[sum[id][pos]]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	root = new Node();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < maxl; j++)
			if ((a[i] >> j) & 1)
				vec[j][i] = -1;
			else
				vec[j][i] = +1;
	}
	for (int i = 0; i < n; i++)
		sum[0][i] = __builtin_popcount(a[i]);
	for (int mask = 0; mask < (1 << maxl2); mask++) {
		if (mask) {
			int rm = __builtin_ctz(mask);
			int nmask = mask & (mask - 1);
			for (int i = 0; i < n; i++)
				sum[mask][i] = sum[nmask][i] + vec[rm][i];
		}
		insert(mask);
	}
	memset(sum, 0, sizeof sum);
	for (int mask = 0; mask < (1 << maxl2); mask++) {
		if (mask) {
			int rm = __builtin_ctz(mask);
			int nmask = mask & (mask - 1);
			for (int i = 0; i < n; i++)
				sum[mask][i] = sum[nmask][i] + vec[rm + maxl2][i];
		}
		for (int i = 0; i < n; i++)
			sum[1 << maxl2][i] = -sum[mask][i];
		for (int res = 0; res <= maxl; res++) {
			int val = find(1 << maxl2);
			if (~val)
				return cout << (mask << maxl2) + val << '\n', 0;
			for (int i = 0; i < n; i++)
				sum[1 << maxl2][i]++;
		}
	}
	cout << -1 << '\n';
	return 0;
}