#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;

const int N = 405;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

inline int add(int A, int B) { if(A + B >= MOD) return A + B - MOD; return A + B; }
inline int sub(int A, int B) { if(A - B < 0) return A - B + MOD; return A - B; }
inline int mul(int A, int B) { return (ll)A * B % MOD; }

inline int pot(int A, int B){
	int ret = 1, bs = A;
	for(; B ; B >>= 1){
		if(B & 1) ret = mul(ret, bs);
		bs = mul(bs, bs);
	}
	return ret;
}

int dis[N][N], dp[N], inv[N], par[N], mor[N];
int vec[N][N];
int n, m;
vector < int > v[N], rek[N];

void floyd(){
	for(int k = 1;k <= n;k++)
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

int izracunaj(int x, int y){	
	if(vec[y][x] != -1) return vec[y][x];
	memset(mor, 0, sizeof(mor));
	int sol = 1;
	for(int i = 0;i <= n;i++) rek[i].clear();
	for(int i = 1;i <= n;i++){
		par[i] = 0;
		if(i == x) continue;
		rek[dis[x][i]].PB(i);
		if(i == y) continue;
		for(int j : v[i])
			if(dis[x][j] < dis[x][i] && dis[y][j] < dis[y][i])
				par[i]++;
		if(par[i])
			sol = mul(sol, par[i]);
		else{
			if(mor[dis[x][i]] || dis[x][i] + dis[i][y] != dis[x][y])
				return 0;
			else
				mor[dis[x][i]] = i;
		}
	//	if(x == 5 && y == 6) printf("\n par[ %d ] = %d\n", i, par[i]);
	}
	dp[x] = 1;
	for(int i = 1;i <= n;i++){
		if(!mor[i]){
			for(int j : rek[i]){
				dp[j] = 0;
				for(int k : v[j])
					if(dis[x][k] < dis[x][j] && dis[y][k] > dis[y][j])
						dp[j] = add(dp[j], dp[k]);
				if(j != y) dp[j] = mul(dp[j], inv[par[j]]);
			}
		}
		else{
			int j = mor[i];
			dp[j] = 0;
			for(int k : v[j])
				if(dis[x][k] < dis[x][j] && dis[y][k] > dis[y][j])
					dp[j] = add(dp[j], dp[k]);
			if(j != y) dp[j] = mul(dp[j], inv[par[j]]);
		}
	}
	return vec[x][y] = mul(sol, dp[y]);
}

int main(){
	memset(vec, -1, sizeof(vec));
	memset(dis, INF, sizeof(dis));
	for(int i = 0;i < N;i++) dis[i][i] = 0;
	inv[0] = 1;
	for(int i = 1;i < N;i++) inv[i] = pot(i, MOD - 2);
	scanf("%d%d", &n, &m);
	for(int i = 0;i < m;i++){
		int x, y; scanf("%d%d", &x, &y);
		dis[x][y] = 1, dis[y][x] = 1;
		v[x].PB(y), v[y].PB(x);
	}
	floyd();
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++)
			printf("%d ", izracunaj(i, j));
		printf("\n");
	}
	return 0;
}