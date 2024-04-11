#include <bits/stdc++.h>

using namespace std;

int A[100001];
void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> A[i];
	cout << (min_element(A, A + n) - A) + 1 << ' ' << (max_element(A, A + n) - A) + 1 << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--) solve();
}