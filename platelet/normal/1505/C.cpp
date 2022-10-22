#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)

using namespace std;
char s[20];
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	cin >> s;
	int n = strlen(s);
	For(i, 2, n) if(s[i] - 'A' != (s[i - 1] + s[i - 2] + 'A' * 2) % 26) puts("NO"), exit(0);
	puts("YES");
	return 0;
}