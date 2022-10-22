#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 1e5 + 6;
int n, st[17][N], cnt, a[N*20];
int main() {
	cin >> n;
	rep(i, 1, n) scanf("%d", &st[0][i]);
	rep(i, 1, 16) rep(j, 1, n - (1 << i) + 1) st[i][j] = st[i-1][j] | st[i-1][j+(1<<(i-1))];
	rep(i, 1, n)
	for(int j = i - 1, nw = st[0][i]; j < n; a[++cnt] = nw, nw |= st[0][j+1])
	per(k, 16, 0) if(j + (1 << k) <= n && (nw | st[k][j+1]) == nw) j += 1 << k;
	sort(a + 1, a + cnt + 1);
	cout << unique(a + 1, a + cnt + 1) - a - 1;
	return 0;
}