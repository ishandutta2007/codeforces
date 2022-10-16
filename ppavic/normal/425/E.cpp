#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 505;
const int MOD = 1e9 + 7;

int pot2[N * N], dp[N][N];
int n, k;

inline int add(int A, int B){
	if(A + B >= MOD)
		return A + B - MOD;
	return A + B;
}

inline int sub(int A, int B){
	if(A - B < 0)
		return A - B + MOD;
	return A - B;
}

inline int mul(int A, int B){
	return (ll)A * B % MOD;
}

int f(int lst, int kol){
	if(kol >= k) return (kol == k);
	if(dp[lst][kol] != -1) return dp[lst][kol];
	int ret = 0;
	for(int nxt = lst + 1;nxt <= n;nxt++){
		ret = add(ret, mul(f(nxt, kol + 1), mul(pot2[nxt - lst] - 1, pot2[(nxt - lst) * (n - nxt)])));
	}
	return dp[lst][kol] = ret;
}

int main(){
	memset(dp, -1, sizeof(dp));
	pot2[0] = 1;
	for(int i = 1;i < N * N;i++) pot2[i] = mul(2, pot2[i - 1]);
	scanf("%d%d", &n, &k);
	printf("%d\n", f(0, 0));
	return 0;
}