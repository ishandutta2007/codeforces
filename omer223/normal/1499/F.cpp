#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 998244353;


inline int add(const int& lhs, const int& rhs) {
	return (lhs + rhs) % mod;
}

inline int mult(const int& lhs, const int& rhs) {
	return ((ll)lhs*rhs) % mod;
}




const int sz = 5e3 + 5;
int n, k;
vector<int> adj[sz];
int dpe[sz][sz], dpa[sz][sz];
int parr[sz], sarr[sz];


void input() {
	scanf("%d %d", &n, &k);
	foru(i, 0, n - 1) {
		int x, y;
		scanf("%d %d", &x, &y);
		adj[--x].pb(--y);
		adj[y].pb(x);
	}
}

void dfs(int src ,int prv){
	bool leaf = 1;
	int kids = 0;
	dpe[src][0] = 1;
	for (int x : adj[src]) {
		if (x != prv) {
			kids++;
			leaf = 0;
			dfs(x, src);
			dpe[src][0] = mult(dpe[src][0], dpa[x][k]);
		}
	}
	if (leaf) {
		foru(l, 0, k + 1)
			dpa[src][l] = 1;
	}
	else {
		foru(l, 1, k + 1) {
			int pref = 1, suf = 1;
			int idx = 0;
			for (int x : adj[src]) {
				if (x == prv)
					continue;
				pref = mult(pref, add(((l >= 2 && k - l - 1 >= 0) ? dpa[x][min(k - l - 1, l - 2)] : 0), dpa[x][k]));
				parr[idx] = pref;
				idx++;
			}
			int x;
			idx = kids - 1;
			for (int i = adj[src].size() - 1; i >= 0; i--) {
				x = adj[src][i];
				if (x == prv)
					continue;
				suf = mult(suf, add((k - l - 1 >= 0 ? dpa[x][min(k - l - 1, l - 1)] : 0), dpa[x][k]));
				sarr[idx] = suf;
				idx--;
			}
			idx = 0;
			for (int x : adj[src]) {
				if (x == prv)
					continue;
				dpe[src][l] = add(dpe[src][l], mult(dpe[x][l - 1], mult((idx ? parr[idx - 1] : 1), (idx + 1 == kids ? 1 : sarr[idx + 1]))));
				idx++;
			}
		}
		dpa[src][0] = dpe[src][0];
		foru(l, 1, k + 1)
			dpa[src][l] = add(dpa[src][l - 1], dpe[src][l]);
	}
}

int main() {
	fast;
	input();
	dfs(0, -1);
	printf("%d\n", dpa[0][k]);
	return 0;
}