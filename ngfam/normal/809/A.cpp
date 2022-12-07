#include <bits/stdc++.h>

using namespace std;

const int N = 300050;
const int mod = 1e9 + 7;

int n;
int a[N];

int add(int u, int v){
	u += v;
	if(u >= mod){
		u -= mod;
	}
	return u;
}

int sub(int u, int v){
	u -= v;
	if(u < 0){
		u += mod;
	}
	return u;
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d", &n);

	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
	}

	sort(a + 1, a + n + 1);

	int sum = 0, ans = 0, current = 0, pw2 = 1;

	for(int i = 1; i <= n; ++i){
		sum = add(sum, a[i - 1]);
		ans = add(ans, 1LL * a[i] * current % mod);
		ans = sub(ans, sum);

		current = add(current, pw2);
		pw2 = add(pw2, pw2);

		sum = add(sum, sum);
	}

	cout << ans;

	return 0;
}