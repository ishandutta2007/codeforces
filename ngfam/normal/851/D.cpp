#include <bits/stdc++.h>

using namespace std;

const int N = 2000010;

int n, x, y;
int prime[N];
long long sum[N];
long long cnt[N];
	long long ans = 1e18;

long long mul(long long u, long long v){
	if(v == 0){
		return 0;
	}
	if((ans + v - 1) / v < u){
		return ans + 1;
	}
	return u * v;
}

long long add(long long u, long long v){
	u += v;
	if(u > ans){
		u = ans + 1;
	}
	return u;
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d%d%d", &n, &y, &x);


	for(int i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);
		++cnt[x];
		sum[x] += x;
	}

	for(int i = 1; i < N; ++i){
		sum[i] += sum[i - 1];
		cnt[i] += cnt[i - 1];
	}

	ans = 1LL * y * (n - 1);

	if(sum[1] == n){
		cout << 1LL * min(x, y) * n;
		return 0;
	}


	int lim = y / x;

	//cout << lim << endl;

	for(int i = 2; i < N; ++i){
		if(prime[i] != 0){
			continue;
		}
		for(int j = i + i; j < N; j += i){
			prime[j] = 1;
		}

		long long result = 0;

		int Del = 0, oldlim = lim;

		for(int u = i; u < N; u += i){

			

			if(lim < i - 1){
				result = add(result, mul((cnt[u - lim - 1] - cnt[u - i]), y));
				result = add(result, mul((cnt[u - 1] - cnt[u - lim - 1]) * u - (sum[u - 1] - sum[u - lim - 1]), x));
			}
			else{
				result = add(result, mul((cnt[u - 1] - cnt[u - i]) * u - (sum[u - 1] - sum[u - i]), x));
			}
		}

		ans = min(ans, result);
	}

	cout << ans;

	return 0;
}