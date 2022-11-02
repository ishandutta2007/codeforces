#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[101];
int mex[101][101];
void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int c0 = 0, c1 = 0;
	for(int i = 0; i < n; i++){
		c0 += a[i] % 2 == 0;
		c1 += a[i] % 2 != 0;
	}
	if(c1 % 4 == 0 || c1 % 4 == 3 || c1 % 4 == 1 && c0 % 2 == 1){
		cout << "Alice" << endl;
	}else{
		cout << "Bob" << endl;
	}
}

int32_t main(){
	for(int i = 0; i <= 100; i++){
		for(int j = 0; j <= 100; j++){
			
		}
	}
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}