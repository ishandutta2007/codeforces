#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef pair < int, int > pt;
typedef vector < int > vi;

const int N = 4e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7; // 998244353
const int LOG = 20;
const int OFF = (1 << LOG);

inline int add(int A, int B) {if(A + B >= MOD) return A + B - MOD; return A + B; }
inline int sub(int A, int B) {if(A - B < 0) return A - B + MOD; return A - B; }
inline int mul(int A, int B) { return (ll)A * B % MOD; }

int A[N], B[N], dp[N][2], n, bitnih;
int par[N], drug[N], bio[N], sol[N], lose, nebitno[N];

pii solve(int x, int y){
	//printf("pozivam %d %d\n", x, y);
	if(x >= y) return {0, 0};
	if(bio[par[y]]){ return solve(x, y - 1); }
	if(bio[par[x]]){ return solve(x + 1, y);  } 
	if(par[x] == par[y]){ 
		sol[par[x]] = 1; nebitno[par[x]] = 1; 
		bio[par[x]] = 1;  
		return solve(x + 1, y - 1); 
	}
	pii dod = {0, 2};
	sol[par[x]] = 0, sol[par[y]] = 1; dod.X += A[par[x]] != x;
	bio[par[x]] = 1, bio[par[y]] = 1; dod.X += A[par[y]] != y;
	if(drug[x] < drug[y]) { lose = 1; return {0, 0}; }
	int xx = x + 1, gx = drug[y];
	int yy = y - 1, gy = drug[x];
	while(xx < gx || yy > gy){
		for(;xx < gx;xx++){
			if(!bio[par[xx]]) { 
				sol[par[xx]] = 0; 
				bio[par[xx]] = 1; 
				dod.Y++;
				dod.X += A[par[xx]] != xx;
				gy = min(gy, drug[xx]);
			}
		}
		for(;yy > gy;yy--)
			if(!bio[par[yy]]) { 
				sol[par[yy]] = 1; 
				bio[par[yy]] = 1; 
				dod.Y++;
				dod.X += A[par[yy]] != yy;
				gx = max(gx, drug[yy]);
			}
	}
	//printf("x = %d y = %d\n", x, y);
	//printf("xx = %d yy = %d\n", xx, yy);
	pii nov = solve(xx , yy );
	dod.X = min(dod.X, dod.Y - dod.X);
	nov.X += dod.X, nov.Y += dod.Y;
	return nov;
}

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%d%d", A + i, B + i);
		par[A[i]] = i, par[B[i]] = i;
		drug[A[i]] = B[i], drug[B[i]] = A[i];
	}
	int ans = solve(1, 2 * n).X;
	if(lose){
		printf("-1\n");
		return 0;
	}
	vector < pii > v;
	for(int i = 0;i < n;i++){	
		if(sol[i]) v.PB({max(A[i], B[i]), min(A[i], B[i])});
		else       v.PB({min(A[i], B[i]), max(A[i], B[i])});
	}
	sort(v.begin(), v.end());
	for(int i = 1;i < n;i++){
		//printf("%d %d\n", v[i].X, v[i].Y);
		if(i && v[i - 1].Y < v[i].Y){
			printf("-1\n"); return 0;
		}
	}
	printf("%d\n", ans);
	return 0;
}