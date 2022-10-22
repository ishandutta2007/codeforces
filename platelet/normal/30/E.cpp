#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 1e5 + 5;
int n, len[N], z[N*2], mxpos[N]; char s[N*2];
int ans, p, x;
void manacher(int n) {
	int p = 0, r = 0; s[0] = '#';
	rep(i, 1, n) {
		for(int& j = len[i] = r > i ? min(len[p*2-i], r - i) : 0; s[i+j+1] == s[i-j-1]; j++);
		if(i + len[i] > r) r = (p = i) + len[i];
	}
}
void exKmp(int n) {
	int zl = 0, zr = 0;
	rep(i, 2, n) if(i > zr) {
		for(int& j = z[i] = 0; s[i+j] == s[1+j]; j++);
		if(z[i]) zr = (zl = i) + z[i] - 1;
	} else if(i + z[i-zl+1] <= zr) z[i] = z[i-zl+1];
	else {
		for(int& j = z[i] = zr - i + 1; s[i+j] == s[1+j]; j++);
		zr = (zl = i) + z[i] - 1;
	}
}
int main() {
	#ifdef local
		freopen("in.txt", "r", stdin);
	#endif
	scanf("%s", s + 1), n = strlen(s + 1);
	manacher(n), memcpy(s + n + 1, s + 1, n);
	reverse(s + 1, s + n + 1), exKmp(n * 2);
	rep(i, 1, n) mxpos[i] = z[n+mxpos[i-1]] > z[i+n] ? mxpos[i-1] : i; 
	rep(i, 1, n) {
		int l = 0, r = min(n - i - len[i], i - len[i] - 1), mid;
		if(!r) {
			if(len[i] * 2 + 1 > ans) ans = len[i] * 2 + 1, p = i, x = r;
			continue;
		}
		while(l <= r) {
			mid = (l + r) >> 1;
			if(z[n+mxpos[i-len[i]-mid]] >= mid) l = mid + 1;
			else r = mid - 1;
		}
		if((r + len[i]) * 2 + 1 > ans) {
			ans = (r + len[i]) * 2 + 1;
			p = i, x = r;
		}
	}
	if(!x) printf("1\n%d %d\n", p - len[p], len[p] * 2 + 1);
	else {
		puts("3"); int l = mxpos[p-len[p]-x];
		printf("%d %d\n%d %d\n%d %d\n", l, x, p - len[p], len[p] * 2 + 1, n - x + 1, x);
	}
	return 0;
}