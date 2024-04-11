#include <bits/stdc++.h>

using namespace std;

int A[200001];

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	while(n > 1 && A[n - 1] == 0) n--;
	long long s = 0;
	for(int i = 0; i < n; i++){
		s += A[i];
		if(i != n - 1 && s <= 0){
			cout << "NO" << endl;
			return;
		}
		if(i == n - 1 && s != 0){
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}
int main(){
	int t;
	cin >> t;
	for(int tc = 0; tc < t; tc++){
		solve();
	}
}