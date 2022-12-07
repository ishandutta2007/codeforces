#include <bits/stdc++.h>

using namespace std;

const int N = 2020;

int n;
int a[N];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	cin >> n;
	int x = 1, cnt = 0;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		x = max(x, a[i]);
		if(a[i] == 1) ++cnt;
	}

	if(cnt > 0){
		cout << n - cnt;
		return 0;
	}

	if(x == 1){
		cout << 0;
		return 0;
	}

	int ans = 1e9;

	for(int i = 1; i <= n; ++i){
		int x = a[i], len = -1;
		for(int j = i; j >= 1; --j){
			x = __gcd(x, a[j]);
			++len;
			if(x == 1) break;
		}
		if(x == 1) ans = min(ans, len + n - 1);
	}

	if(ans == 1e9) ans = -1;
	cout << ans;

	return 0;
}