#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

int a[N], q, n;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
	}

	sort(a + 1, a + n + 1);

	scanf("%d", &q);
	for(int i = 1; i <= q; ++i){
		int val; scanf("%d", &val);
		int fin = upper_bound(a + 1, a + n + 1, val) - a - 1;
		printf("%d\n", fin);
	}

	return 0;
}