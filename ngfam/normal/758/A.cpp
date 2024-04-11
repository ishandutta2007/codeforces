#include <bits/stdc++.h>

using namespace std;

int n, a[111];

long long ans;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	int values = 0;
	
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		values = max(values, a[i]);
	}	

	for(int i = 1; i <= n; ++i){
		ans += values - a[i];
	}

	cout << ans;

	return 0;
}