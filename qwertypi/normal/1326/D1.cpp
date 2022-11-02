#include <bits/stdc++.h>
 
using namespace std;
 
string s;
 
int isPal[5001][5001];
 
void f(int n){
	int L = 0, R = n - 1;
	while(s[L] == s[R] && L < R){
		L++, R--;
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			isPal[i][j] = 1;
		}
	}
	for(int d = 1; d < n; d++){
		for(int i = 0; i < n - d; i++){
			isPal[i][i + d] = isPal[i + 1][i + d - 1] && (s[i] == s[i + d]);
		}
	}
	
	if(L > R){
		cout << s << endl;
		return;
	}
	
	int fL, fR;
	for(int i = L; i <= R; i++){
		if(isPal[L][i]){
			fL = i + 1;
		}
	}
	for(int i = R; i >= L; i--){
		if(isPal[i][R]){
			fR = i - 1;
		}
	}
	
	if(fL - L > R - fR){
		for(int i = 0; i < fL; i++){
			cout << s[i];
		}
		
		for(int i = R + 1; i < n; i++){
			cout << s[i];
		}
		
	}else{
 
		for(int i = 0; i < L; i++){
			cout << s[i];
		}
		
		for(int i = fR + 1; i < n; i++){
			cout << s[i];
		}
		
	}
	cout << endl;
}
 
int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> s;
		f(s.size());
	}
}