#include <bits/stdc++.h>
 
using namespace std;
 
int A[300000];
 
void sub(){
	int n;
	cin >> n;
	for(int i = 0; i < n * 2; i++){
		cin >> A[i];
	}
	int cnt_0 = 0;
	for(int i = 0; i < n * 2; i++){
		cnt_0 += (A[i] % 2);
	}
	if(cnt_0 == n){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
}
 
int32_t main(){
	int t;
	cin >> t;
	while(t--) sub();
}