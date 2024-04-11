#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define X first
#define Y second
#define PB push_back

/**

Jesam li sto rekao?
Sve sto sam rekao,
zaglusio je tutanj tramvaja...

Antun Soljan

**/

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef long long ll;

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << 18);
const int K = 105;

int n, m, k, ans;

int ako[K][K], zab[N];

vector < pii > v[N];
vector < int > eks[N];
vector < int > sol;

void brute(int x){
	if(x == k + 1){
		ans++; return;
	}
	for(int i = 0;i < x;i++){
		int dod = 9 * x + i;
		if(zab[dod]) continue;
		bool mogu = 1;
		for(int y : sol)
			if(ako[y][dod])
				mogu = 0;
		if(mogu){
			sol.PB(dod);
			brute(x + 1);
			sol.pop_back();
		}
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0;i < m;i++){
		int x, y, w; scanf("%d%d%d", &x, &y, &w);
		v[x].PB({w, y}); 
	}
	for(int i = 1;i <= n;i++){
		sort(v[i].begin(), v[i].end());
		int deg = (int)v[i].size();
		for(int j = 0;j < (int)v[i].size();j++){
			eks[v[i][j].Y].PB(9 * deg + j);
		}
	}
	for(int i = 1;i <= n;i++){
		sort(eks[i].begin(), eks[i].end());
		for(int j = 0;j + 1 < (int)eks[i].size();j++)
			if(eks[i][j] == eks[i][j + 1]) zab[eks[i][j]] = 1;
		eks[i].erase(unique(eks[i].begin(), eks[i].end()), eks[i].end());
		for(int x : eks[i])
			for(int y : eks[i])
				ako[x][y] = 1;
	}
	brute(1);
	printf("%d\n", ans);
	return 0;
}