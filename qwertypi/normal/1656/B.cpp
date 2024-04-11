#include <bits/stdc++.h>
#define int long long
using namespace std;

int A[300001];
void solve(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> A[i];
	sort(A, A + n);
	set<int> S;
	for(int i = 0; i < n; i++) S.insert(A[i]);
	for(int i = 0; i < n; i++){
		if(S.find(A[i] + k) != S.end()){
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--) solve();
}