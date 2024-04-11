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

const int N = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int ALP = 30;
const int BASE = 31337;
const double EPS = 1e-9;
const double PI = 3.1415926535;

int par[N][LOG], n, m;
int F[N], dep[N], tez[N], cnt = 2, dp[N], post[N][10];
vp v[N];

int cmp(int i,int j){
	if(dep[i] != dep[j]) return dep[i] < dep[j];
	for(int k = LOG - 1;k >= 0;k--)
		if(par[i][k] != par[j][k])
			i = par[i][k], j = par[j][k];
	if(tez[i] == tez[j]) return 2;
	return tez[i] < tez[j];
}

bool p_cmp(pii A, pii B){
	//printf("USPORERDUJEM %d %d i %d %d\n", A.X, A.Y, B.X, B.Y);
	//fflush(stdout);
	int ret = cmp(A.X, B.X);
	//printf("RET = %d\n", ret);
	if(ret == 2) return A.Y < B.Y;
	return !ret;
}

priority_queue < pii, vector < pii >, decltype(&p_cmp)> P(p_cmp);



inline int add(const int &A, const int &B){
	if(A + B >= MOD) return A + B - MOD;
	return A + B;
}

inline int mul(const int &A, const int &B){
	return (ll)A * B % MOD;
}

int get_node(int i, int x){
	if(post[i][x]) return post[i][x];
	par[cnt][0] = i, tez[cnt] = x;
	dp[cnt] = add(x, mul(dp[i], 10));
	dep[cnt] = dep[i] + 1;
	post[i][x] = cnt;
	//printf("NOVI CVOR %d\n", cnt);
	//printf("PARENT %d\n", i);
	//printf("DEPTH %d\n", dep[i]);
	//printf("DP %d\n", dp[i]);
	//printf("TEZINA %d\n", x);

	for(int k = 1;k < LOG;k++)
		par[cnt][k] = par[par[cnt][k - 1]][k - 1];
	//printf("KREACIJA GOTOVA\n");
	return cnt++;
}

int stvori(int i,int x){
	int pot = 1;
	for(;x >= pot;pot *= 10); pot /= 10;
	//printf("x = %d pot = %d\n", x, pot);
	for(;pot >= 1;pot /= 10){
		i = get_node(i, x / pot);
		x %= pot;
	}
	//printf("STVOREN CVOR %d\n", i);
	return i;
}

void dijkstra(){
	memset(F, -1, sizeof(F));
	P.push({0, 1});
	for(;!P.empty();){
		pii beg = P.top(); P.pop();
		int cur = beg.Y;
		//printf("			cur = %d\n", cur);
		if(F[cur] != -1) continue;
		F[cur] = beg.X;
		for(pii nxt : v[cur]){
			if(F[nxt.X] == -1){
				//printf("	%d => %d\n", cur, nxt.X);
				//printf("POCEO PUSH\n");
				P.push({stvori(F[cur], nxt.Y), nxt.X});
				//printf("GOTOV PUSH\n");
			}
		}
	}
}



int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0;i < m;i++){
		int x, y; scanf("%d%d", &x, &y);
		v[x].PB({y, i + 1}); v[y].PB({x, i + 1});
	}
	dijkstra();
	for(int i = 2;i <= n;i++)
		printf("%d\n", dp[F[i]], F[i]);
	return 0;
}