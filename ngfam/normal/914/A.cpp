#include <bits/stdc++.h>

using namespace std;

int n;
int a[10001];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	cin >> n;
	int ans = -1e9;

	for(int i = 1; i <= n; ++i){
		int x;
		cin >> x;

		if(x < 0) {
			ans = max(ans, x);
			continue;
		}

		int j = 0;
		while(j * j < x) ++j;
		if(j * j != x) ans = max(ans, x);
	}

	cout << ans;


	return 0;
}