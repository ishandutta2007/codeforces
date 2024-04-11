#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++)
#define R(i, j, k) for(int i = j; i >= k; i--)
#define ll long long
using namespace std;
const int N = 1e4;
int T, n, m, a[N][3][3];
int main() {
	scanf("%d", &T);
	while(T--) {
		int fga = 0, fgb = 0;
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) {
			L(ta, 1, 2) L(tb, 1, 2) scanf("%d", &a[i][ta][tb]);
			fga |= (a[i][1][2] == a[i][2][1]);
		}
		L(i, 1, n) L(j, 1, n) fgb |= (a[i][1][1] == a[j][1][1] && a[i][2][2] == a[j][2][2] && a[i][1][2] == a[j][2][1] && a[i][2][1] == a[j][1][2]);
		if(m % 2 || !fga || !fgb) {
			printf("NO\n");
			continue;
		}
		else printf("YES\n");
	}
	return 0;
}