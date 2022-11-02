#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int A[300001], B[300001];
int32_t main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i < n; i++){
		cin >> B[i];
	}
	for(int i = 0; i < n; i++){
		A[i] -= B[i];
	}
	sort(A, A + n);
	int ans = 0;
	for(int i = 0; i < n; i++){
		int idx = upper_bound(A, A + n, -A[i]) - A;
		ans += max(0LL, n - max(i + 1, idx));
	}
	cout << endl;
	cout << ans << endl;
}