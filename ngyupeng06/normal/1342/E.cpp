#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<li,li> pll;
#define mp make_pair
#define pb push_back

long long n, k, mod = 998244353, ans, f[200005], fi[200005];

long long mul_inv(long long a, long long b) { 
	long long b0 = b, t, q, x0 = 0, x1 = 1; 
	if (b == 1) return 1; 
	while (a > 1) { 
		q = a / b; 
		t = b; 
		b = a % b; 
		a = t; 
		t = x0;
		x0 = x1 - q * x0; 
		x1 = t; 
	} 
	if (x1 < 0) x1 += b0; 
	return x1; 
}

li modpow(li base, li exp, li mod) { 
	li result = 1; 
	for (base %= mod; exp; exp >>= 1) { 
		if (exp & 1) result = (result * base) % mod; 
		base = (base * base) % mod; 
	} 
	return result; 
}


long long xcy(long long x, long long y){
	if (y == 0 || y==n) return 1;
	long long thing = 1;
	thing *= f[x];
	thing *= fi[y];
	thing %= mod;
	thing *= fi[x-y];
	thing %= mod;
	return thing;
}

long long pie(){
	long long sum = 0;
	long long idx;
	for (int i=0; i<n-k; i++){
		if (i%2 == 0) idx = 1;
		else idx = -1;
		sum += idx * ((xcy(n-k, i) * modpow(n-k-i, n, mod)) % mod);
		sum += mod*5;
		sum %= mod;
	}
	return sum;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	f[0] = 1;
	fi[0] = 1;
	for (int i=1; i<=n; i++){
		f[i] = f[i-1] * i;
		f[i] %= mod;
		fi[i] = mul_inv(f[i], mod);
	}
	if (k == 0){
		ans = 1;
		for (int i=1; i<=n; i++){
			ans *= i;
			ans %= mod;
		}
	}
	else if (k>=n){
		ans = 0;
	}
	else {
		ans = 2;
		ans %= mod;
		ans *= xcy(n,k);
		ans %= mod;
		ans *= pie();
		ans %= mod;
	}
	cout << ans;
}