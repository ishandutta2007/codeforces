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
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double
        
const int inf = 1e18 + 7;
const int max_n = 1e5 + 3;

int n;
vector<int> gr[max_n];

pii dfs(int v, int pr) {
	pii res(0, v);
	for(int to : gr[v]) {
		if (to == pr) continue;
		pii t = dfs(to, v);
		t.fi++;
		chkmax(res, t);
	}
	return res;
}

int dfs1(int v, int pr, int fin) {
	if (v == fin) return 0;
	for(int to : gr[v]) {
		if (to != pr) {
			int r = dfs1(to, v, fin);
			if (r != -1) return r + 1; 
		}
	}
	return -1;
}

bool solve() {
	int a, b, da, db;
	cin >> n >> a >> b >> da >> db;
	a--; b--;
	for(int i = 0;i < n;i++)
		gr[i].clear();
	for(int i = 0; i< n - 1;i++) {
		int v1, v2;
		cin >> v1 >> v2;
		gr[--v1].emplace_back(--v2);
		gr[v2].emplace_back(v1);
	}
	int dist = dfs1(a, -1, b);
	if (dist <= da) return false;
	if (db <= 2 * da) return false;
	pii to = dfs(0, -1);
	to = dfs(to.se, -1);
	return to.fi > 2 * da;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--) {
    	cout << (solve() ? "Bob" : "Alice") << endl;
    }
}