#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void func(vector<int>& l, vector<int>& r, string& s, vector<int>& p, int node = 1) {
	if (node == 0)return;
	func(l, r, s, p, l[node]);
	p.push_back(node - 1);
	func(l, r, s, p, r[node]);
}

void func(vector<int>& l, vector<int>& r, vector<int>& ok, vector<int>& two, vector<int>& p, vector<int>& parent, int node = 1, int depth = 1) {
	if (l[node]) {
		func(l, r, ok, two, p, parent, l[node], depth + 1);
	}
	if (!ok[node-1]&&two[node-1]==0)return;
	if (two[node - 1] == 0) {
		if (K < depth)return;
		K -= depth;
		int box = node;
		while (box && two[box - 1] == 0) {
			//	cout << "box " << box << endl;
			two[box - 1] = 1;
			box = parent[box];
		}
	}
	depth = 0;
	if (r[node]) {
		func(l, r, ok, two, p, parent, r[node], depth + 1);
	}
}

void Solve() {
	cin >> N >> K;
	string s;
	cin >> s;
	vector<int>l(N + 1);
	vector<int>r(N + 1);
	vector<int>parent(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> l[i] >> r[i];
		parent[l[i]] = i;
		parent[r[i]] = i;
	}
	vector<int>p;
	func(l, r, s, p);
	vector<int>ok(N);
	vector<int>two(N);
	vector<int>inv(N + 1);
	for (int i = N - 2; i >= 0; i--) {
		if (s[p[i]] == s[p[i + 1]]) {
			ok[p[i]] = ok[p[i + 1]];
		}
		else if (s[p[i]] < s[p[i + 1]]) {
			ok[p[i]] = 1;
		}
	}
	//for (auto i : ok)cout << i;
	//cout << endl;
	func(l, r, ok, two, p, parent);
	//for (auto i : two)cout << i;
	//cout << endl;
	//cout << K << endl;
	for (int i = 0; i < N; i++) {
		cout << s[p[i]];
		if (two[p[i]] == 1)cout << s[p[i]];
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	//cin >> T;
	while (T--) {
		Solve();
	}
}