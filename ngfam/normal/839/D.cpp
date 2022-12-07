#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;
const int mod = 1e9 + 7;

int n;
int pw[N];
int cnt[N];
int ways[N];

int mul(int u, int v){
	return (1LL * u * v) % mod;
}

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
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
	#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int val;
		scanf("%d", &val);
		++cnt[val];
	}
	pw[0] = 1;
	for(int i = 1; i <= n; ++i){
		pw[i] = add(pw[i - 1], pw[i - 1]);
	}
	int ans = 0;
	for(int i = N - 1; i > 1; --i){
		int sum = 0;
		for(int j = i; j < N; j += i){
			sum += cnt[j];
		}
		if(sum == 0){
			continue;
		}
		ways[i] = mul(pw[sum - 1], sum);
		for(int j = i + i; j < N; j += i){
			ways[i] = sub(ways[i], ways[j]);
		}
		ans = add(ans, mul(i, ways[i]));
	}
	cout << ans;
	return 0;
}