#include <bits/stdc++.h>

using namespace std;

const int N = 400;

int n;
int a[N];
int f[N];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}



	int ans = 360;
	for(int i = 1; i <= n; ++i){
		int tot = 0;
		for(int j = i; j <= n; ++j){
			tot += a[j];
			ans = min(ans, abs(tot + tot - 360));
		}
	}

	cout << ans;

	return 0;
}