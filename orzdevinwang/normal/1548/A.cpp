#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int >
#define sz(a) ((int) a.size())
using namespace std;
const int N = 5e5 + 7, mod = 998244353;
int n, m, q, ns, nt[N];
void mk (int w, int u, int v) {
	if(u > v) swap(u, v);
	if(w == 1) {
		nt[u] ++;
		if (nt[u] == 1) ++ns;
	} 
	else {
		nt[u] --;
		if (nt[u] == 0) --ns; 
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		mk (1, u, v);
	}
	cin >> q;
	while (q--) {
		int u, v, w;
		cin >> w;
		if(w == 3) 
			cout << n - ns << "\n";
		else {
			cin >> u >> v;
			mk(w, u, v);
		}
	}
	return 0;
}