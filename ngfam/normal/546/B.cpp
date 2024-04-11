#include <bits/stdc++.h>

using namespace std;

const int N = 3333;

int a[N], n;

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

	int s = 0;

	for(int i = 2; i <= n; ++i){
		if(a[i] <= a[i - 1]){
			s += a[i - 1] + 1 - a[i];
			a[i] = a[i - 1] + 1;
		}
	}

	cout << s;

	return 0;
}