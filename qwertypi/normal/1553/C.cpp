#include <bits/stdc++.h>
 
#define int long long
using namespace std;
 
int powmod(int a, int b, int p){
	int res = 1;
	while(b){
		if(b % 2){
			res = (res * a) % p;
		}
		b /= 2;
		a = (a * a) % p;
	}
	return res;
}

bool A[10];
void sub(){
	string s;
	cin >> s;
	int d;
	fill(A, A + 10, 0);
	int ans = 10;
	for(int i = 0; i < 10; i++){
		A[i] = s[i] == '1';
		if(i % 2){
			A[i] |= s[i] == '?';
		}
	}
	
	d = 0;
	for(int i = 0; i < 10; i++){
		if(i % 2){
			if(A[i]) d++;
		}else{
			if(A[i]) d--;
		}
		
		if(d > (10 - i - 1) / 2 || d < -(10 - i) / 2){
			ans = min(ans, i + 1);
			break;
		}
	}
	 
	fill(A, A + 10, 0);
	for(int i = 0; i < 10; i++){
		A[i] = s[i] == '1';
		if(i % 2 == 0){
			A[i] |= s[i] == '?';
		}
	}
	
	d = 0;
	for(int i = 0; i < 10; i++){
		if(i % 2){
			if(A[i]) d++;
		}else{
			if(A[i]) d--;
		}
		
		if(d > (10 - i - 1) / 2 || d < -(10 - i) / 2){
			ans = min(ans, i + 1);
			break;
		}
	}
	cout << ans << endl;
}


int32_t main(){
	int J;
	cin >> J;
	while(J--){
		sub();
	}
}