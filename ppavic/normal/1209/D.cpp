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

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int ALP = 30;
const int BASE = 31337;
const double EPS = 1e-9;
const double PI = 3.1415926535;

int par[N], sz[N], n, k;

int pr(int x){
	if(x == par[x]) return x;
	return par[x] = pr(par[x]);
}

void mrg(int x,int y){
	x = pr(x), y = pr(y);
	if(x == y) return;
	par[y] = x;
}

int main(){
	for(int i = 0;i < N;i++) par[i] = i;
	scanf("%d%d", &n, &k);
	for(int i = 0;i < k;i++){
		int x, y; scanf("%d%d", &x, &y);
		mrg(x, y);
	}
	int sol = 0;
	for(int i = 0;i < N;i++)
		sol += (par[i] != i);
	printf("%d\n", k - sol);
	return 0;
}