#include <bits/stdc++.h>

using namespace std;

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		if(n % m == 0 || m % n == 0){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}
}