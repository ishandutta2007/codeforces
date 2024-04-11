#include <bits/stdc++.h>

// Pls don't give me expert
// Back to the origin in 2019...

using namespace std;

int A[1 << 17];
int dp[17];
int dp2[17];
bool ex[1 << 17];
int ans[17];
int l, r;
	
bool test(int x){
	for(int i = l; i <= r; i++){
		if(l > (A[i] ^ x) || r < (A[i] ^ x)) return false;
	}
	cout << x << endl;
	for(int i = l; i <= r; i++){
		ex[A[i]] = false;
	}
	return true;
}

void solve(){
	fill(dp, dp + 17, 0);
	cin >> l >> r;
	for(int i = l; i <= r; i++){
		cin >> A[i];
		ex[A[i]] = true;
	}
	
	for(int j = 0; j < 17; j++){
		vector<int> lonely; // :(
		for(int i = l; i <= r; i++){
			if(!ex[A[i] ^ (1 << j)]){
				lonely.push_back(A[i] >> j);
			}
		}
		// assert(lonely.size() <= 2);
		if(lonely.size() == 0) continue;
		if(test((lonely[0] << j) ^ l)) return;
		if(test((lonely[0] << j) ^ r)) return;
	}
	for(int i = l; i <= r; i++){
		ex[A[i]] = false;
	}
	cout << 0 << endl;
}

int main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}