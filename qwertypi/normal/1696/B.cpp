#include <bits/stdc++.h>
 
using namespace std;
 
int A[100001];
void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> A[i];
	int p = 0, ans = 0;
	for(int i = 0; i < n; i++){
		if(A[i] != 0){
			ans += p == 0;
		}
		p = A[i];
	}
	cout << min(ans, 2) << endl;
}
 
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}