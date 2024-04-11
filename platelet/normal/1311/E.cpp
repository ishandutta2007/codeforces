#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++) 

using namespace std;
const int N = 5005;
int T, n, d, cnt[N], id[N][N]; 
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	for(cin >> T; T--;) {
		scanf("%d%d", &n, &d);
		mem(cnt, 0);
		int Min = 0, h = -1;
		while(1 << (h+2) <= n + 1) h++, Min += h * (cnt[h] = 1 << h);
		if(1 << (h+1) < n + 1) h++, Min += h * (cnt[h] = n + 1 - (1 << h));
		if(d < Min || d > n * (n - 1) / 2) { puts("NO"); continue; }
		while(d > Min) per(i, h, 0)
		if(cnt[i] > 1 && cnt[i+1] < (cnt[i] - 1) * 2) {
			cnt[i]--, cnt[i+1]++, Min++; h = max(h, i + 1); break;
		}
		puts("YES");
		int sz = id[0][0] = 1;
		For(i, 1, n) For(j, 0, cnt[i]) id[i][j] = ++sz, printf("%d ", id[i-1][j/2]);
		puts("");
	}
	return 0;
}