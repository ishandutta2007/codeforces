#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<random>
//#include<unordered_set>

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> st;*/

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define ld long double
#define int long long

const int MOD = 998244353;

mt19937 rnd(51);

const int N = 2e5 + 10;
vector<int> t(4 * N);
vector<int> a;

void build(int v, int l, int r) {
	if (l == r) {
		t[v] = a[l];
		return;
	}
	int m = (l + r) / 2;
	build(2 * v, l, m), build(2 * v + 1, m + 1, r);
	t[v] = min(t[v * 2], t[v * 2 + 1]);
}

int mn(int v, int tl, int tr, int l, int r) {
	if (l > r) {
		return 1e18;
	}
	if (tl == l && tr == r) {
		return t[v];
	}
	int tm = (tl + tr) / 2;
	return min(mn(2 * v, tl, tm, l, min(r, tm)), mn(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	a.resize(n);
	vector<int> b(m);
	map<int, int> ind;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ind[a[i]] = i;
	}
	build(1, 0, n - 1);
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	bool x = 0;
	for (int i = 0; i < m - 1; i++) {
		if (ind[b[i]] > ind[b[i + 1]]) {
			x = 1;
		}
	}
	if (x) {
		cout << 0;
		return 0;
	}
	int now = 1;
	if (mn(1, 0, n - 1, 0, ind[b[0]]) != b[0]){
        now = 0;
	}
	if (mn(1, 0, n - 1, ind[b[m - 1]], n - 1) != b[m - 1]){
        now = 0;
	}
	for (int i = 0; i < m - 1; i++) {
		int cnt = 0;
		for (int j = ind[b[i]]; j < ind[b[i + 1]]; j++) {
			if (mn(1, 0, n - 1, ind[b[i]], j) == b[i] && mn(1, 0, n - 1, j + 1, ind[b[i + 1]]) == b[i + 1]) {
				cnt++;
			}
		}
		now *= cnt;
		now %= MOD;
	}
	cout << now << endl;
	return 0;
}