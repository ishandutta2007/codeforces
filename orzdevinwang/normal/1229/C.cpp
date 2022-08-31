/*
 /ll 
 /ll 
*/ 
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e5 + 7;
int n, a[N], deg[N], m;
ll ns;
vi e[N], s[N];
void win (int x, int w) {
	for (const int &v : s[x]) {
		ns -= deg[x];
		ns -= sz(e[v]) - 1;
		deg[v] -= 1;
		ns += deg[v] * 2;
		s[v].push_back(x);
	}
	s[x].clear ();
	a[x] = w;
	deg[x] = sz(e[x]);
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> m;
	L(i, 1, m) {
		int u, v;
		cin >> u >> v;
		if(u > v) swap (u, v);
		deg[v] += 1;
		e[u].push_back(v);
		e[v].push_back(u);
		s[u].push_back(v);
	} 
	L(x, 1, n) for (const int &v : e[x]) if(x > v) ns += deg[v];
	L(i, 1, n) a[i] = i;
	cout << ns << '\n';
	int q;
	cin >> q;
	L(t, 1, q) {
		int x;
		cin >> x;
		win (x, t + n);
		cout << ns << '\n';
	}
	return 0;
}