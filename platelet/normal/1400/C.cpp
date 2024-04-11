#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
char s[100005]; int n, x, w[100005];
int main() {
	int t; cin >> t;
	while(t--) {
		scanf("%s%d", s + 1, &x), n = strlen(s + 1);
		rep(i, 1, n) w[i] = 1, s[i] -= 48;
		rep(i, 1, n) if(!s[i]) {
			if(i > x) w[i-x] = 0;
			if(i <= n - x) w[i+x] = 0;
		}
		rep(i, 1, n) if(s[i] && (i <= x || !w[i-x]) && (i > n - x || !w[i+x])) goto loop;
		rep(i, 1, n) putchar(w[i] + 48);
		putchar(10); continue;
		loop: puts("-1");
	}
	return 0;
}