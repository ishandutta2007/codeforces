#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 105;
int T, n, a, b; 
int main() {
	for(cin >> T; T--;) {
		scanf("%d", &n);
		rep(i, 1, n / 2) {
			scanf("%d%d", &a, &b);
			printf("%d %d ", b, -a);
		}
		puts("");
	}
	return 0;
}