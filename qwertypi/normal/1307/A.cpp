#include <bits/stdc++.h>

using namespace std;

int A[100];
int sub(){
	int n, d;
	cin >> n >> d;
	int ans = 0;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i < n; i++){
		while(A[i] && d >= i){
			A[i]--;
			d -= i;
			ans++;
		}
	}
	cout << ans << endl;
}
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}