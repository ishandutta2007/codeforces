#include <bits/stdc++.h>

using namespace std;

int A[100000], B[100000];
int sA[100001], sB[100001];
void sub(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i < n; i++){
		cin >> B[i];
	}
	sort(A, A + n);
	sort(B, B + n);
	for(int i = 0; i < n; i++){
		sA[i + 1] = sA[i] + A[i];
	}
	for(int i = 0; i < n; i++){
		sB[i + 1] = sB[i] + B[i];
	}
	
	for(int k = 0; k <= n * 2; k++){
		int chosen = (k + n) - (k + n) / 4;
		int scA = k * 100 + sA[n] - sA[min(n, n - (chosen - k))];
		int scB = sB[n] - sB[max(0, n - chosen)];
		if(scA >= scB){
			cout << k << endl;
			return;
		}
	}
}
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
	return 0;
}