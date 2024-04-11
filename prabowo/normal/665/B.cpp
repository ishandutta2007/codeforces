#include <cstdio>

int main () {
	int ans = 0;
	int n, m, k;
	scanf ("%d %d %d", &n, &m, &k);
	
	int pos[k];
	int what[k];
	int p;
	for (int i=0; i<k; i++) {
		scanf ("%d", &p);
		pos[--p] = i;
		what[i] = p;
	}
	
	int a;
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
		scanf ("%d", &a);
		a--;
		
		ans += pos[a];
		for (int k=pos[a]; k; k--) pos[what[k] = what[k-1]]++;
		pos[a] = 0;
		what[0] = a;
	}
	
	printf ("%d\n", ans + n * m);
	return 0;
}