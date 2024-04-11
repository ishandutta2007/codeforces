#include <bits/stdc++.h>

#define int long long
using namespace std;

int n, k;
int A[1000];

void sub(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	cout << 3 * n << endl;
	for(int i = 1; i < n; i += 2){
		cout << 1 << ' ' << i << ' ' << i + 1 << endl;
		cout << 2 << ' ' << i << ' ' << i + 1 << endl;
		cout << 1 << ' ' << i << ' ' << i + 1 << endl;
		cout << 1 << ' ' << i << ' ' << i + 1 << endl;
		cout << 2 << ' ' << i << ' ' << i + 1 << endl;
		cout << 1 << ' ' << i << ' ' << i + 1 << endl;
	}
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}