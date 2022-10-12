#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int n;
int a[N];

int main () {
	scanf ("%d", &n);
	for (int i=0; i<n; i++) scanf ("%d", a + i);
	
	sort (a, a + n);
	
	for (int i=0; i<n; i++) {
		if (i & 1) printf ("%d ", a[(i >> 1) + (n + 1 >> 1)]);
		else printf ("%d ", a[i >> 1]);
	}
	printf ("\n");
	
	return 0;
}