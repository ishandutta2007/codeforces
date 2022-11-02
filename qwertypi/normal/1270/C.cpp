#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[200000];
void sub(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	int XOR = 0;
	int SUM = 0;
	for(int i = 0; i < n; i++){
		XOR ^= A[i];
		SUM += A[i];
	}
	SUM += XOR;
	cout << 2 << endl;
	cout << XOR << ' ' << SUM << endl;
}
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}