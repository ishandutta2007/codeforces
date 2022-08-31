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
		scanf("%d", &n);
		int m = sqrt(n);
		printf("%d\n", m + ((n + m - 1) / m) - 2);
	}
	return 0;
}