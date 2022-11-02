#include <bits/stdc++.h>
#define int long long
using namespace std;

void sub(int n){
	if(n >= 14 && 1 <= n % 14 && n % 14 <= 6){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}

int32_t main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int k;
		cin >> k;
		sub(k);
	}
}