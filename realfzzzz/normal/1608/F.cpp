#include<bits/stdc++.h>
using namespace std;

const int P = 998244353; int dp[103][2003] , tp[103][2003] , R[2003] , TR[2003] , N , K , A[2003];
int upd(int x){return x + (x >> 31 & P);} int add(int x , int y){return upd(x + y - P);} int sub(int x , int y){return upd(x - y);}

int main(){
	cin >> N >> K; for(int i = 1 ; i <= N ; ++i) cin >> A[i];
	for(int i = A[N] - K ; i <= A[N] + K ; ++i) if(i >= 0 && i <= N) dp[i + K - A[N]][1] = 1;
	A[0] = -K;
	for(int i = 1 ; i <= N ; ++i) if(A[i] - K > i || A[i - 1] - A[i] > 2 * K){cout << 0; return 0;}
	for(int i = N ; i ; --i){
		memset(tp , 0 , sizeof(tp));
		for(int j = 0 ; j <= 2 * K ; ++j)
			if(A[i] + j - K >= A[i - 1] - K && A[i] + j - K <= A[i - 1] + K){
				int pos = A[i] + j - K - A[i - 1] + K;
				for(int l = 0 ; l <= N + 1 ; ++l) if(dp[j][l]) tp[pos][l] = (tp[pos][l] + 1ll * dp[j][l] * (N + 1 - l)) % P;
			}
		memset(R , 0 , sizeof(R));
		for(int t = A[i] + K - 1 ; t >= A[i - 1] - K ; --t){
			for(int j = N + 1 ; ~j ; --j) if(R[j]) R[j + 1] = sub(R[j + 1] , R[j]);
			if(t + 1 >= A[i] - K) for(int j = 0 ; j <= N + 1 ; ++j) R[j] = add(R[j] , dp[t + 1 - A[i] + K][j]);
			if(t <= A[i - 1] + K) for(int j = 0 ; j <= N + 1 ; ++j) tp[t - A[i - 1] + K][j + 1] = add(tp[t - A[i - 1] + K][j + 1] , R[j]);
		}
		memcpy(dp , tp , sizeof(dp)); bool flg = 0;
		for(int i = 0 ; i <= 2 * K ; ++i) for(int j = 0 ; j <= N + 1 ; ++j) flg |= dp[i][j] != 0;
		if(!flg){cout << 0; return 0;}
	}
	int sum = 0; for(int i = 0 ; i <= N + 1 ; ++i) sum = (sum + dp[2 * K][i]) % P;
	cout << sum; return 0;
}
// T 