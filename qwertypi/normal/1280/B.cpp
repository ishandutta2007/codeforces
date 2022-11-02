#include <bits/stdc++.h>
using namespace std;

char A[60][60];
void sub(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	bool OK = false;
	bool T = true;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			OK |= A[i][j] == 'A';
			T &= A[i][j] == 'A';
		}
	}
	if(!OK){
		cout << "MORTAL" << endl;
		return;
	}
	bool corner = (A[0][0] == 'A') || (A[n - 1][m - 1] == 'A') || (A[0][m - 1] == 'A') || (A[n - 1][0] == 'A');
	bool line = false;
	bool side = false;
	bool mid_line = false; 
	bool test;
	test = 1;
	for(int i = 0; i < n; i++){
		bool test = 1;
		for(int j = 0; j < m; j++){
			test &= A[i][j] == 'A';
		}
		mid_line |= test;
	}

	for(int i = 0; i < m; i++){
		bool test = 1;
		for(int j = 0; j < n; j++){
			test &= A[j][i] == 'A';
		}
		mid_line |= test;
	}
	
	for(int i = 0; i < n; i++){
		test &= A[i][0] == 'A';
		side |= A[i][0] == 'A';
	}
	line |= test;
	test = 1;
	for(int i = 0; i < n; i++){
		test &= A[i][m - 1] == 'A';
		side |= A[i][m - 1] == 'A';
	}
	line |= test;
	test = 1;
	for(int i = 0; i < m; i++){
		test &= A[0][i] == 'A';
		side |= A[0][i] == 'A';
	}
	line |= test;
	test = 1;
	for(int i = 0; i < m; i++){
		test &= A[n - 1][i] == 'A';
		side |= A[n - 1][i] == 'A';
	}
	line |= test;
	if(T){
		cout << 0 << endl;
	}else if(line){
		cout << 1 << endl;
	}else if(corner || mid_line){
		cout << 2 << endl;
	}else if(side){
		cout << 3 << endl;
	}else{
		cout << 4 << endl;
	}
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}