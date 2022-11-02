#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define rep(i, k, n) foru(i, k, n)
#define sz(a) (int)(a.size())

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
#include <random>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;


//ty kactl
struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({ b, sz(adj[b]), c, c });
		adj[b].push_back({ a, sz(adj[a]) - 1, rcap, rcap });
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		rep(L, 0, 31) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

int n, m;
const int offset = 0, sz = 1e4 + 5;
bitset<sz> s;
int a[sz];
int indeg[sz], outdeg[sz];




int main() {
    fast;
    cin >> n >> m;
    foru(i, 0, n) {
        int x;
        cin >> x;
        if (x)s[i + 1] = 1;
    }
    foru(i, 0, n) {
        cin >> a[i + 1];
    }
	Dinic d = Dinic(n + 3 + m);
	int x, y;
	ll givesum = 0;
	vector<pii> ed;
	foru(i, 0, m) {
		cin >> x >> y;
		ed.push_back({ x,y });
		outdeg[x]++;
		indeg[y]++;
		if (s[x] ^ s[y])givesum++;
		d.addEdge(0, n + 2 + i, 1);
		d.addEdge(n + 2 + i, x, 1);
		d.addEdge(n + 2 + i, y, 1);
	}
	ll ones_sum = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i])ones_sum += a[i];
	}
	if (abs(ones_sum) > givesum) {
		cout << "NO\n";
		return 0;
	}
	bool bad = 0;
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == 0)continue;
		if (abs(a[i]) > indeg[i] + outdeg[i]) {
			bad = 1;
			break;
		}
		int delta = -(indeg[i] + outdeg[i]);
		if ((a[i] - delta) & 1)bad = 1;
		if ((abs(a[i]) < delta))bad = 1;
		else {
			d.addEdge(i, n + 1, (a[i] - delta) / 2); //what??
			sum += ((a[i] - delta) / 2);
		}
	}
	if (bad) {
		cout << "NO\n";
		return 0;
	}
	ll Delta = m - sum;
	if (Delta < 0) {
		cout << "NO\n";
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (s[i])continue;
		d.addEdge(i, n + m + 2, 1e5 + 5);
	}
	d.addEdge(n + m + 2, n + 1, Delta);
	ll ans = d.calc(0, n + 1);
	if (ans == m) {
		cout << "YES\n";
		auto adj = d.adj;
		for (int i = n+2; i < n+m+2; i++) {
			for (Dinic::Edge e : adj[i]) {
				if (e.flow() == 1 && e.to >= 1 && e.to <= n) {
					pii ii = ed[i - n - 2];
					if (ii.ff == e.to)swap(ii.ff, ii.ss);
					cout << ii.ff << ' ' << ii.ss << '\n';
				}
				else continue;
			}
		}
	}
	else cout << "NO\n";
    return 0;
}