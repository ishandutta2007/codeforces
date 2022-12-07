#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

long long Qpow(long long x, long long y){
	x %= mod;
	long long ret = 1;

	for(int i = 60; i >= 0; --i){
		ret = (ret * ret) % mod;
		if(y & (1LL << i)) ret = (ret * x) % mod;
	}

	return ret;
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	long long n, m, k;
	cin >> n >> m >> k;
	
	if(k == -1 && n % 2 != m % 2) cout << 0;
  else
	cout << Qpow(Qpow(2, n - 1), m - 1);

	return 0;
}