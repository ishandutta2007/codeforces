#include <bits/stdc++.h>

using namespace std;

int A[500];
int B[500][500]; 
int32_t main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	for(int i = 0; i < n; i++){
		int x = i, y = i;
		for(int j = 0; j < A[i]; j++){
			B[x][y] = A[i];
			if(y == 0 || B[x][y - 1] != 0){
				x++;
			}else{
				y--;
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			cout << B[i][j] << ' ';
		}
		cout << endl;
	}
}