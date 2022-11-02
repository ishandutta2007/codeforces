#include <bits/stdc++.h>

using namespace std;

int A[300001];
int s[300001];
int Is[300001];
void solve(){
	int n, q;
	cin >> n >> q;
	string S;
	cin >> S;
	for(int i = 0; i < n; i++){
		A[i] = (S[i] == '+' ? 1 : -1);
	}
	for(int i = 0; i < n; i++){
		s[i + 1] = s[i] + A[i];
		Is[i + 1] = Is[i] + (i % 2 ? -1 : 1) * A[i];
	}
	for(int i = 0; i < q; i++){
		int l, r;
		cin >> l >> r;
		if((Is[r] - Is[l - 1]) == 0){
			cout << 0 << endl;
			continue;
		}
		if((Is[r] - Is[l - 1]) % 2 == 1 || (Is[r] - Is[l - 1]) % 2 == -1){
			cout << 1 << endl;
		}else{
			cout << 2 << endl;
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--) solve();
}