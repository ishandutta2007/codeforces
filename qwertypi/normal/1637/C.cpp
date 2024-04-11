#include <bits/stdc++.h>
#define int long long
using namespace std;

int A[100001];
void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	int o = 0;
	for(int i = 1; i < n - 1; i++) if(A[i] % 2) o++;
	int c = (accumulate(A + 1, A + n - 1, 0LL) + o + 1) / 2;
	int a0 = true, a1 = true;
	for(int i = 1; i < n - 1; i++){
		if(A[i] != 0) a0 = false;
		if(A[i] > 1) a1 = false;
	}
	if(a0){
		cout << 0 << endl;
		return;
	}
	if(a1){
		cout << -1 << endl;
		return;
	}
	if(n == 3 && A[1] % 2 == 1){
		cout << -1 << endl;
		return;
	} 
	cout << c << endl; 
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}