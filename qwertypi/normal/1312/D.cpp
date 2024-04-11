#include <bits/stdc++.h>
#define int long long
using namespace std;

int A[100];

int mod = 998244353;

int pow(int a, int b){
	int res = 1;
	while(b){
		if(b % 2){
			res *= a;
			res %= mod;
		}
		a *= a;
		a %= mod;
		b /= 2;
	}
	return res;
}

int modinv(int a){
	return pow(a, mod - 2);
}

int fact[200001];

int C(int n, int r){
	return ((fact[n] * modinv(fact[r])) % mod * modinv(fact[n - r])) % mod;
}

int32_t main(){
	fact[0] = 1;
	for(int i = 1; i <= 200000; i++){
		fact[i] = (fact[i - 1] * i) % mod;
	}
	int n, m;
	cin >> n >> m;
	int P = (C(m, n - 1) * (n - 2)) % mod;
	int Q = 0;
	for(int i = 1; i < n - 1; i++){
		int l = i - 1, r = n - 1 - i - 1;
		Q += C(n - 3, l);
		Q %= mod;
	}
	cout << (P * Q) % mod << endl;
}