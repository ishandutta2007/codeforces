#include <bits/stdc++.h>

#define int long long
using namespace std;

int A[100000];
map<int, int> B;
int diff[99999];
int L[100000];
int R[100000];
int32_t main(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> A[i];
		B[A[i]]++;
	}
	sort(A, A+n);
	for(int i = 0; i < n - 1; i++){
		diff[i] = A[i+1] - A[i];
	}
	int L = 0;
	int R = 0;
	int ans = 0;
	while(k && A[L] != A[n - R - 1]){
		int L_per_move = L + B[A[L]];
		int R_per_move = R + B[A[n - 1 - R]];
		if(L_per_move < R_per_move){
			if(k >= L_per_move * diff[L + B[A[L]] - 1]){
				ans += diff[L + B[A[L]] - 1];
				k -= L_per_move * diff[L + B[A[L]] - 1];
			}else{
				ans += k / L_per_move;
				break;
			}
			L += B[A[L]];
		}else{
			if(k >= R_per_move * diff[n - 1 - R - B[A[n - 1 - R]]]){
				ans += diff[n - 1 - R - B[A[n - 1 - R]]];
				k -= R_per_move * diff[n - 1 - R - B[A[n - 1 - R]]];
			}else{
				ans += k / R_per_move;
				break;
			}
			R += B[A[n - 1 - R]];
		}
	}
	cout << A[n-1] - A[0] - ans;
}