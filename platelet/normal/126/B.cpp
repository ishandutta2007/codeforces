#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 1e6 + 5;
char s[N]; int n, z[N], mx, zl, zr, ans, p;
int main() {
	#ifdef local
		freopen("in.txt", "r", stdin);
	#endif
	scanf("%s", s + 1), n = strlen(s + 1);
	rep(i, 2, n) {
		if(i > zr) {
			for(int& j = z[i]; s[i+j] == s[1+j]; j++);
			if(z[i]) zr = (zl = i) + z[i] - 1;
		} else if(i + z[i-zl+1] <= zr) z[i] = z[i-zl+1];
		else {
			for(int& j = z[i] = zr - i + 1; s[i+j] == s[1+j]; j++);
			zr = (zl = i) + z[i] - 1;
		}
		if(i + z[i] - 1 == n && mx >= z[i]) {
			ans = z[i], p = i; break;
		}
		mx = max(mx, z[i]);
	}
	if(ans) while(ans--) putchar(s[p++]);
	else puts("Just a legend");
	return 0;
}