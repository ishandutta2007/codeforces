#include <bits/stdc++.h>

using namespace std;

int A[100000];
void sub(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	int res = 0;
	int L = (1 << 30), R = -(1 << 30);
	for(int i = 0; i < n - 1; i++){
		if(A[i] == -1 ^ A[i + 1] == -1){
			int x = max(A[i], A[i + 1]);
			L = min(L, x);
			R = max(R, x);
		}else{
			res = max(res, abs(A[i] - A[i + 1]));
		}
	}
	int m = (L + R) / 2;
	int ans = max((R - L + 1) / 2, res);
	cout << ans << ' ' << m << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}