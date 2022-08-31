#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
int n, sv = -1, m, f[N], deg[N], seg[N], cnt;
ll ans;
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) f[i] = i;
	L(i, 1, m) {
		int u, v;
		cin >> u >> v;
		seg[u] ++, seg[v] ++;
		if(u == v) {
			cnt ++;
			continue;
		}
		deg[u] ++, deg[v] ++;
		f[find(u)] = find(v);
	}
	
	L(i, 1, n) if(seg[i]) {
		if(sv == -1) sv = find(i);
		else if(sv != find(i)) return cout << "0\n", 0; 
	}
	
	ans = (ll) cnt * (m - cnt) + (ll) cnt * (cnt - 1) / 2;
	L(i, 1, n) ans += (ll) deg[i] * (deg[i] - 1) / 2;
	cout << ans << "\n";
	return 0;
}