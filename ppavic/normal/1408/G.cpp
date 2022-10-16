#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef pii pt;
typedef vector < int > vi;
typedef vector < ll > vl;

const int N = 1550;
const int M = 1e6 + 500;
const int LOG = 20;
const int OFF = (1 << LOG);
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

inline int add(int A, int B){
	if(A + B >= MOD)
		return A + B - MOD;
	return A + B;
}

int C[N][N], n;
int miin[N][N], maax[N][N], grp[N];
int miin2[N][N], miin3[N][N], dp[N][N];
vector < int > cur[N], p, prz[N];
vector < pii > edg;

bool cmp(pii A, pii B){
	return C[A.X][A.Y] < C[B.X][B.Y];
}

void precompute(){
	for(int ii = 1;ii <= n;ii++){
		for(int i = 0, j = ii;i < n && j < n;i++, j++){
			maax[i][j] = max(maax[i][j - 1], maax[i + 1][j]);
			maax[i][j] = max(maax[i][j], C[p[i]][p[j]]);
		}
	}
	for(int i = 0;i < n;i++){
		miin[i][0] = C[p[i]][p[0]];
		miin[i][n - 1] = C[p[i]][p[n - 1]];
		for(int j = 1;j < i;j++)
			miin[i][j] = min(miin[i][j - 1], C[p[i]][p[j]]);
		for(int j = n - 2;j > i;j--)
			miin[i][j] = min(miin[i][j + 1], C[p[i]][p[j]]);			
	}
	for(int i = 0;i < n;i++){
		miin2[i][i] = (i ? miin[i][i - 1] : INF); 
		for(int j = i + 1;j < n;j++){
			miin2[i][j] = min(miin2[i][j - 1], (i ? miin[j][i - 1] : INF));
		}
	}
	for(int j = 0;j < n;j++){
		miin3[j][j] = (j + 1 < n ? miin[j][j + 1] : INF);
		for(int i = j - 1;i >= 0;i--){
			miin3[i][j] = min(miin3[i + 1][j], (j + 1 < n ? miin[i][j + 1] : INF));			
		}
	}
}

bool check(int l, int r){
	if(l == r) return true;
	return maax[l][r] < miin2[l][r] && maax[l][r] < miin3[l][r];
}

void mrg(int x, int y){
	if(x > y) {x ^= y, y ^= x, x ^= y;}
	for(int z : cur[y]){
		grp[z] = x;
		cur[x].PB(z);
	}
	cur[y].clear();
}


int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			scanf("%d", &C[i][j]);
			if(i < j) edg.PB({i, j});
		}
		grp[i] = i; cur[i].PB(i);
	}
	sort(edg.begin(), edg.end(), cmp);
	for(pii tmp : edg){
		if(grp[tmp.X] != grp[tmp.Y])
			mrg(grp[tmp.X], grp[tmp.Y]);
	}
	p = cur[0];
	precompute();
	for(int i = 0;i < n;i++){
		for(int j = i;j < n;j++){
			if(check(i, j))
				prz[i].PB(j + 1);
		}
	}
	dp[n][0] = 1;
	for(int i = n - 1;i >= 0;i--){
		for(int j = 1;j <= n - i;j++){
			for(int nxt : prz[i]){
				dp[i][j] = add(dp[i][j], dp[nxt][j - 1]);
			}
		}
	}
	for(int i = 1;i <= n;i++)
		printf("%d ", dp[0][i]);
	printf("\n");
	return 0;
}