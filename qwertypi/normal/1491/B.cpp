#include <bits/stdc++.h>
#define int long long
using namespace std;

int A[200001];

void sub(){
	int n, u, v;
	cin >> n >> u >> v;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	int diff = 0;
	for(int i = 0; i < n - 1; i++){
		diff = max(diff, abs(A[i] - A[i + 1]));
	}
	
	if(diff == 0){
		cout << min(u + v, v * 2) << endl;
	}else if(diff == 1){
		cout << min(u, v) << endl;
	}else{
		cout << 0 << endl; 
	}
}
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}