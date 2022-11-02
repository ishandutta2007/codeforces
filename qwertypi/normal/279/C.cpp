#include <bits/stdc++.h>

using namespace std;

int A[200001];
int RM[200001], LM[200001];

int32_t main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	LM[0] = 0;
	for(int i = 1; i < n; i++){
		if(A[i] <= A[i - 1]){
			LM[i] = LM[i - 1];
		}else{
			LM[i] = i;
		}
	}
	RM[n - 1] = n - 1;
	for(int i = n - 2; i >= 0; i--){
		if(A[i] <= A[i + 1]){
			RM[i] = RM[i + 1];
		}else{
			RM[i] = i;
		}
	}
	for(int i = 0; i < m; i++){
		int l, r;
		cin >> l >> r;
		l--, r--;
		cout << (RM[l] >= LM[r] ? "Yes" : "No") << endl;
	} 
}