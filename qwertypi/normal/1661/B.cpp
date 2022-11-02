#include <bits/stdc++.h>
// Uncertainty principle.
// If you are persistent enough, you can build a segtree.
using namespace std;
#define int long long
// why always ka long long ...
// WTF is TLE????
int A[32768], B[26];
int dp[1 << 15];
int32_t main(){
	int t = 1;
	// cin >> t;
	while(t--){
		int n; cin >> n;
		for(int i = 0; i < n; i++){
			cin >> A[i];
		}
		deque<int> dq;
		dq.push_back(32767);
		dq.push_back(16384);
		dp[0] = 1;
		for(int i = 1; i < 32768; i++) dp[i] = (1 << 30);
		while(dq.size()){
			int e = dq.front(); dq.pop_front();
			if(dp[e] != (1 << 30)) continue;
			dp[e] = min(dp[e], dp[(e + 1) % 32768] + 1);
			dp[e] = min(dp[e], dp[(e * 2) % 32768] + 1);
			if(e % 2 == 0)  dq.push_back((e / 2) % 32768);
			if(e % 2 == 0)  dq.push_back((e / 2) % 32768 + 16384);
			dq.push_back((e + 32767) % 32768);
		}
		for(int i = 0; i < n; i++){
			cout << dp[A[i]] - 1 << ' ';
		}
		cout << endl;
	}	
}