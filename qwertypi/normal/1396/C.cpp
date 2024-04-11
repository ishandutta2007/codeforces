#include <bits/stdc++.h>

#define int long long

using namespace std;

char const * o;
char in[1 << 26];

void load(){ o = in ;  in [ fread(in,1,sizeof(in)-4,stdin)] = 0; }

inline int Int(){
     int u = 0;
     while(*o && *o <= 32)++o;
     while(*o >='0' && *o <='9') u = (u << 3) + (u << 1) + (*o++ -'0');
     return u;
}

int A[1000001];
int P[1000001], Q[1000001];
int dp[1000001][2];
int n, r1, r2, r3, d;

#define inf (1LL << 60)
int32_t main(){
	load();
	n = Int(), r1 = Int(), r2 = Int(), r3 = Int(), d = Int();
	for(int i = 0; i < n; i++){
		A[i] = Int();
		P[i] = Q[i] = inf;
	}
	
	r1 = min(r1, r3);
	int ans = 0;
	for(int i = 0; i < n; i++){
		P[i] = r1 * A[i] + r3;
		Q[i] = min(r2 + r1, r1 * (A[i] + 2));
	}
	
	dp[1][0] = P[0], dp[1][1] = Q[0];
	
//	for(int i = 0; i < n; i++){
//		cout << P[i] << ' ' << Q[i] << endl;
//	}
	for(int i = 1; i < n - 1; i++){
		dp[i + 1][0] = min(P[i] + min(dp[i][0] + d, dp[i][1] + d * 3), Q[i] + dp[i][1] + d * 3);
		dp[i + 1][1] = min(dp[i + 1][0], Q[i] + dp[i][0] + d);
	}
	
	dp[n - 1 + 1][0] = min(P[n - 1] + min(dp[n - 1][0] + d, dp[n - 1][1] + d * 2), Q[n - 1] + dp[n - 1][1] + d * 3);
	dp[n - 1 + 1][1] = min(dp[n - 1 + 1][0], Q[n - 1] + dp[n - 1][0] + d);
		
//	for(int i = 0; i <= n; i++){
//		cout << dp[i][0] << ' ' << dp[i][1] << endl;
//	}
	cout << dp[n][0] << endl;
}