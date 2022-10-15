#include <bits/stdc++.h>
using namespace std;
const int maxn=505;
 
int n, a[maxn], d[maxn][maxn];
 
void read() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
}
 
void solve() {
	for (int len = 1; len <= n; len++) {
		for (int beg = 0, end = len - 1; end < n; beg++, end++) {
			if (len == 1) {
				d[beg][end] = 1;
			} else {
				d[beg][end] = 1 + d[beg + 1][end];
				if (a[beg] == a[beg + 1]) {
					d[beg][end] = min(1 + d[beg + 2][end], d[beg][end]);
				}
				for (int match = beg + 2; match <= end; match++) {
					if (a[beg] == a[match]) {
						d[beg][end] = min(d[beg + 1][match - 1] + d[match + 1][end], d[beg][end]);
					}
				}
			}
		}
	}
}
 
int main() {
	read();
	solve();
	printf("%d\n", d[0][n-1]);
	return 0;
}