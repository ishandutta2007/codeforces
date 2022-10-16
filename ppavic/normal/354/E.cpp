#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 55;

int dp[N][N], rekA[N][N], rekB[N][N], A[N];
ll rek[N], pot[N], sol[N];

int f(int i, int ost){
	if(i == -1) return (ost == 0);
	ost = 10 * ost + A[i];
	if(ost < 0 || ost > 50) return 0;
	if(dp[i][ost] != -1) return dp[i][ost];
	for(int a = 0;a <= 6;a++){
		for(int b = 0;a + b <= 6;b++){
			if(f(i - 1, ost - 4 * a - 7 * b)){
				rekA[i][ost] = a,
				rekB[i][ost] = b;
				return dp[i][ost] = 1;
			}
		}
	}
	return dp[i][ost] = 0;
}

void solve(){
	ll x; scanf("%lld", &x);
	for(int i = 0;i < 19;i++){
		A[i] = (int)(x % 10LL);
		x /= 10LL;
	}
	memset(dp, -1, sizeof(dp));
	bool ans = f(18, 0);
	if(!ans) {
		printf("-1\n");
		return;
	}
	int cur = 0;
	for(int i = 18;i >= 0;i--){
		cur = 10 * cur + A[i];
		int a = rekA[i][cur], b = rekB[i][cur];
		cur -= 4 * a + 7 * b;
		for(int j = 0;j < a;j++)
			sol[j] += 4 * pot[i];
		for(int j = a;j < a + b;j++)
			sol[j] += 7 * pot[i];
	}
	for(int i = 0;i < 6;i++){
		printf("%lld ", sol[i]);
		sol[i] = 0;
	}
	printf("\n");
}

int main(){
	pot[0] = 1;
	for(int i = 1;i < 20;i++)
		pot[i] = 10LL * pot[i - 1];
	int T; scanf("%d", &T);
	for(;T--;) solve();
}