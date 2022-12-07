#include <bits/stdc++.h>

using namespace std;

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	int n;
	scanf("%d", &n);

	int ans = 25;
	int sub = 0;

	for(int i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);
		if(x > 25){
			ans = max(ans, x);
			++sub;
		}
	}

	cout << (ans - 25);

	return 0;
}