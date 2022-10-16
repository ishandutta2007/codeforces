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

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int LOG = 18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7; //
const int OFF = (1 << LOG);
const ld EPS = 1e-9;

inline int add(int A, int B) { if(A + B >= MOD); return A + B - MOD; return A + B; }
inline int sub(int A, int B) { if(A - B < 0) return A - B + MOD; return A - B; }
inline int mul(int A, int B) { return (ll)A * B % MOD; }

vi fib;

int zab[N], siz[N], gor[N];
int n;
vector < int > proso;
vector < pii > v[N];

void dfs(int x, int lst){
	siz[x] = 1; proso.PB(x);
	for(pii y : v[x]){
		if(zab[y.Y] || y.X == lst) continue;
		dfs(y.X, x); siz[x] += siz[y.X]; gor[y.X] = y.Y;
	}
}

bool provjeri(int cur, int k){	
	if(k == 1 || k == 2) return true;
	dfs(cur, cur); 
	int odl = -1;
	for(int x : proso){
		if(siz[x] == fib[k - 1]){
			odl = x; break;
		}
	}
	if(odl != -1){
		zab[gor[odl]] = 1;	
		proso.clear();
		return provjeri(cur, k - 2) && provjeri(odl, k - 1);
	}
	for(int x : proso){
		if(siz[x] == fib[k - 2]){
			odl = x; break;
		}
	}
	proso.clear();
	if(odl == -1) return false;
	zab[gor[odl]] = 1;
	return provjeri(odl, k - 2) && provjeri(cur, k - 1);
}

void precompute(){
	fib.PB(0); fib.PB(1);
	while(fib.back() < N){
		fib.PB(fib.back() + fib[(int)fib.size() - 2]);
	}
}

int main(){
	precompute();
	scanf("%d", &n);
	int ja = 0;
	while(fib[ja] < n) ja++;
	if(fib[ja] != n){
		printf("NO\n");
		return 0;
	}
	for(int i = 1;i < n;i++){
		int x, y; scanf("%d%d", &x, &y);
		v[x].PB({y, i}), v[y].PB({x, i});
	}
	if(provjeri(1, ja))
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}