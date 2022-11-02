#include <bits/stdc++.h>
// Uncertainty principle.
// If you are persistent enough, you can build a segtree.
using namespace std;
#define int long long
int A[26], B[26];
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		for(int i = 0; i < n; i++){
			cin >> A[i];
		}
		for(int i = 0; i < n; i++){
			cin >> B[i];
		}
		for(int i = 1; i < n; i++){
			if(abs(A[i] - A[i - 1]) + abs(B[i] - B[i - 1]) <= abs(A[i] - B[i - 1]) + abs(B[i] - A[i - 1])){
				;
			}else{
				swap(B[i], A[i]);
			}
		}
		int ans = 0;
		for(int i = 0; i < n - 1; i++){
			ans += abs(A[i] - A[i + 1]) + abs(B[i] - B[i + 1]);
		}
		cout << ans << endl;
	}	
}