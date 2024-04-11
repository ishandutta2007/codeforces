#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

using namespace std;
typedef long long ll;
const int N = 1005;
const ll P = 998244353;

struct mat {
	ll a[64][64];
	mat() { mem(a, 0); }
	ll* operator [](int key) { return a[key]; }
	mat operator *(mat& b) {
		mat c;
		rep(i, 0, 63) rep(k, 0, 63) if(a[i][k]) rep(j, 0, 63) (c[i][j] += a[i][k] * b[k][j]) %= P;
		return c;
	}
} co[4], pows[31];
int n, a[N], m, ok[5][5];
ll f[N][4];
vector <pair <int, int>> v[N];
int A(int i) { return i & 3; }
int B(int i) { return i >> 2 & 3; }
int C(int i) { return i >> 4; }
int ext(int k, int i) {
	rep(j, 0, 3) if((!ok[k][3] || A(i) ^ j) && (!ok[k][2] || B(i) ^ j) && (!ok[k][1] || C(i) ^ j)) return i >> 2 | j << 4;
}
void Pow(mat& a, int n) {
	rep(k, 0, 30) if(n >> k & 1) a = a * pows[k];
}
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n;
	rep(i, 1, n) scanf("%d", &a[i]);
	cin >> m;
	int x, y, c;
	rep(i, 1, m) scanf("%d%d%d", &x, &y, &c), v[x].eb(y, c);
	rep(i, 1, 3) rep(j, 1, 3) scanf("%d", &ok[i][j]);
	rep(i, 1, n) sort(v[i].begin(), v[i].end());
	rep(i, 1, 3) rep(S, 0, 63) {
		int j = ext(i, S);
		co[i][S][j]++, pows[0][S][j]++;
	}
	rep(i, 0, 29) pows[i + 1] = pows[i] * pows[i];
	f[0][0] = 1;
	rep(i, 1, n) {
		mat nw; nw[0][63] = 1;
		int lst = 1;
		for(auto [j, c] : v[i]) Pow(nw, j - lst), nw = nw * co[c], lst = j + 1;
		Pow(nw, a[i] + 1 - lst);
		rep(j, 0, 3) rep(S, 0, 63) (f[i][j ^ C(S)] += f[i - 1][j] * nw[0][S]) %= P;
	}
	cout << f[n][0];
	return 0; 
}