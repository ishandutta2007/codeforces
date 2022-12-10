#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 2e5 + 10;
int n;
int up;
int dpath[maxn], upath[maxn];
int Min = 1e9;
vector<int> ans;
vector<pair<int, bool> > v[maxn];

void dfs(int x, int p = -1){
	for(int i = 0; i < v[x].size(); i++){
		if(v[x][i].L != p){
			dpath[v[x][i].L] = dpath[x] + !v[x][i].R;
			upath[v[x][i].L] = upath[x] + v[x][i].R;
			up += v[x][i].R;
			dfs(v[x][i].L, x);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	ans.reserve(1e5);
	cin >> n;
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		v[fi].PB(MP(se, 0));
		v[se].PB(MP(fi, 1));
	}
	dfs(1);
	for(int i = 1; i <= n; i++){
		if(up - upath[i] + dpath[i] < Min){
			Min = up - upath[i] + dpath[i];
			ans.clear();
			ans.PB(i);
		}
		else if(up - upath[i] + dpath[i] == Min)
			ans.PB(i);
	}
	cout << Min << endl;
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}