#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int n , m;
char a[200010], b[200010];
int x[200010], y[200010];

int main() {
	scanf("%d%d", &n, &m);
	scanf("%s%s", a + 1, b + 1);
	for(int i = 1; i <= m; i++) {
		int s = x[i - 1] + 1;
		for(; s <= n; s++)
			if(a[s] == b[i])
				break;
		x[i] = s;
	}
	y[m + 1] = n + 1;
	for(int i = m; i >= 1; i--) {
		int s = y[i + 1] - 1;
		for(; s; s--)
			if(a[s] == b[i])
				break;
		y[i] = s; 
	}
	int A = 0;
	for(int i = 1; i < m; i++)
		A = max(A, y[i + 1] - x[i]);
	printf("%d\n", A);
	return 0;
}