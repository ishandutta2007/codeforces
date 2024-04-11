#include <bits/stdc++.h>
#define int long long
using namespace std;

int XOR(int a, int b, int k){
	// cout << "XOR: " << a << ' ' << b << ' ';
	int A[30] = {0}, B[30] = {0}, R[30] = {0};
	int da = 0, db = 0;
	while(a){
		A[da++] = a % k; a /= k;
	}
	while(b){
		B[db++] = b % k; b /= k;
	}
	for(int i = 0; i < max(da, db); i++){
		R[i] = (A[i] + B[i]) % k;
	}
	int res = 0;
	for(int i = max(da, db) - 1; i >= 0; i--){
		res = (res * k + R[i]);
	}
	// cout << res << endl;
	return res;
}

int INV(int a, int k){
	// cout << "INV: " << a << ' ';
	int A[30] = {0}, R[30] = {0};
	int da = 0;
	while(a){
		A[da++] = a % k; a /= k;
	}
	for(int i = 0; i < da; i++){
		R[i] = (k - A[i]) % k;
	}
	int res = 0;
	for(int i = da - 1; i >= 0; i--){
		res = (res * k + R[i]);
	}
	// cout << res << endl;
	return res;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int cur_xor = 0;
		for(int i = 0; i < n; i++){
			cout << XOR(cur_xor, (i % 2 ? INV(i, k) : i), k) << endl;
			int r; cin >> r; if(r) break;
			cur_xor = XOR(INV(cur_xor, k), XOR(cur_xor, (i % 2 ? INV(i, k) : i), k), k);
		}
	}
}