// 
// 

#include <bits/stdc++.h>
#define int long long
#define inf (1LL << 60)

using namespace std;

const int mod = 1e9 + 7;

int A[300001];
void solve(){
	int n;
	cin >> n;
	if(n == 4){
		cout << 1 << ' ' << 1 << ' ' << 1 << ' ' << 1 << endl;
		return;
	}else if(n == 5){
		cout << "1 2 1 1" << endl;
		return;
	}else if(n == 6){
		cout << 1 << ' ' << 3 << ' ' << 1 << ' ' << 1 << endl;
		return;
	}
	if(n % 2){
		cout << 2 << ' ' << n - 5 << ' ' << 2 << ' ' << 1 << endl; 
	}else{
		cout << 2 << ' ' << n - 6 << ' ' << 2 << ' ' << 2 << endl; 
	}
}

int32_t main(){
	int t; cin >> t;
	while(t--) solve();
}