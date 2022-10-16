#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int , int > pii;
typedef vector < int > vi;
typedef set < int > si;

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;

vi v[N], v2[N];
vi skup, poc, pitam;

int par[N][LOG], dep[N], ans[N], n;
int tme[N], R[N], cur_tme, sped[N];

bool cmp(int x,int y){
	return tme[x] < tme[y];
}

void dfs(int x,int lst){
	tme[x] = cur_tme++;
	par[x][0] = lst; dep[x] = dep[lst] + 1;
	for(int y : v[x])
		if(y != lst) dfs(y, x);
	R[x] = cur_tme - 1;
}

void precompute(){
	for(int i = 1;i < LOG;i++){
		for(int j = 1;j <= n;j++)
			par[j][i] = par[par[j][i - 1]][i - 1];
	}
}

int lca(int x,int y){
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = LOG - 1;i >= 0;i--)
		if(dep[x] - (1 << i) >= dep[y])
			x = par[x][i];
	if(x == y) return x;
	for(int i = LOG - 1;i >= 0;i--)
		if(par[x][i] != par[y][i])
			x = par[x][i],
			y = par[y][i];
	return par[x][0];
}

inline int dis(int x,int y){
	return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}

void prosiri(){
	sort(skup.begin(), skup.end(), cmp);
	int ln = (int)skup.size();
	for(int i = 1;i < ln;i++){
		skup.PB(lca(skup[i], skup[i - 1]));
	}
	sort(skup.begin(), skup.end());
	skup.erase(unique(skup.begin(), skup.end()), skup.end());
	//printf("vel %d\n", (int)skup.size());
}

void pospajaj(){
	stack < int > tren;
	sort(skup.begin(), skup.end(), cmp);
	for(int i = 0;i < (int)skup.size();i++){
		while(!tren.empty() && R[tren.top()] < tme[skup[i]])
			tren.pop();
		if(!tren.empty()){
			v2[skup[i]].PB(tren.top());
			v2[tren.top()].PB(skup[i]);
			//printf("spajam %d <=> %d\n", tren.top(), skup[i]);
		}
		tren.push(skup[i]);
	}
}

void obradi(){
	set < pair < pair < int, pii > , int > > S;
	for(int i = 0;i < (int)poc.size();i++){
		S.insert({{0, {i + 1, 0}}, poc[i]});
	}
	for(;!S.empty();){
		pair < pair < int, pii > , int > sad = *S.begin();
		S.erase(S.begin());
		int cur = sad.Y;
		int ost = sad.X.Y.Y, boj = sad.X.Y.X;
		//printf("cur %d   kor %d   boj %d    ost %d\n", cur, kor, boj, ost);
		if(ans[cur]) continue;
		ans[cur] = boj;
		for(int sus : v2[cur]){
			if(ans[sus]) continue;
			int ds = dis(cur, sus);
			//printf("%d <= %d => %d\n", cur, ds, sus);
			S.insert({{(ost + ds + sped[boj] - 1) / sped[boj], {boj, (ost + ds)}}, sus});
		}
	}
}

void pocisti(){
	for(int x : skup){
		v2[x].clear(); ans[x] = 0;
	}
	poc.clear(); pitam.clear();
	skup.clear();
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i < n;i++){
		int x, y; scanf("%d%d", &x, &y);
		v[x].PB(y), v[y].PB(x);
	}
	dfs(1, 1); precompute();
	int q; scanf("%d", &q);
	for(int i = 0;i < q;i++){
		int k, m; scanf("%d%d", &k, &m);
		for(int j = 1;j <= k;j++){
			int x; scanf("%d%d", &x, &sped[j]);
			poc.PB(x); skup.PB(x);
		}
		for(int j = 0;j < m;j++){
			int x; scanf("%d", &x);
			pitam.PB(x); skup.PB(x);
		}
		prosiri(); pospajaj();
		obradi();
		for(int x : pitam)
			printf("%d ", ans[x]);
		printf("\n");
		pocisti();
	}
	return 0;
}