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
	
	int cnt[3] = {0, 0, 0};
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cnt[(i + j) % 3] += A[i][j] == 'X'; 
		}
	}
	
	if(cnt[0] <= cnt[1] && cnt[0] <= cnt[2]){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if((i + j) % 3 == 0 && A[i][j] == 'X'){
					A[i][j] = 'O';
				}
			}
		}
	}else if(cnt[1] <= cnt[2]){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if((i + j) % 3 == 1 && A[i][j] == 'X'){
					A[i][j] = 'O';
				}
			}
		}
	}else{
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if((i + j) % 3 == 2 && A[i][j] == 'X'){
					A[i][j] = 'O';
				}
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