#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <map>
#include <queue>
#pragma comment(linker, "/stack:111")
#define ll long long
#define cs(x) (int)x.size()
#define mp make_pair
#define ld long double
using namespace std;

const int N = 500000;
const ll INF = 1e12;
const ll mod = 10;

unordered_map<int, vector<int> > q;
unordered_map<int, unordered_map<int, int> > compress;
struct segment_tree {
	vector<int> arr;
	int n;

	int get(int v, int curl, int curr, int x) {
		int ans = arr[v];
		if (curl == curr)
			return ans;
		int m = (curl + curr) / 2;
		if (m >= x)
			return ans + get(v * 2, curl, m, x);
		else
			return ans + get(v * 2 + 1, m + 1, curr, x);
	}

	void add(int v, int curl, int curr, int l, int r, int k) {
		if (curl > r || curr < l)
			return;
		if (curl >= l && curr <= r) {
			arr[v] += k;
			return;
		}
		int m = (curl + curr) / 2;
		add(v * 2, curl, m, l, r, k);
		add(v * 2 + 1, m + 1, curr, l, r, k);
	}

	void init(int n) {
		this->n = n;
		int k = 1;
		while (k < n)
			k *= 2;
		k *= 2;
		arr.resize(k);
	}
};

unordered_map<int, segment_tree> segment;

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("kthpath.in", "r", stdin);
	int n;
	cin >> n;
	vector < pair<int, pair<int, int> > > arr(n);
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[i] = mp(a, mp(b, c));
		q[c].push_back(b);
	}
	for (auto & el : q) {
		sort(el.second.begin(), el.second.end());
		int count = 0;
		for (auto c : el.second) {
			compress[el.first][c] = count++;
		}
	}
	for (auto & el : q) {
		segment[el.first].init(cs(el.second));
	}
	for (auto el : arr) {
		if (el.first == 1) {
			int pos = compress[el.second.second][el.second.first];
			int sz = cs(q[el.second.second]);
			segment[el.second.second].add(1, 0, sz - 1, pos, sz - 1, 1);
		}
		else if (el.first == 2) {
			int pos = compress[el.second.second][el.second.first];
			int sz = cs(q[el.second.second]);
			segment[el.second.second].add(1, 0, sz - 1, pos, sz - 1, -1);
		}
		else {
			int pos = compress[el.second.second][el.second.first];
			int sz = cs(q[el.second.second]);
			cout << segment[el.second.second].get(1, 0, sz - 1, pos) << "\n";
		}
	}
	return 0;
}