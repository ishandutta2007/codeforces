//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 510;
char ans[maxn];
bool mat[maxn][maxn], mark[maxn];
int n, m, cmpcnt;
vector<int> vec[maxn];

void dfs(int v){
	mark[v] = true;
	vec[cmpcnt].PB(v);
	for(int u = 0; u < n; u++)
		if(mat[v][u] and ans[u] != 'b' and !mark[u])
			dfs(u);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		mat[fi][se] = mat[se][fi] = true;
	}
	for(int i = 0; i < n; i++){
		int deg = 0;
		for(int j = 0; j < n; j++)
			deg += mat[i][j];
		if(deg == n - 1)
			ans[i] = 'b';
	}
	cmpcnt = 0;
	for(int i = 0; i < n; i++)
		if(!mark[i] and ans[i] != 'b')
			dfs(i), cmpcnt++;
	if(cmpcnt > 2){
		cout << "NO\n";
		return 0;
	}
	for(auto x : vec[0])
		ans[x] = 'a';
	for(auto x : vec[1])
		ans[x] = 'c';
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(i != j)
				if((mat[i][j] and abs(ans[i] - ans[j]) > 1) or (!mat[i][j] and abs(ans[i] - ans[j]) <= 1)){
					cout << "NO\n";
					return 0;
				}
	cout << "YES\n";
	for(int i = 0; i < n; i++)
		cout << ans[i];
	cout << endl;
	return 0;
}