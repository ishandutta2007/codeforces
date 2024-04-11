#include <bits/stdc++.h>

using namespace std;
int A[200000];
void sub(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i < n - 1; i++){
		if(abs(A[i] - A[i + 1]) >= 2){
			cout << "YES" << endl;
			cout << i + 1 << ' ' << i + 2 << endl;
			return;
		}
	}
	cout << "NO" << endl;
}
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}