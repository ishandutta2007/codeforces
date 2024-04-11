#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("0.inp", "r", stdin);
		freopen("0.out", "w", stdout);	
	#endif

	int x1, x2, x3;
	scanf("%d%d%d", &x1, &x2, &x3);

	int ans = 300;
	
	for(int i = 1; i <= 100; ++i){
		ans = min(ans, abs(i - x1) + abs(i - x2) + abs(i - x3));
	}
	printf("%d", ans);
}