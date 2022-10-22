#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
int n, x;
long long a, b;
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	cin >> n;
	while(n--) scanf("%d", &x), a += (x + n % 2) / 2, b += (x + (n + 1) % 2) / 2;
	cout << min(a, b);
	return 0;
}