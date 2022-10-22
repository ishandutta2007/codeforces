#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define N 1000005
using namespace std;

int T, n, m, A[N], ta, tb, a[N], b[N];
void ins(int* a, int& tp, int x) {
	auto it = lower_bound(a, a + tp, x);
	if(it == a + tp) tp++;
	*it = x;
}
int main() {
	for(cin >> T; T--;) {
		scanf("%d%d", &n, &m), ta = tb = 0;
		rep(i, 1, n) rep(j, 1, m) scanf("%1d", &A[i * m + j - m]);
		rep(s, 2, n + m) rep(i, max(s - m, 1), min(n, s - 1))
		if(int j = s - i; A[i * m + j - m]) s & 1 ? ins(a, ta, j - i) : ins(b, tb, j - i);
		printf("%d\n", ta + tb);
	}
}