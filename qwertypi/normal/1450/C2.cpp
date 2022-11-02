#include <bits/stdc++.h>

#define int long long
using namespace std;

char A[300][300];

void sub(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	int cnt_X[3] = {0, 0, 0}, cnt_O[3] = {0, 0, 0};
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cnt_X[(i + j) % 3] += A[i][j] == 'X'; 
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cnt_O[(i + j) % 3] += A[i][j] == 'O'; 
		}
	}
	
	int ri = -1, rj = -1, cost = (1 << 30);
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(i != j){
				if(cnt_X[i] + cnt_O[j] < cost){
					cost = cnt_X[i] + cnt_O[j];
					ri = i, rj = j;
				}
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if((i + j) % 3 == ri && A[i][j] != '.'){
				A[i][j] = 'O';
			}
			if((i + j) % 3 == rj && A[i][j] != '.'){
				A[i][j] = 'X';
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << A[i][j];
		}
		cout << endl;
	}
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}