#include <bits/stdc++.h>
using namespace std;

int main () {
	int n, m;
	scanf ("%d %d", &n, &m);
	stack <int> s[n][2];
	
	for (int i=0; i<m; i++) s[(i % (n << 1)) >> 1][i & 1].push (i);
	
	for (int i=0; i<n; i++) for (int j=0; j<2; j++) while (s[i][j].size()) printf ("%d ", s[i][j].top() + 1), s[i][j].pop(); printf ("\n");
	
	return 0;
}