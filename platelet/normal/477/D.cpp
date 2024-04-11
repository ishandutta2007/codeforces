#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
 
using std::min;
const int N = 5005, P = 1e9 + 7;
typedef long long ll;
int n, g[N][N], z[N][N]; ll suf[N], f[N][N]; char s[N];
int cmp(int a, int b, int len) {
	return z[a][b] < len ? s[a+z[a][b]] > s[b+z[a][b]] : 0;
}
int main() {
	scanf("%s", s + 1), n = strlen(s + 1);
	rep(i, 1, n) {
		int l = 0, r = 0;
		rep(j, i + 1, n) {
			int& k = z[i][j] = j > r ? 0 : min(z[i][i+j-l], r - j + 1);
			while(s[i+k] == s[j+k]) k++;
			if(j + k >= r) l = j, r = j + k - 1;
		}
	}
	mem(g, 63), f[1][0] = 1, g[1][0] = 0;
	ll ans = 1e9, ans2 = 0, tw = 1;
	per(i, n, 1) suf[i] = (suf[i+1] + (s[i] - 48) * tw) % P, tw = tw * 2 % P;
	rep(r, 1, n) {
		int mi = 1e9;
		per(l, r, 1) {
			if(s[l] > 48) {
				int x = l - (r - l + 1);
				if(x < 1) x = 1; else x += cmp(x, l, r - l + 1);
				f[l][r] = f[x][l-1], g[l][r] = g[x][l-1] + 1;
				if(s[r+1] > 48 && (r - l + 1 < n - r || (r - l + 1 == n - r && !cmp(l, r + 1, n - r)))) {
					if(n - r < 20) ans = min(ans, g[l][r] + 1 + suf[r+1]);
					else mi = min(mi, g[l][r] + 1);
				}
			} (f[l][r] += f[l+1][r]) %= P, g[l][r] = min(g[l][r], g[l+1][r]);
		}
		if(mi < 1e9) ans2 = (mi + suf[r+1]) % P;
	}
	printf("%lld\n%lld", f[1][n], ans < 1e9 ? ans : ans2 ? ans2 : (suf[1] + 1) % P);
	return 0;
}