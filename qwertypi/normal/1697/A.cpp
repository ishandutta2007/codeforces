#include <bits/stdc++.h>

using namespace std;

int A[100001];
void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	long long ans = max(accumulate(A, A + n, 0LL) - m, 0LL);
	cout << ans << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}