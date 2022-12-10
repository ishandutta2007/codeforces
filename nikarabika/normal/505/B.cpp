#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 1e2 + 10;
bool mark[maxn];
vector<int> v[maxn][maxn];
int n, m;

void dfs(int x, int c){
	mark[x] = true;
	for(int i = 0; i < v[x][c].size(); i++)
		if(!mark[v[x][c][i]])
			dfs(v[x][c][i], c);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		v[fi][th].PB(se);
		v[se][th].PB(fi);
	}
	int q;
	cin >> q;
	while(q--){
		int fi, se;
		cin >> fi >> se;
		int c = 0;
		for(int i = 1; i <= m; i++){
			memset(mark, false, sizeof mark);
			dfs(fi, i);
			if(mark[se])
				c++;
		}
		cout << c << endl;
	}
	return 0;
}