#include <bits/stdc++.h>
using namespace std;

int main () {
	int n;
	scanf ("%d", &n);
	
	int a[n];
	for (int i=0; i<n; i++) scanf ("%d", a + i);
	
	int ans = 0;
	vector <int> v;
	
	v.push_back (a[0]);
	for (int i=1; i<n; i++) {
		int gcd = __gcd (a[i], a[i-1]);
				
		if (gcd > 1) v.push_back (1);
		v.push_back (a[i]);
	}
	
	printf ("%d\n", (int) v.size() - n);
	for (int i=0; i<v.size(); i++) printf ("%d ", v[i]); printf ("\n");
	
	return 0;
}