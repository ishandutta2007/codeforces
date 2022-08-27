#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define putsl puts("")
using namespace std;
const int N = 1e3 + 7;
int n, m, q, lg2[N], Pow[12];
short a[N][N], dp[N][N], mx[N][N][10][10];
int getmax(int l1, int r1, int l2, int r2) {
	int p1 = lg2[r1 - l1 + 1], p2 = lg2[r2 - l2 + 1], s1 = r1 - (1 << p1) + 1, s2 = r2 - (1 << p2) + 1;
	return max(max(mx[l1][l2][p1][p2], mx[s1][l2][p1][p2]), max(mx[l1][s2][p1][p2], mx[s1][s2][p1][p2]));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	L(i, 0, 10) Pow[i] = (1 << i);
	L(i, 1, 9) L(j, Pow[i], min(Pow[i + 1] - 1, 1000)) lg2[j] = i;
	cin >> n >> m;
	L(i, 1, n) L(j, 1, m) cin >> a[i][j];
	L(i, 1, n) L(j, 1, m) if(a[i][j]) dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
	L(i, 1, n) L(j, 1, m) mx[i][j][0][0] = dp[i][j];
	L(a, 0, 9) {
		if(a) L(i, 1, n - Pow[a] + 1) L(j, 1, m) 
			mx[i][j][a][0] = max(mx[i][j][a - 1][0], mx[i + Pow[a - 1]][j][a - 1][0]);
		L(b, 1, 9) L(i, 1, n - Pow[a] + 1) L(j, 1, m - Pow[b] + 1) 
			mx[i][j][a][b] = max(mx[i][j][a][b - 1], mx[i][j + Pow[b - 1]][a][b - 1]);
	}
	cin >> q;
	while(q--) {
		int l1, r1, l2, r2;
		cin >> l1 >> l2 >> r1 >> r2;
		int l = 1, r = min(r1 - l1 + 1, r2 - l2 + 1), ans = 0;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(getmax(l1 + mid - 1, r1, l2 + mid - 1, r2) >= mid) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}