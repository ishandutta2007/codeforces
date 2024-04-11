#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define upd(a, b) (a = max(a, b))

using namespace std;
int a;
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	cin >> a;
	cout << 2 - a * a;
	return 0;
}