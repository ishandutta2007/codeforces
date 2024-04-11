#include <bits/stdc++.h>

using namespace std;

bool sel[1000001];
int lp[1000001];
const int N = 1000000;
int dp[N + 1];
int dpp[N + 1];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	for(int i = 2; i <= N; i++){
		if(lp[i]) continue; lp[i] = i;
		for(int j = i; j <= N; j += i){
			if(!lp[j]) lp[j] = i;
		}
	}
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int v; cin >> v;
		sel[v] = true;
	}
	for(int i = 1; i <= N; i++){
		for(int j = i; j <= N; j += i){
			if(sel[j]) dp[i]++;
		}
	}
	
	fill(dpp, dpp + N + 1, 0);
	int ans = 0;
	for(int i = N; i >= 1; i--){
		int v = i;
		if(dpp[i] != dp[i] && dp[i] > 0) ans++;
		while(v != 1){
			int pr = lp[v];
			dpp[i / pr] = max(dpp[i / pr], dp[i]);
			v /= lp[v];
		}
	}
	cout << ans - n << endl;
}