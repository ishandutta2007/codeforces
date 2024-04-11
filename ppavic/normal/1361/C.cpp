#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>
#include <map>

#define X first
#define Y second 
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

const int N = 2e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int deg[N];
int L[N], R[N], bio[N], lst[N], ans;
int par[N], n;
vector < pair < int, bool > > put;
vector < int > v[N];

int pr(int x){
	if(x == par[x]) return x;
	return par[x] = pr(par[x]);
}

void mrg(int x, int y){
	par[pr(x)] = pr(y);
}


void euler(int x){	
	for(;lst[x] >= 0;lst[x]--){
		if(bio[v[x][lst[x]]]) continue;
		int edg = v[x][lst[x]];
		bio[edg] = 1;
		bool sm = 0;
		if((R[edg] % (1 << ans)) == x)
			sm = 1;
		if(!sm)
			euler(R[edg] % (1 << ans));
		else
			euler(L[edg] % (1 << ans));
		put.PB({edg, sm});
	}
}

int main(){
	scanf("%d", &n);
	if(n == 1){
		int x, y; scanf("%d%d", &x, &y);
		int ans = 20;
		for(;x % (1 << ans) != y % (1 << ans); ans--);
		printf("%d\n1 2\n", ans);
		return 0;
	}
	for(int i = 0;i < n;i++){
		scanf("%d%d", L + i, R + i);
	}
	for(ans = 20;ans >= 0;ans--){
		for(int i = 0;i < (1 << ans);i++){
			par[i] = i; deg[i] = 0;
		}
		vector < int > bit;
		for(int i = 0;i < n;i++){
			deg[L[i] % (1 << ans)]++; deg[R[i] % (1 << ans)]++;
			mrg(L[i] % (1 << ans), R[i] % (1 << ans));
			bit.PB(L[i] % (1 << ans)); bit.PB(R[i] % (1 << ans));
		}
		int mogu = 1;
		for(int x : bit){
			if(pr(x) != pr(bit[0]))
				mogu = 0;
		}
		bit.clear();
		for(int i = 0;i < (1 << ans);i++){
			if(deg[i] & 1) mogu = 0;	
		}
		if(!mogu) continue;
		for(int i = 0;i < n;i++){
			v[L[i] % (1 << ans)].PB(i); 
			v[R[i] % (1 << ans)].PB(i); 
		}
		for(int i = 0;i < (1 << ans);i++){
			lst[i] = (int)v[i].size() - 1;
		}
		for(int i = 0;i < (1 << ans);i++){
			if(v[i].size())	{
				euler(i); break;
			}
		}
		printf("%d\n", ans);
		for(pair < int, bool > tmp : put){
			if(tmp.Y)
				printf("%d %d ", 2 * tmp.X + 1, 2 * tmp.X + 2);
			else
				printf("%d %d ", 2 * tmp.X + 2, 2 * tmp.X + 1);
		}
		printf("\n");
		return 0;
	}
	return 0;
	
}