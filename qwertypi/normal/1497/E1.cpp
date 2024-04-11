#include <bits/stdc++.h>

using namespace std;

int lp[10000001];

int A[200001];
int dp[200001][21];
int l[200001][21];

struct Counter{
	int cnt[10000001] = {0};
	int ans = 0;
	void add(int x){
		cnt[x]++;
		if(cnt[x] >= 2) ans++;
	}
	
	void erase(int x){
		cnt[x]--;
		if(cnt[x] >= 1) ans--;
	}
} counter;

void solve(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		A[i] = 1;
		while(v != 1){
			(A[i] % lp[v] == 0) ? A[i] /= lp[v] : A[i] *= lp[v];
			v /= lp[v];
		}
	}
	for(int a = 1; a <= 21; a++){
		int L = 0, R = -1;
		for(int i = 0; i < n; i++){
			while(R < i) counter.add(A[++R]);
			while(counter.ans >= a && L <= R) counter.erase(A[L++]);
			l[i][a - 1] = L;
		}
		while(L <= R) counter.erase(A[L++]);
	}
	
	for(int i = 0; i <= k; i++) for(int j = 0; j <= n; j++) dp[i][j] = (1 << 30);
	for(int i = 0; i <= k; i++) dp[i][0] = 0;
	for(int i = 0; i <= k; i++){
		for(int j = 0; j < n; j++){
			if(i > 0) dp[i][j + 1] = dp[i - 1][j + 1];
			for(int d = 0; d <= i; d++){
				dp[i][j + 1] = min(dp[i][j + 1], dp[i - d][l[j][d]] + 1);
			}
		}
	}
	cout << dp[k][n] << endl;
}

int main(){
	for(int i = 2; i <= 10000000; i++){
		if(lp[i] == 0){
			lp[i] = i;
			for(int j = i * 2; j <= 10000000; j += i){
				if(!lp[j]) lp[j] = i;
			}
		}
	}
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}