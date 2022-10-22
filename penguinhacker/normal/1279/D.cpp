#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

const int MOD = 998244353;

int add(int a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
	return a;
}

int mul(int a, int b) {
	return a * 1ll * b % MOD;
}

int binpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

int n, num[1000001], numP[1000000];
vector<int> child[1000000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for (int i=0; i<1000001; ++i)
		num[i] = 0;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> numP[i];
		for (int j=0; j<numP[i]; ++j) {
			int b;
			cin >> b;
			num[b]++;
			child[i].push_back(b);
		}
	}
	
	int stuff = binpow(mul(n,n), MOD-2);
	
	long long ans = 0;
	for (int i=0; i<n; ++i) {
		long long count = 0;
		for (int x : child[i]) { 
			count += num[x];
		}
		count = mul(count, binpow(numP[i], MOD-2));
		count = mul(count, stuff);
		ans = add(ans, count);
	}

	cout << ans << '\n';
	return 0;
}