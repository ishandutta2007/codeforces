#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, a[N];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
	}

	for(int i = 1; i <= n / 2; ++i){
		if(i % 2 == 1){
			swap(a[i], a[n - i + 1]);
		}
	}

	for(int i = 1; i <= n; ++i){
		printf("%d ", a[i]);
	}

	return 0;
}