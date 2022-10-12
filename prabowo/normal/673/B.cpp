#include <cstdio>
#include <algorithm>

int main () {
	int n, m;
	scanf ("%d %d", &n, &m);
	
	int mini = 1;
	int maxi = n;
	
	int u, v;
	while (m--) {
		scanf ("%d %d", &u, &v);
		if (v < u) std::swap(u, v);
		
		mini = std::max(mini, u);
		maxi = std::min(maxi, v);
	}
	
	printf ("%d\n", std::max(0, maxi - mini));
	
	return 0;
}