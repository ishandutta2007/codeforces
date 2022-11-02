#include <bits/stdc++.h>

using namespace std;
int B[40001];
int A[40001];
void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> B[i];
	}
	long long s = accumulate(B, B + n, 0LL);
	if(s % (n * (n + 1) / 2) != 0){
		cout << "NO" << endl;
		return;
	}
	s /= n * (n + 1) / 2;
	for(int i = 0; i < n; i++){
		int v = (B[i] - B[(i + 1) % n]) + s;
		if(v % n != 0){
			cout << "NO" << endl;
			return;
		}
		A[(i + 1) % n] = v /= n;
	}
	for(int i = 0; i < n; i++){
		if(A[i] <= 0 || A[i] >= 1e9 + 1){
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	for(int i = 0; i < n; i++){
		cout << A[i] << ' ';
	}
	cout << endl;
}

int main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}