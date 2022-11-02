#include <bits/stdc++.h>
#define int long long
using namespace std;

bool A[40], B[40];
int A_sum[40], B_sum[40];
bool test(int u, int v){
	fill(A, A + 40, 0);
	fill(B, B + 40, 0); 
	fill(A_sum, A_sum + 40, 0);
	fill(B_sum, B_sum + 40, 0);
	if(u > v){
		return false;
	}
	for(int i = 0; i < 30; i++){
		A[i] = u % 2;
		u /= 2;
		A_sum[i + 1] = A_sum[i] + A[i];
	}
	for(int i = 0; i < 30; i++){
		B[i] = v % 2;
		v /= 2;
		B_sum[i + 1] = B_sum[i] + B[i];
	}
	for(int i = 0; i <= 30; i++){
		if(A_sum[i] < B_sum[i]){
			return false;
		}
	}
	return true;
}
int32_t main(){
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		int u, v;
		cin >> u >> v;
		bool ok = false;
		ok |= test(u, v);
		cout << (ok ? "YES" : "NO") << endl;
	}
}