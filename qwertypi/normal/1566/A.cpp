#include <bits/stdc++.h>

using namespace std;

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n, s;
		cin >> n >> s;	
		cout << ((s) / (n - ((n + 1) / 2 - 1))) << endl;
	}
}