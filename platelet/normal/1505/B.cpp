#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)

using namespace std;
int a;
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	cin >> a;
	while(a >= 10) {
		int t = 0;
		while(a) t += a % 10, a /= 10;
		a = t;
	}
	cout << a;
	return 0;
}