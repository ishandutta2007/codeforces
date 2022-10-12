#include <bits/stdc++.h>
using namespace std;

const int N = 300000;

int n, k;
int a[N], pre[N];

int main () {
	scanf ("%d %d", &n, &k);
	for (int i=0; i<n; i++) {
		scanf ("%d", a + i);
		pre[i] = pre[i-1] + (a[i] == 0);
	}
	
	int ans = 0;
	int idx = 0;
	for (int i=0; i<n; i++) {		
		int tmp = upper_bound (pre + i, pre + n, pre[i - 1] + k) - pre - i;		
		if (ans < tmp) {
			ans = tmp;
			idx = i;			
		}
	}
	
	printf ("%d\n", ans);
	int i = idx;
	while (i < n && k) {
		if (a[i] == 0) {
			a[i] = 1;
			k--;
		}
		
		i++;
	}
	
	for (int i=0; i<n; i++) printf ("%d ", a[i]); printf ("\n");
	
	return 0;
}