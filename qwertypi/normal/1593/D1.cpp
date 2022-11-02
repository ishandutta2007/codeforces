#include <bits/stdc++.h>

using namespace std;

int A[41];

void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	sort(A, A + n);
	map<int, int> M;
	for(int i = 0; i < n; i++) M[A[i]]++;
	for(auto i : M){
		if(i.second == n){
			cout << -1 << endl;
			return;
		}
	}
	int g = 0;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(A[i] != A[j]) g = __gcd(g, A[j] - A[i]);
		}
	}
	cout << abs(g) << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}