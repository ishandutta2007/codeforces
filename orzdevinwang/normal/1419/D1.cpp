#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = j; i <= k; i++)
#define R(i, j, k) for(int i = j; i >= k; i--) 
using namespace std;
const int N = 1e5 + 7;
int T, n, v, a[N];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	printf("%d\n", (n - 1) / 2);
	for(int i = 1; i <= n / 2; i++) printf("%d %d ", a[i + n / 2], a[i]);
	if(n & 1) printf("%d\n", a[n]);
	return 0;
}