#include <bits/stdc++.h>
        
using namespace std;
        
        
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
        
//#define GCC optimize("O3, Ofast")
//#define GCC optimize("unroll-loops")
#define aidar asadulin
         
#define int long long
#define ull long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define size(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double
        
const int inf = 5e9 + 7;
const int max_n = 2e5 + 3;

int n;
set<int> gr[max_n];
int fib[30];
int sz[max_n];

void scan() {
	fib[0] = fib[1] = 1;
	for(int i = 2;i < 30;i++)
		fib[i] = fib[i - 1] + fib[i - 2];

	cin >> n;
	for(int i = 0;i < n - 1;i++) {
		int v1, v2;
		cin >> v1 >> v2;
		gr[--v1].emplace(--v2);
		gr[v2].emplace(v1);
	}
}

void build_sz(int v, int pr = -1) {
	sz[v] = 1;
	for(int to : gr[v]) {
		if (to != pr) build_sz(to, v), sz[v] += sz[to];
	}
}

bool find_cut(int v, int pr, int st, int& r1, int& r2) {
	for(int to : gr[v]) {
		if (to == pr) continue;
		if (sz[to] == fib[st - 1] || sz[to] == fib[st - 2]) {
			r1 = v, r2 = to;
			gr[v].erase(to);
			gr[to].erase(v);
			return true;
		}
		if (find_cut(to, v, st, r1, r2)) return true;
	}
	return false;
}


bool solve() {
	scan();

	deque<int> rts{0};

	while(size(rts)) {
		int v = rts.front(); rts.pop_front();
		build_sz(v);
		if (sz[v] == 1) continue;

		int r1, r2;
		int st = lower_bound(fib, fib + 30, sz[v]) - fib;

		if (fib[st] != sz[v]) return false;
		if (!find_cut(v, -1, st, r1, r2)) return false;
		rts.emplace_back(r1);
		rts.emplace_back(r2);
	}
	return true;
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    cout << (solve() ? "YES" : "NO") << endl;
}