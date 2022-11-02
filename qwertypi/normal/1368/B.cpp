#include <bits/stdc++.h>
 #define int long long // so dumb
using namespace std;
 
int A[10];
string s = "codeforces";
int f(void){
	int x = 1;
	for(int i = 0; i < 10; i++){
		x *= A[i];
	}
	return x;
}
 
void sub(){
	int k;
	cin >> k; 
	for(int i = 0; i < 10; i++){
		A[i] = 1;
	}
	
	for(int t = 0;; t++){
		if(f() >= k){
			for(int i = 0; i < 10; i++){
				for(int j = 0; j < A[i]; j++){
					cout << s[i];
				}
			}
			exit(0);
		}
		A[t % 10]++;
	}
}
 
int32_t main(){
	int t = 1;
	while(t--){
		sub();
	}
}