#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
typedef vector < int > vi;
typedef vector < ll > vl;
typedef vector < pii > vp;
typedef set < int > si;
typedef set < ll > sl;
typedef set < pii > sp;
typedef pair < ld, ld > pt;

const int N = 1500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int ALP = 30;
const int BASE = 31337;
const double EPS = 1e-9;
const double PI = 3.1415926535;

int a[5][N], n, m;
int dp[N][20], mx[N][20];

void calc_mx(int i){
	for(int j = 0;j < (1 << n);j++){
		mx[i][j] = 0;
		for(int sh = 0;sh < n;sh++){
			int cur = 0;
			for(int k = 0;k < n;k++)
				if(j & (1 << k)) cur += a[(sh + k) % n][i];
			mx[i][j] = max(mx[i][j], cur);
		}
		
	}
}


int f(int x,int msk){
	if(x == m) return 0;
	if(dp[x][msk] != -1) return dp[x][msk];
	int ret = f(x + 1, msk);
	for(int msk2 = 0;msk2 < (1 << n);msk2++){
		if(msk & msk2) continue;
		ret = max(ret, f(x + 1, msk | msk2) + mx[x][msk2]);
	}
	return dp[x][msk] = ret;
}

void solve(){
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &n, &m);
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			scanf("%d", &a[i][j]);
	for(int i = 0;i < m;i++) calc_mx(i);
	printf("%d\n", f(0,0));
	
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}