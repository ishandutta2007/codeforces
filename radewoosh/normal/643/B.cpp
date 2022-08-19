#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, k, a, b, c, d;
	scanf("%d%d%d%d%d%d", &n, &k, &a, &b, &c, &d);
	if(k <= n || n <= 4) {
		puts("-1");
		return 0;
	}
	for(int rep = 0; rep < 2; ++rep) {
		printf("%d %d ", a, c);
		for(int i = 1; i <= n; ++i)
			if(i != a && i != b && i != c && i != d)
				printf("%d ", i);
		printf("%d %d\n", d, b);
		swap(a, c);
		swap(b, d);
	}
	return 0;
}