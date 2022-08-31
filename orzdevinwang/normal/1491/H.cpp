#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j), i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = k; i >= i##E; i--)
#define mkp make_pair
#define pii pair<int, int>
#define ll long long
#define db double
#define sz(a) a.size()
#define x first
#define y second
#define vi vector<int>
using namespace std;
const int N = 1e5 + 7;
int n, m, B, cB, a[N];
int tB[N], bl[N], br[N], de[N], sto[N];
bool ok[N];
int getto(int u) {
	return ok[tB[u]] ? max(a[u] - de[tB[u]], 0) : sto[u];
}
int lca(int u, int v) {
	while(getto(u) != getto(v)) {
		if(u > v) swap(u, v);
		v = getto(v);
	} 
//	cout << "ok1\n";

//	cout << u << " " << v << "\n";
//	cout << "orz : " << getto(u) << " " <<getto(v) << "\n";
	while(u != v) {
		if(u > v) swap(u, v);
//		cout << u << " " << v << "\n";
		v = max(a[v] - de[tB[v]], 0);
//		cout << u << " " << v << "\n";
	}
	return v;
}
int f[N];
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
void rebuild(int x) {
	if(ok[x]) return;
	ok[x] = true;
	L(u, bl[x], br[x]) if(a[u] >= bl[x]) ok[x] = false;
//	if(ok[x]) cout << "x : " << bl[x] << " " << br[x] << "\n";
	if(ok[x]) return;
	L(u, bl[x], br[x]) {
		if(a[u] < bl[tB[u]]) f[u] = a[u];
		else f[u] = find(a[u]);
	}
	L(u, bl[x], br[x]) sto[u] = f[u], f[u] = u;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m, --n, B = sqrt(n), cB = (n - 1) / B + 1;
	L(i, 1, n) cin >> a[i], --a[i], tB[i] = (i - 1) / B + 1, f[i] = i;
	L(i, 1, cB) bl[i] = (i - 1) * B + 1, br[i] = min(i * B, n), rebuild(i);
	while(m--) {
		int op, u, v, x, uid, vid;
		cin >> op >> u >> v, --u, --v, uid = tB[u], vid = tB[v];
		if(op == 1) {
			cin >> x;
			if(uid == vid) {
				L(i, u, v) a[i] -= x, a[i] = max(a[i], 0);
				rebuild(uid);
				continue;
			}
			L(i, uid + 1, vid - 1) {
				if(ok[i]) de[i] += x, de[i] = min(de[i], n + 1); 
				else {
					L(j, bl[i], br[i]) a[j] -= x, a[j] = max(a[j], 0);
					rebuild(i);
				}
			} 
			L(i, u, br[uid]) a[i] -= x, a[i] = max(a[i], 0);
			L(i, bl[vid], v) a[i] -= x, a[i] = max(a[i], 0);
			rebuild(uid), rebuild(vid);
		}
		else cout << lca(u, v) + 1 << "\n";
	}
	return 0;
}
/*
100 10 
1 2 3 1 4 2 4 4 3 5 1 7 5 4 12 11 6 8 1 14 5 17 8 11 15 12 9 13 19 20 19 20 22 18 24 23 1 22 26 16 30 34 3 11 26 37 14 24 15 41 16 52 13 7 28 19 28 22 5 5 31 48 60 13 29 4 64 5 1 47 25 29 52 48 44 64 77 19 20 60 80 73 76 54 70 43 58 44 12 75 58 86 14 57 73 14 20 11 63
1 4 36 2
2 24 37
1 55 81 3
2 81 90
2 65 88

1 17 85 5
1 8 40 5
2 33 43
1 36 43 3
2 74 94
*/