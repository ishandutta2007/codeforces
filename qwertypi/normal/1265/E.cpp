#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int p[200001];
 
constexpr int mod = 998244353;
int bp(int a, int b){
	if(b == 0) return 1;
	return bp(a * a % mod, b / 2) * (b % 2 ? a : 1) % mod;
}
 
int mi(int a){
	return bp(a, mod - 2);
}
 
int E[200001];
int32_t main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> p[i];
	}
	int i100 = mi(100);
	for(int i = 0; i < n; i++){
		p[i] = (p[i] * i100) % mod;
	}
	E[0] = 0;
	for(int i = 0; i < n; i++){
		E[i + 1] = mi(p[i]) % mod * (E[i] + 1) % mod; 
		E[i + 1] = (E[i + 1] % mod + mod) % mod;
	}
	/*
	for(int i = 0; i <= n; i++){
		cout << E[i] << ' ';
	} 
	cout << endl;
	*/
	cout << E[n] << endl;
}