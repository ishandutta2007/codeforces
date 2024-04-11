#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long 
#define rs(x) resize(x)
using namespace std;
const int N = 1007, M = 107;
int n, m, k, siz[N];
int f[N];
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
bool vis[N], ok[N];
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	L(i, 1, k) {
		int w;
		cin >> w;
		vis[w] = true;
	}
	L(i, 1, n) f[i] = i;
	L(i, 1, m) {
		int u, v;
		cin >> u >> v;
		f[find(u)] = find(v);
	}
	L(i, 1, n) siz[find(i)] += 1;
	L(i, 1, n) if(vis[i]) ok[find(i)] = true;
	int ret = 0;
	L(i, 1, n) 
		if(siz[i] && !ok[i]) 
			ret += siz[i];
	int mx = 0, ns = 0;
	L(i, 1, n) 
		if(siz[i] && ok[i]) {
			mx = max(mx, siz[i]);
			ns += siz[i] * (siz[i] - 1) / 2;
		}
	ns -= mx * (mx - 1) / 2;
	mx += ret;
	ns += mx * (mx - 1) / 2;
	cout << ns - m << '\n';
	return 0;
}