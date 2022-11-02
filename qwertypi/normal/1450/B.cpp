#include <bits/stdc++.h>

#define int long long
using namespace std;

int A[100][2];
bool OK[100][100];
int d(int i, int j){
	return abs(A[i][0] - A[j][0]) + abs(A[i][1] - A[j][1]);
}

void sub(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> A[i][0] >> A[i][1];
	}
	
	for(int i = 0; i < n; i++){
		bool OK = true;
		for(int j = 0; j < n; j++){
			if(d(i, j) > k){
				OK = false;
			}
		}
		if(OK){
			cout << 1 << endl;
			return;
		}
	}
	cout << -1 << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}