#include <bits/stdc++.h>
 
#define int long long
using namespace std;
 
int A[100000];
int _left[100001];
int32_t main(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < k; i++){
		cin >> A[i];
	}
	for(int i = 0; i < k; i++){
		if(i + 1 > n - A[i] + 1){
			cout << -1 << endl;
			return 0;
		}
	}
	for(int i = k - 1; i >= 0; i--){
		_left[i] = _left[i + 1] + A[i];
	}
	if(accumulate(A, A + k, 0LL) < n){
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < k; i++){
		cout << max(i + 1, n - _left[i] + 1) << ' ';
	}
}