#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

char mem[1000 * 1000 * 800];
int mpos = 0;
void* operator new(size_t sz) {
	mpos += sz;
	return mem + mpos - sz;
}
void operator delete(void* ptr) {

}

const int N = 600008;
int p[N], r[N];
ll c1[N], c2[N], res[N];
vector<vector<int>> bt, e;
ll ans = 0;

int getp(int v) {
	while (v != p[v])
		v = p[v];
	return v;
}

void merge(int u, int v) {
	u = getp(u);
	v = getp(v);
	if (u == v)
		return;
	if (r[u] < r[v])
		swap(u, v);
	p[v] = u;
	ans += c1[u] * c2[v] + c1[v] * c2[u];
	c1[u] += c1[v];
	c2[u] += c2[v];
	bt.push_back({u, v, r[u]});
	if (r[u] == r[v])
		r[u]++;
}
void unmerge() {
	int u = bt.back()[0], v = bt.back()[1];
	p[v] = v;
	r[u] = bt.back()[2];
	bt.pop_back();
	c1[u] -= c1[v];
	c2[u] -= c2[v];
	ans -= c1[u] * c2[v] + c1[v] * c2[u];
}

void go(int l, int r, vector<int> &re) {
	vector<int> e1, e2;
	int pos = bt.size();
	int m = (l + r) / 2;
	for (int x : re) {
		if (e[x][2] <= l && r <= e[x][3])
			merge(e[x][0], e[x][1]);
		else if (e[x][3] <= l || r <= e[x][2]) {}
		else {
			if (e[x][2] < m)
				e1.push_back(x);
			if (e[x][3] > m)
				e2.push_back(x);
		}
	}
	if (r - l > 1) {
		go(l, m, e1);
		go(m, r, e2);
	}
	else {
		res[l] = ans;
	}
	while (bt.size() > pos)
		unmerge();
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q, u, v;
	pair<int, int> pr;
	map<pair<int, int>, int> mp;
	cin >> q;
	rep(i, q) {
		cin >> pr.first >> pr.second;
		pr.second += N / 2;
		if (mp.count(pr)) {
			e.push_back({pr.first, pr.second, mp[pr], i});
			mp.erase(pr);
		}
		else
			mp[pr] = i;
	}
	int cq = q;
	for (auto &pp : mp) {
		e.push_back({pp.first.first, pp.first.second, pp.second, cq});
		cq++;
	}
	rep(i, N) {
		p[i] = i;
		if (i < N / 2)
			c1[i] = 1;
		else
			c2[i] = 1;
	}
	vector<int> re(e.size());
	rep(i, e.size())
		re[i] = i;
	go(0, cq, re);
	rep(i, q)
		cout << res[i] << ' ';
}