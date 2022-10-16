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

const int N = 2050;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int ALP = 30;
const int BASE = 31337;
const double EPS = 1e-9;
const double PI = 3.1415926535;

int a[20][N], n, m;
int dp[20][5000], mx[20][5000], naj[N], P[N];

bool cmp(int i,int j){
	return naj[i] > naj[j];
}

void calc_mx(int i, int ii){
	for(int j = 0;j < (1 << n);j++){
		mx[ii][j] = 0;
		for(int sh = 0;sh < n;sh++){
			int cur = 0;
			for(int k = 0;k < n;k++)
				if(j & (1 << k)) cur += a[(sh + k) % n][i];
			mx[ii][j] = max(mx[ii][j], cur);
		}
		
	}
}


int f(int x,int msk){
	if(x == m || x == 12) return 0;
	if(dp[x][msk] != -1) return dp[x][msk];
	int ret = f(x + 1, msk);
	int nmsk = (1 << n) - 1 - msk;
	for(int msk2 = nmsk;msk2 > 0;msk2 = (msk2 - 1) & nmsk){
		ret = max(ret, f(x + 1, msk | msk2) + mx[x][msk2]);
	}
	return dp[x][msk] = ret;
}

void solve(){
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &n, &m);
	for(int i = 0;i < m;i++) P[i] = i, naj[i] = 0;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			scanf("%d", &a[i][j]), naj[j] = max(naj[j], a[i][j]);
	sort(P, P + m, cmp);
	for(int i = 0;i < m && i < 12;i++) calc_mx(P[i], i);
	printf("%d\n", f(0,0));
	
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}