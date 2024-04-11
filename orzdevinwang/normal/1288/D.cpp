#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e5 + 7;
int n, m, a[N][20], pp, maxn[512], mi[512], pi, pj;
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < (1 << m); i++) maxn[i] = -1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
		for(int j = 0; j < (1 << m); j++) {
			pp = 1e9 + 7;
			for(int k = 1; k <= m; k++) 
				if(j & (1 << (k - 1))) pp = min(a[i][k], pp);
			if(pp > maxn[j]) maxn[j] = pp, mi[j] = i;
		}
	}
	int Ans = -1;
	for(int i = 0; i < (1 << m); i++) {
		pp = min(maxn[i], maxn[(1 << m) - 1 - i]);
		if(pp > Ans) Ans = pp, pi = mi[i], pj = mi[(1 << m) - 1 - i];
	}
	printf("%d %d\n", pi, pj);
	return 0;
}