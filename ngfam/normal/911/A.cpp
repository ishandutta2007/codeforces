#include <bits/stdc++.h>

using namespace std;

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	int val = 1e9 + 1;

	int n;

	int last = - 1;

	int ans = 1e9;

	scanf("%d", &n);

	for(int i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);

		if(x < val){
			last = i;
			val = x;
			ans = 1e9;
			continue;
		}
		else{
			if(x == val) {
				ans = min(ans, i - last);
				last = i;
			}
		}
	}

	cout << ans;

	return 0;
}