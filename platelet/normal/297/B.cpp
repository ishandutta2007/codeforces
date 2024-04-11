#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 1e5 + 5;

int n, m, K, a[N], b[N], c[N * 2], s[N * 4];
int main() {
	cin >> n >> m >> K;
	rep(i, 1, n) scanf("%d", &a[i]), c[i] = a[i];
	rep(i, 1, m) scanf("%d", &b[i]), c[i + n] = b[i];
	sort(c + 1, c + n + m + 1);
	rep(i, 1, n) s[lower_bound(c + 1, c + n + m + 1, a[i]) - c]++;
	rep(i, 1, m) s[lower_bound(c + 1, c + n + m + 1, b[i]) - c]--;
	per(i, n + m, 1) if((s[i] += s[i + 1]) > 0) puts("YES"), exit(0);
	puts("NO");
	return 0;
}