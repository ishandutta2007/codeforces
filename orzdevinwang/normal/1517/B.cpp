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
const int N = 207, M = 1e6 + 7, z = 2050;
int n, m, a[N][N], b[N][N], tot;
struct piii {
	int x, y, v;
} s[M];
void rmain() {
	ll ns = 0;
	tot = 0;
	cin >> n >> m;
	L(i, 1, n) L(j, 1, m) b[i][j] = 0;
	L(i, 1, n) L(j, 1, m) cin >> a[i][j], ++tot, s[tot].x = i, s[tot].y = j, s[tot].v = a[i][j];
	sort(s + 1, s + tot + 1, [&] (piii a, piii b) {
		return a.v < b.v;
	});
	L(i, 1, m) 
		b[s[i].x][i] = s[i].v, ns += s[i].v;
	L(i, m + 1, tot) {
		L(j, 1, m) if(!b[s[i].x][j]) {
			b[s[i].x][j] = s[i].v;
			break;
		}
	} 
	L(i, 1, n) {
		L(j, 1, m) cout << b[i][j] << " ";
		cout << "\n";
	} 
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) rmain();
	return 0;
}