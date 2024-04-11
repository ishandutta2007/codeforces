#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	int a, b, c;

	cin >> a >> b >> c;

	if(c == 0){
		if(b == a) puts("YES");
		else puts("NO");
	}
	else{
		//if(b < a) puts("NO");
		if((b - a) % c == 0 && (b - a) / c >= 0) puts("YES");
		else puts("NO");
	}
	
	return 0;
}