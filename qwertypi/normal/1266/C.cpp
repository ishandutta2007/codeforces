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
	int n, m;
	cin >> n >> m;
	if(n * m == 1){
		cout << 0 << endl;
		return 0;
	}
	if(n == 1){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cout << (n + j) * i << ' ';
			} 
			cout << endl;
		}
	}else{
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cout << (m + i) * j << ' ';
			}
			cout << endl;
		}
	}
}