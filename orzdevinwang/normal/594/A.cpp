#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2e5 + 7;
const int inf = 1e9 + 7;
int n, a[N], ans = inf;
int main() {
	scanf("%d", &n);
	L(i, 1, n) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	L(i, 1, n / 2) ans = min(ans, a[i + n / 2] - a[i]);
	printf("%d\n", ans);
	return 0;
}