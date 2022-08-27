#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e3 + 7;
int n, a[N], tot, g[N], ansa, sum;
int main() {
	scanf("%d", &n);
	while(n--) {
		int k; scanf("%d", &k);
		L(i, 1, k) scanf("%d", &a[i]), sum += a[i];
		L(i, 1, k / 2) ansa += a[i];
		if(k % 2 == 1) g[++tot] = a[k / 2 + 1];
	}
	sort(g + 1, g + tot + 1), reverse(g + 1, g + tot + 1);
	L(i, 1, (tot + 1) / 2) ansa += g[i * 2 - 1];
	printf("%d %d\n", ansa, sum - ansa);
	return 0;
}