#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 2e3 + 7;
int n, m, col[N];
bitset < N > e[N];
void solve (set < int > cur) {
	int p = -1;
	for (int u : cur) if((e[u].count ()) & 1) {
		for (int v = e[u]._Find_first(); v <= n; v = e[u]._Find_next(v)) 
			e[v] ^= e[u], e[v].reset (v), e[v].reset (u);
		cur.erase (u);
		p = u;
		break;
	}
	if(p == -1) {
		for (int u : cur) col[u] = 1;
	}
	else {
		solve (cur);
		int cnt = 0;
		for (int v = e[p]._Find_first(); v <= n; v = e[p]._Find_next(v)) 
			if(col[v] == 1) cnt += 1;
		if (cnt & 1) col[p] = 2;
		else col[p] = 1;
	}
}
void Main () {
	cin >> n >> m;
	L(i, 1, m) {
		int u, v;
		cin >> u >> v;
		e[u].set (v);
		e[v].set (u);
	}
	bool tri = true;
	L(i, 1, n) if(e[i].count () & 1) tri = false;
	if(tri) {
		cout << 1 << '\n';
		L(i, 1, n) cout << 1 << ' ';
		cout << '\n';
	}
	else {
		set < int > S; 
		L(i, 1, n) S.insert(i);
		solve (S);
		cout << 2 << '\n';
		L(i, 1, n) cout << col[i] << ' ';
		cout << '\n'; 
	}
	L(i, 1, n) e[i].reset ();
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main (); 
	return 0;
}