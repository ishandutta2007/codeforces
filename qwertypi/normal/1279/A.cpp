#include <bits/stdc++.h>

using namespace std;
void sub(){
	int A[3];
	for(int i = 0; i < 3; i++){
		cin >> A[i];
	}
	sort(A, A + 3);
	if(A[2] > A[0] + A[1] + 1){
		cout << "No" << endl;
	}else{
		cout << "Yes" << endl;
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		sub(); 
	} 
}