#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int >
#define sz(a) ((int) a.size())
using namespace std;
const int N = (1 << 20), inf = 1e7;
int n, f[N], a[N], A[N];
inline int ano (int x) { return x % 2 == 1 ? x + 1 : x - 1; }
int find (int x) {
	return f[x] == x ? x : f[x] = find (f[x]);
}
void merge (int x, int y) {
	x = find (x), y = find(y);
	if(f[x] != f[y]) f[x] = f[y];
}
int mat[N], le[N], tp;
vi s[N];
bool check(int x) {
	L(i, 1, n) f[i * 2] = f[i * 2 - 1] = i * 2;
	L(i, 0, (1 << x) - 1) s[i].clear ();
	L(i, 1, n * 2) a[i] = A[i] & ((1 << x) - 1), s[a[i]].push_back(i);
	L(i, 0, (1 << x) - 1) {
		if(sz(s[i]) & 1) return false ;
		L(j, 0, sz(s[i]) / 2 - 1) {
			int u = s[i][j * 2], v = s[i][j * 2 + 1];
			merge (u, v), mat[u] = v, mat[v] = u;
		} 
	} 
//	cout <<x << " : "; 
//	L(i, 1, n * 2) cout << find(i) << ' ';
//	cout << '\n';
	L(i, 0, (1 << x) - 1) {
		L(j, 1, sz(s[i]) / 2 - 1) {
			int u = s[i][j * 2], v = s[i][j * 2 + 1];
			if(find(u) != find (s[i][0])) {
				int x = s[i][0], y = mat[s[i][0]];
				mat[u] = x, mat[x] = u;
				mat[v] = y, mat[y] = v;
				merge (x, u);
			}
		}
	} 
	L(i, 1, n * 2) if(find(i) != find(1)) return false;
	int u = 1;
	tp = 0;
	while (tp < n * 2) le[++tp] = u, u = ano (u), le[++tp] = u, u = mat[u];
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie (0);
	cin >> n;
	L(i, 1, n * 2) cin >> A[i], mat[i] = ano (i);
	int l = 0, r = 20, ns = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) ns = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ns << "\n";
	L(i, 1, tp) cout << le[i] << ' ';
	return 0;
}