#include <bits/stdc++.h>
#define int long long
using namespace std;

int A[300000], B[300000];
void sub(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i < n; i++){
		cin >> B[i];
	}
	sort(A, A + n);
	sort(B, B + n);
	for(int i = 0; i < n; i++){
		cout << A[i] << ' ';
	}
	cout << endl;
	for(int i = 0; i < n; i++){
		cout << B[i] << ' ';
	}
	cout << endl;
}
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}