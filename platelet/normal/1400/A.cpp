#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;

int main() {
	int t, n; char s[105];
	for(cin >> t; t--;) {
		scanf("%d%s", &n, s + 1);
		rep(i, 1, n) putchar(s[i*2-1]);
		putchar(10); 
	}
	return 0;
}