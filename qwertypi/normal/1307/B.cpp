#include <bits/stdc++.h>
 
using namespace std;
 
int A[100000];
int sub(){
	int n, x;
	cin >> n >> x;
	bool OK = false;
	for(int i = 0; i < n; i++){
		cin >> A[i];
		if(A[i] == x){
			cout << 1 << endl;
			OK = true;
		}
	}
	if(OK){
		return 0;
	}
	int _max = *max_element(A, A + n);
	int ans = max(2, (x + _max - 1) / _max);
	cout << ans << endl;
}
 
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}