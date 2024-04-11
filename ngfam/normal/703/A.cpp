#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	int one = 0, two = 0, n;
	scanf("%d", &n);
	
	for(int i = 1; i <= n; ++i){
		int u, v;
		scanf("%d%d", &u, &v);

		if(u > v) ++one;
		if(v > u) ++two;
	}

	if( one > two ) puts("Mishka");
	if(two > one) puts("Chris");
	if(two == one) puts("Friendship is magic!^^");

	return 0;
}