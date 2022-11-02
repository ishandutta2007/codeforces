#include <bits/stdc++.h>
#define int long long
using namespace std;

int A[100013];


void sub(){
	int x, y;
	cin >> x >> y;
	if(y < x){
		cout << y + x << endl;
	}else if(y == x){
		cout << y << endl;
	}else{
		cout << (y / x * x + (y - (y / x * x)) / 2) << endl;
	}
	return;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}