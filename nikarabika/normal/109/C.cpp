#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pie;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 1e5 + 85 - 75;
int down[maxn], dowl[maxn];
int up[maxn], ul[maxn], n;
pie par[maxn];
vector<pie> v[maxn];

void dfs(int x, int p = -1){
	down[x] = 1;
	for(auto adj : v[x]){
		int y = adj.L, tp = adj.R;
		if(y == p)
			continue;
		par[y] = MP(x, tp);
		dfs(y, x);
		down[x] += down[y];
		if(tp)
			dowl[x] += down[y];
		else
			dowl[x] += dowl[y];
	}
}

void UP(int x){
	if(up[x] != -1)
		return;
	int p = par[x].L, tp = par[x].R;
	UP(p);
	up[x] = up[p] + down[p] - down[x];
	if(tp)
		ul[x] = up[x];
	else
		ul[x] = ul[p] + dowl[p] - dowl[x];
}

bool islck(int x){
	while(x){
		if(x % 10 != 7 and x % 10 != 4)
			return false;
		x /= 10;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		v[fi].PB(MP(se, islck(th)));
		v[se].PB(MP(fi, islck(th)));
	}
	dfs(1);
	memset(up, -1, sizeof up);
	up[1] = 0;
	for(int i = 2; i <= n; i++)
		UP(i);
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		long long x = ul[i] + dowl[i];
		ans += x * (x - 1);
	}
	cout << ans << endl;
	return 0;
}