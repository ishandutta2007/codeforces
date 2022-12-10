#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
//#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))

const int maxn = 1000 + 10;
char a[maxn][maxn];
int par[maxn * maxn + maxn * 5];
int n, m;

int MP(int r, int c){return r * maxn + c;}

int root(int v){return (par[v] < 0) ? v : par[v] = root(par[v]);}

void merge(int v, int u){
	if((v = root(v)) == (u = root(u)))
		return;
	if(par[v] > par[u])
		swap(v, u);
	par[v] += par[u];
	par[u] = v;
	return;
}

int sizof(int v){
	int x = v / maxn, y = v % maxn;
	if(x == 0 or x == n + 1 or y == 0 or y == m + 1 or a[x][y] == '*')
		return 0;
	return -par[v];
}

int main(){
	memset(par, -1, sizeof par);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%s", a[i] + 1);
		for(int j = 1; j <= m; j++){
			if(a[i][j] == '.'){
				if(i - 1 >= 1 and a[i - 1][j] == '.')
					merge(MP(i, j), MP(i - 1, j));
				if(j - 1 >= 1 and a[i][j - 1] == '.')
					merge(MP(i, j), MP(i, j - 1));
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] == '.'){
				printf(".");
				continue;
			}
			int ans = 1;
			vector<int> v;
			if(i - 1 >= 1) v.PB(root(MP(i - 1, j)));
			if(i + 1 <= n) v.PB(root(MP(i + 1, j)));
			if(j - 1 >= 1) v.PB(root(MP(i, j - 1)));
			if(j + 1 <= m) v.PB(root(MP(i, j + 1)));
			sort(v.begin(), v.end());
			int siz = unique(v.begin(), v.end()) - v.begin();
			for(int k = 0; k < siz; k++)
				ans += sizof(v[k]);
			printf("%d", ans % 10);
		}
		printf("\n");
	}
	return 0;
}