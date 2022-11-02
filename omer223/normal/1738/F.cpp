#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define pb push_back

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <numeric>
#include <iomanip>
#include <string>
#include <chrono>
#include <complex>
#include <random>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;

const int sz = 2e3 + 5; //PLUS TEN
int cnts[sz], deg[sz], disc[sz];
vector<int> comp[sz];

int ask(int u) {
    if (cnts[u] >= deg[u])return -1;
    cout << "? " << u << endl;
    fflush(stdout);
    int ans;
    cin >> ans;
    cnts[u]++;
	disc[ans]++;
    return ans;
}

struct DisjointSet {
	int fcnt;
	vi f, sz, sumdeg;
	DisjointSet(int size) {
		f.resize(size);
		sz.resize(size);
		sumdeg.resize(size);
		fcnt = size;
		foru(i, 0, size) {
			f[i] = i;
			sz[i] = 1;
			if (i)sumdeg[i] = deg[i];
			comp[i].push_back(i);
		}
	}
	int father(int src) {
		if (src == f[src])return src;
		return f[src] = father(f[src]);
	}
	bool unite(int a, int b) {
		int fa = father(a), fb = father(b);
		if (sz[fa] < sz[fb])swap(fa, fb);
		if (fa == fb)return false;
		f[fb] = fa;
		fcnt--;
		sz[fa] += sz[fb];
		sumdeg[fa] += sumdeg[fb];
		for (int idx : comp[fb])comp[fa].push_back(idx);
		return true;
	}
};

void reset(int n) {
	foru(i, 0, n + 1)cnts[i] = deg[i] = 0, disc[i] = 0;
	foru(i, 0, n + 1)comp[i].clear();
}

void solve() {
	std::random_device rd;
	std::mt19937 g(rd());
    int n;
    cin >> n;
    reset(n + 1);
    foru(i, 0, n)cin >> deg[i + 1];
	DisjointSet dsu(n + 1);
	int queries = 0;
	set<int> done;
	while (queries < n) {
		int mndisc = 1e9;
		for (int i = 1; i <= n; i++) {
			if (!done.count(i)) {
				if (mndisc > disc[i] && deg[i] - disc[i] > 0) {
					mndisc = disc[i];
				}
			}
		}
		int cand = -1;
		int bstidx = -1;
		ll bst = 0;
		for (int i = 1; i <= n; i++) {
			if (done.count(i) || deg[i] - disc[i] <= 0)continue;
			if (disc[i] != mndisc)continue;
			if (deg[i] - disc[i] > bst) {
				bst = deg[i] - disc[i];
				bstidx = i;
			}
		}
		if (bstidx == -1)break;
		cand = bstidx;
		int ret = 0;
		while (ret != -1 && queries<n) {
			int fat = dsu.father(cand);
			if (dsu.sumdeg[fat] <= dsu.sz[fat] * dsu.sz[fat])break;
			ret = ask(cand);
			if (ret == -1)break;
			dsu.unite(ret, cand);
			queries++;
		}
		done.insert(cand);
	}
	cout << "! ";
	for (int i = 1; i <= n; i++)cout << dsu.father(i) << ' ';
	cout << endl;
	fflush(stdout);
}

int main() {
    fast;
	srand(time(0));
    int t;
    cin >> t;
    while (t--)solve();

    return 0;
}