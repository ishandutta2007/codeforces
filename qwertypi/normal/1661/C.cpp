#include <bits/stdc++.h>
// Uncertainty principle.
// If you are persistent enough, you can build a segtree.
using namespace std;
#define int long long
// why always ka long long ...
// WTF is TLE????
// lmao Wrong every TC 2... 
int h[300001];
int dp[1 << 15];
int32_t main(){
	int t = 1;
	cin >> t;
	while(t--){
		int n; cin >> n;
		for(int i = 0; i < n; i++){
			cin >> h[i];
		}
		int ans1 = 0, ans2 = 0;
		int mx = 0; for(int i = 0; i < n; i++) mx = max(mx, h[i]);
		{
			int ttl = 0;
			int one = 0; for(int i = 0; i < n; i++) if((h[i] + mx) % 2) one++;
			for(int i = 0; i < n; i++) ttl += mx - h[i];
			ans1 = max(ans1, ttl / 3 * 2 + ttl % 3);
			ans1 = max(ans1, one * 2 - 1);
		}
		mx++;
		{
			int ttl = 0;
			int one = 0; for(int i = 0; i < n; i++) if((h[i] + mx) % 2) one++;
			for(int i = 0; i < n; i++) ttl += mx - h[i];
			ans2 = max(ans2, ttl / 3 * 2 + ttl % 3);
			ans2 = max(ans2, one * 2 - 1);
		}
		cout << min(ans1, ans2) << endl;
	}	
}