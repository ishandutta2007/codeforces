#include <bits/stdc++.h>
 
using namespace std;
 
int A[300001];
void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	if(n == 1){
		cout << 0 << endl;
		return;
	}
	int ans = n;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			int res = 0;
			for(int k = 0; k < n; k++){
				if(A[j] * (k - i) + A[i] * (j - k) != A[k] * (j - i)){
					res++;
				}
			}
			ans = min(ans, res);
		}
	}
	cout << ans << endl;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		solve();
	}
}