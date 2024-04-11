#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)

using namespace std;
const int N = 18;
typedef long long ll;
int K, t, C[N][N], T[N];
ll f[N];
int Len() {
	f[0] = 1;
	rep(i, 0, 15) per(j, 16, 1) rep(k, 1, min(j, t)) f[j] += f[j - k] * C[j][k];
	rep(i, 1, 16) if(K > f[i] * 15 / 16) K -= f[i] * 15 / 16; else return i;
}
void calc(int n, int m) {
	mem(f, 0), f[0] = 1;
	rep(i, 0, 15) if(i ^ m) per(j, n, 1) rep(k, 1, min(j, t - T[i])) f[j] += f[j - k] * C[j][k];
}
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	rep(i, 0, 16) {
		C[i][0] = 1;
		rep(j, 1, i) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	}
	cin >> K >> t;
	int l = Len();
	per(i, l, 1) rep(j, i == l, 15) {
		ll as = 0;
		calc(i, j);
		rep(k, 1, min(i, t - T[j])) as += f[i - k] * C[i - 1][k - 1];
		if(K > as) K -= as;
		else { putchar(j < 10 ? j + 48 : j + 87), T[j]++; break; }
	}
	return 0;
}