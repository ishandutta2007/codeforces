#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)

using namespace std;
typedef long long ll;
const ll P = 1e9 + 7;
int n, m, f[255][2][2][1 << 15]; char s[255][255];

int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> m;
	For(i, 0, n) scanf("%s", s[i]);
	if(n < m) {
		For(i, 0, n) For(j, i + 1, m) swap(s[i][j], s[j][i]);
		swap(n, m);
	}
	f[0][0][0][0] = 1;
	For(i, 0, n) For(j, 0, m) rep(a, 0, 1) rep(b, 0, 1) For(S, 0, 1 << m) {
		int x = f[i * m + j][a][b][S], nxt = i * m + j + 1;
		if(!x) continue;
		if(s[i][j] == 'x') (f[nxt][0][b][~(~S | 1 << j)] += x) %= P;
		else {
			(f[nxt][j < m - 1][b][S | 1 << j] += x) %= P;
			if(a | (S >> j & 1)) (f[nxt][a & (j < m - 1)][b][S] += x) %= P;
			else if(!b) (f[nxt][0][1][S] += x) %= P;
		}
	}
	int as = 0;
	rep(b, 0, 1) For(S, 0, 1 << m) (as += f[n * m][0][b][S]) %= P;
	cout << as;
	return 0;
}