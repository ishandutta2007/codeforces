#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 1e5 + 5;
int n, m; char s[N];
long long ans;
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	scanf("%d%d%s", &n, &m, s + 1);
	int su = 0;
	rep(i, 1, n) {
		su += s[i - 1] != s[i];
		ans += su * (m - 1);
	}
	su = -1;
	per(i, n, 1) {
		su += s[i + 1] != s[i];
		ans += su * (m - 1);
	}
	int lst[2] = { 2, 1 };
	rep(i, 1, n) {
		if(s[lst[i & 1]] ^ s[i]) lst[i & 1] = i;
		if(s[i] ^ s[i - 1]) ans -= i - max(lst[0], lst[1]) + 1;
	}
	cout << ans;
	return 0; 
}