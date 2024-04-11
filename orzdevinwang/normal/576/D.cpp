#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db long double
#define pii pair<int, int>
#define mkp make_pair
#define putsl puts("")
using namespace std;
const int N = 155;
int n, m, ans = 2e9;
int dp[2][N], s[N], ss[N];
struct edge {
	int from, to, val;
} e[N];
struct Matrix {
	bitset<N> f[N];  
} now;
Matrix operator * (Matrix aa, Matrix bb) {
	bitset<N> sav[N]; Matrix res; L(i, 1, n) res.f[i].reset();
	L(i, 1, n) L(j, 1, n) sav[i][j] = bb.f[j][i];
	L(i, 1, n) L(j, 1, n) res.f[i][j] = !!(aa.f[i] & sav[j]).count();
	return res;
}
Matrix operator ^ (Matrix aa, int bb) {
	Matrix res; L(i, 1, n) res.f[i].reset(), res.f[i].set(i);
	for(; bb; aa = aa * aa, bb >>= 1) if(bb & 1) res = res * aa;
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	L(i, 1, m) cin >> e[i].from >> e[i].to >> e[i].val;
	sort(e + 1, e + m + 1, [&](edge aa, edge bb) { return aa.val < bb.val; });
	s[1] = 1;
	if(e[1].val != 0) return puts("Impossible"), 0;
	L(i, 1, m) {
		now.f[e[i].from].set(e[i].to);
		memset(dp, 0, sizeof(dp));
		L(j, 1, n) dp[0][j] = s[j];
		int nw = 0;
		L(k, 1, n) {
			nw ^= 1;
			memset(dp[nw], 0, sizeof(dp[nw]));
			L(j, 1, i) dp[nw][e[j].to] |= dp[nw ^ 1][e[j].from];
			if(dp[nw][n]) ans = min(ans, e[i].val + k); //, cout << "qwq\n";
		}
		if(i < m) {
			Matrix res = now ^ (e[i + 1].val - e[i].val);
			L(j, 1, n) ss[j] = s[j], s[j] = 0;
			// cout << endl;
			// L(j, 1, n) L(k, 1, n) cout <<res.f[j][k] << " \n"[k == n];
			// cout << endl;
			L(j, 1, n) L(k, 1, n) if(res.f[j][k]) s[k] |= ss[j];
		}
		// L(j, 1, n) cout << s[j] << " ";
		// cout << endl;
	}
	if(ans == 2e9) cout << "Impossible\n";
	else cout << ans << endl;
	return 0;
}