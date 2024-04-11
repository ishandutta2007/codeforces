#include<bits/stdc++.h>
using namespace std;
int n, m, a, b, used[111];
int print(int x, int y) {
	printf("%d %d\n", x, y);
	for(int i = 1; i <= m; i++) if(i != y) printf("%d %d\n", x, i);
	return y == m ? m - 1 : m;
}
int main() {
	scanf("%d%d%d%d", &n, &m, &a, &b);
	b = print(a, b);
	for(int i = 1; i <= n; i++) {
		if(i == a) continue;
		b = print(i, b);
	}
}