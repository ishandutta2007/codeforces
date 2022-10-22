#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)

using namespace std;
const int N = 1e6 + 5;
int n, m, fa[N], deg[N], vis[N], u, v, s, k, x;
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int read() {
	int c = getchar(), r = 0;
	while(c < 48) c = getchar();
	while(c > 47) r = r * 10 + c - 48, c = getchar();
	return r;
}
int main() {
	cin >> n >> m;
	rep(i, 1, n) fa[i] = i;
	deg[1] = 2;
	rep(i, 1, m) {
		deg[u = read()]++, deg[v = read()]++;
		if((u = find(u)) ^ (v = find(v))) fa[u] = v;
	}
	rep(i, 1, n) if(deg[i] & 1) s++, vis[find(i)] = 1;
	rep(i, 1, n) if(i == fa[i] && deg[i]) k++, x += vis[i];
	if(k == 1) return cout << s / 2, 0; 
	if(!s) return cout << k, 0;
	return cout << s / 2 + k - x, 0;
}