#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
typedef bitset <1000> bst;
int n, s, d, pop[1 << 20];
bst b0[1 << 10], b1[1 << 20];
unordered_map <bst, int> m;

int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> s >> d;
	int K = s / 3;
	int c, x;
	For(i, 0, s) {
		scanf("%d", &c);
		while(c--) scanf("%d", &x), x--, i < K ? b0[1 << i][x] = 1 : b1[1 << (i - K)][x] = 1;
	}
	For(i, 0, 1 << K) b0[i] = b0[i & (i - 1)] ^ b0[i & -i];
	For(i, 0, 1 << (s - K)) {
		b1[i] = b1[i & (i - 1)] ^ b1[i & -i];
		pop[i] = __builtin_popcount(i);
		if(m.count(b1[i])) m[b1[i]] = min(m[b1[i]], pop[i]);
		else m[b1[i]] = pop[i];
	}
	while(d--) {
		bst nw; int as = 100;
		for(scanf("%d", &c); c--; scanf("%d", &x), nw[--x] = 1);
		For(i, 0, 1 << K) if(m.count(nw ^ b0[i])) as = min(as, pop[i] + m[nw ^ b0[i]]);
		printf("%d\n", as < 100 ? as : -1);
	}
	return 0;
}