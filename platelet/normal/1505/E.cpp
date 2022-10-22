#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define upd(a, b) (a = max(a, b))

using namespace std;
int n, m;
char s[9][9];
int find(int& a, int& b) {
	int mi = 1e9, x, y;
	rep(i, a, n) rep(j, b, m) if((i > a || j > b) && (s[i][j] == '*' && i + j - a - b < mi))
		mi = i + j - a - b, x = i, y = j;
	if(mi == 1e9) return 0;
	a = x, b = y;
	return 1;
}
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	cin >> n >> m;
	rep(i, 1, n) cin >> (s[i] + 1);
	int res = s[1][1] == '*', a = 1, b = 1;
	while(find(a, b)) res++;
	cout << res;
	return 0;
}