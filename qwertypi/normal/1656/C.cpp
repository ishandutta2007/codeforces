#include <bits/stdc++.h>

using namespace std;

int A[100001];
void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> A[i];
	sort(A, A + n);
	bool one = false, zero = false;
	for(int i = 0; i < n; i++) if(A[i] == 1) one = true;
	for(int i = 0; i < n; i++) if(A[i] == 0) zero = true;
	if(one && zero){
		cout << "NO" << endl;
		return;
	}else if(!one){
		cout << "YES" << endl;
		return;
	}else{
		for(int i = 0; i < n - 1; i++){
			if(A[i] + 1 == A[i + 1]){
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--) solve();
}