#include <bits/stdc++.h>

#define int long long
using namespace std;

bool A[1000][1000], B[1000][1000];
void sub(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			char v;
			cin >> v;
			A[i][j] = v - '0';
		} 
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			char v;
			cin >> v;
			B[i][j] = v - '0';
		} 
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			A[i][j] ^= B[i][j];
		} 
	}
	
	for(int i = 0; i < n; i++){
		if(A[i][0] == 0){
			for(int j = 0; j < n; j++){
				A[i][j] ^= 1;
			}
		}
	}
	for(int i = 0; i < n; i++){
		if(A[0][i] == 0){
			for(int j = 0; j < n; j++){
				A[j][i] ^= 1;
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(A[i][j] == 0){
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}