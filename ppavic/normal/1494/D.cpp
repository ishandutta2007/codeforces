#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef vector < int > vi;

const int N = 1e3 + 50;
const int M = 1e6 + 500;
const int LOG = 18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7; //
const int OFF = (1 << LOG);
const ld EPS = 1e-9;

inline int add(int A, int B) { if(A + B >= MOD); return A + B - MOD; return A + B; }
inline int sub(int A, int B) { if(A - B < 0) return A - B + MOD; return A - B; }
inline int mul(int A, int B) { return (ll)A * B % MOD; }

int A[N][N], n;
int par[N], k, placa[N];
vector < int > rek[N];
vector < pii > edg;

int pr(int x){
	if(par[x] == x) return x;
	return par[x] = pr(par[x]);
}


void solve(vector < int > v, int lst){
	if((int)v.size() == 1){
		edg.PB({v[0], lst}); 
		return;
	}
	int maax = 0;
	for(int x : v){
		par[x] = x;
		for(int y : v)
			maax = max(maax, A[x][y]);
	}
	for(int x : v)
		for(int y : v)
			if(A[x][y] < maax)
				par[pr(x)] = pr(y);
	for(int x : v)
		rek[pr(x)].PB(x);
	int root = k++; placa[root] = maax; 
	if(lst) edg.PB({root, lst});
	for(int x : v){
		if((int)rek[x].size() == 0) continue;
		vector < int > tmp = rek[x]; rek[x].clear();
		solve(tmp, root); 
	}
	
}

int main(){
	scanf("%d", &n);
	vi v; k = n + 1;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++)
			scanf("%d", &A[i][j]);
		v.PB(i); placa[i] = A[i][i];
	}
	solve(v, 0);
	printf("%d\n", k - 1);
	for(int i = 1;i < k;i++) printf("%d ", placa[i]); printf("\n");
	printf("%d\n", n + 1);
	for(pii tmp : edg) printf("%d %d\n", tmp.X, tmp.Y);
	return 0;
}