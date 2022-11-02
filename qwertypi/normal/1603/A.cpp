#include <bits/stdc++.h>

using namespace std;

int A[100013];


void sub(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i < n; i++){
		bool OK = false;
		for(int j = 2; j <= i + 2; j++){
			if(A[i] % j != 0){
				OK = true;
				break;
			}
		} 
		if(!OK){
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	return;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}