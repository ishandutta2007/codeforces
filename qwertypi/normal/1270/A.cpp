#include <bits/stdc++.h>

using namespace std;

void sub(){
	int n, k1, k2;
	cin >> n >> k1 >> k2;
	for(int i = 0; i < k1; i++){
		int v;
		cin >> v;
		if(v == n){
			cout << "YES" << endl;
		}
	}
	for(int i = 0; i < k2; i++){
		int v;
		cin >> v;
		if(v == n){
			cout << "NO" << endl;
		}
	}
}
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}