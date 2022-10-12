#include <cstdio>
#include <algorithm>

int main () {
	int n, m;
	scanf ("%d %d", &n, &m);
	
	n *= 2;
	m *= 3;
	
	int now = 6;
	while (now <= n && now <= m) {
		if (n + 2 < m + 3) n += 2;
		else m += 3;
		
		now += 6;
	}
	
	printf ("%d\n", std :: max(n, m));
	
	return 0;
}