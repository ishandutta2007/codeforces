#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 1000 + 10;
int cnt[maxn * maxn], compo, com[maxn][maxn];
int n, m, q;
char a[maxn][maxn];
bool mark[maxn][maxn];
vector<pii> mv;

void dfs(pii v){
	mark[v.L][v.R] = true;
	com[v.L][v.R] = compo;
	for(auto d : mv){
		pii u(v.L + d.L, v.R + d.R);
		if(a[u.L][u.R] == '.' and !mark[u.L][u.R])
			dfs(u);
		cnt[compo] += a[u.L][u.R] == '*';
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//seen.reserve(1000000);
	mv.PB({0, +1});
	mv.PB({0, -1});
	mv.PB({-1, 0});
	mv.PB({+1, 0});
	cin >> n >> m >> q;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(a[i][j] == '.' and !mark[i][j]){
				dfs({i, j});
				//sort(seen.begin(), seen.end());
				compo++;
			}
	while(q--){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		cout << cnt[com[fi][se]] << '\n';
	}
	return 0;
}