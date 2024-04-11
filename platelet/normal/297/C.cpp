#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 1e5 + 5;

int n, a[N], ord[N], b[N];
int main() {
#ifdef local
	freopen(".in", "r", stdin);
#endif
	cin >> n;
	int m = (n + 2) / 3;
	For(i, 0, n) scanf("%d", &a[i]), ord[i] = i;
	sort(ord, ord + n, [](int x, int y) {
		return a[x] < a[y];
	});
	For(i, 0, m) b[ord[i]] = i;
	For(i, m * 2, n) b[ord[i]] = a[ord[i]] - (n - i - 1);
	puts("YES");
	For(i, 0, n) printf("%d ", b[i]);
	puts("");
	For(i, 0, n) printf("%d ", a[i] - b[i]);
	return 0;
}