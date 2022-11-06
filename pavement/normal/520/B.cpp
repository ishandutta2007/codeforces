#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, p = 0;
	scanf("%d %d", &n, &m);
	while (n < m) {
		if (m % 2) m++;
		else m /= 2;
		p++;
	}
	printf("%d", p + n - m);
}