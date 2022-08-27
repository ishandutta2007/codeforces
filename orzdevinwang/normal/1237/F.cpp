#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 3607, mod = 998244353;
bool vis1[N], vis2[N];
int n, m, k, f[N][N], cnt1, cnt2;
int A[N], B[N], fac[N], ifac[N], inv[N], ans;
void init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (ll) inv[mod % i] * (mod - mod / i) % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
}
int C(int x, int y) {
	if(y < 0 || x < y) return 0;
	return (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k, init(max(n, m));
	L(i, 1, k) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2, vis1[x1] = vis1[x2] = vis2[y1] = vis2[y2] = true;
	}
	vis1[0] = vis2[0] = true;
	L(i, 1, n) cnt1 += ! vis1[i];
	L(i, 1, m) cnt2 += ! vis2[i];
	f[0][0] = 1;
	L(i, 1, n) {
		L(j, 0, i) f[i][j] = f[i - 1][j];
		if(!vis1[i] && !vis1[i - 1]) L(j, 1, i) (f[i][j] += f[i - 2][j - 1]) %= mod;	
	}
	L(i, 0, cnt1) A[i] = f[n][i];
	memset(f, 0, sizeof(f));
	f[0][0] = 1;
	L(i, 1, m) {
		L(j, 0, i) f[i][j] = f[i - 1][j];
		if(!vis2[i] && !vis2[i - 1]) L(j, 1, i) (f[i][j] += f[i - 2][j - 1]) %= mod;	
	}
	L(i, 0, cnt2) B[i] = f[m][i];
	L(i, 0, cnt1) L(j, 0, cnt2) (ans += (ll) C(cnt1 - i * 2, j) * C(cnt2 - j * 2, i) % mod * fac[i] % mod * fac[j] % mod * A[i] % mod * B[j] % mod) %= mod;
	cout << ans << "\n";
	return 0;
}