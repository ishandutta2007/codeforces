#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

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

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;


struct DisjointSet {
	int fcnt;
	vi f, sz;
	DisjointSet(int size) {
		f.resize(size);
		sz.resize(size);
		fcnt = size;
		foru(i, 0, size) {
			f[i] = i;
			sz[i] = 1;
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
		sz[fa] = max(sz[fa], sz[fb] + 1);
		return true;
	}
};


void solve() {
    int n;
    cin >> n;
	vector<pair<pii, pii>> v;
    foru(i, 0, n) {
        int c, l, r;
        cin >> c >> l >> r;
		v.push_back({ {l,r}, {c, i} });
    }
	DisjointSet dsu(n);
	priority_queue<pii, vector<pii>, greater<pii>> pq[2];
	sort(v.begin(), v.end());
	foru(i, 0, n) {
		auto ii = v[i];
		int l = ii.ff.ff, r = ii.ff.ss, col = ii.ss.ff, idx = ii.ss.ss;
		foru(j, 0, 2) {
			while (!pq[j].empty() && pq[j].top().ff < l)pq[j].pop();
		}
		pq[col].push({ r,idx });
		if (!pq[1 - col].empty()) {
			foru(j, 0, 2) {
				pii bst;
				while (!pq[j].empty()) {
					bst = pq[j].top(); pq[j].pop();
					dsu.unite(idx, bst.ss);
				}
				pq[j].push(bst);
			}
		}
	}
	cout << dsu.fcnt << '\n';
}


int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}