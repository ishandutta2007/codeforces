#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
int n, a[N], qz[N], g[N], p, k, x, y;
void Brute() {
	int ans = 1e9;
	L(i, 1, n) L(l, 0, i - 1) L(r, i + 1, n) if((qz[i] ^ qz[l]) > (qz[i] ^ qz[r])) ans = min(ans, r - l - 2);
	if(ans > 1e8) printf("-1\n");
	else printf("%d\n", ans);
}
int main() {
	scanf("%d", &n);
	L(i, 1, n) scanf("%d", &a[i]), g[i] = log2(a[i]), qz[i] = (qz[i - 1] ^ a[i]);
	L(i, 1, n - 2) if(g[i] == g[i + 1] && g[i + 1] == g[i + 2]) {
		printf("1\n");
		return 0;
	}
	Brute();
	return 0;
}