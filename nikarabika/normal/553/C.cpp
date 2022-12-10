#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define PB push_back

const int maxn = 1e5 + 85 - 69;
const LL D = 1e9 + 7;
vector<int> v[maxn], vc[maxn];
int h[maxn], com[maxn];
bool mark[maxn];
int n, m, comp;

void dfs1(int x){
	mark[x] = true;
	com[x] = comp;
	for(int i = 0; i < v[x].size(); i++)
		if(!mark[v[x][i]])
			dfs1(v[x][i]);
}

void dfs2(int x, int p = -1){
	mark[x] = true;
	for(int i = 0; i < v[x].size(); i++){
		if(!mark[v[x][i]]){
			h[v[x][i]] = h[x] + 1;
			dfs2(v[x][i]);
		}
		else if(v[x][i] != p and !((h[v[x][i]] + h[x]) & 1)){
			cout << 0 << endl;
			exit(0);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se, ty;
		cin >> fi >> se >> ty;
		if(ty)
			v[fi].PB(se), v[se].PB(fi);
		else
			vc[fi].PB(se), vc[se].PB(fi);
	}
	for(int i = 1; i <= n; i++){
		if(!mark[i]){
			comp++;
			dfs1(i);
		}
	}
	for(int i = 1; i <= n; i++){
		v[i].clear();
		for(int j = 0; j < vc[i].size(); j++)
			v[com[i]].PB(com[vc[i][j]]);
	}
	memset(mark, false, sizeof mark);
	n = comp;
	comp = -1;
	for(int i = 1; i <= n; i++){
		if(!mark[i]){
			comp++;
			dfs2(i);
		}
	}
	LL ans = 1;
	for(int i = 0; i < comp; i++)
		ans = (ans * 2) % D;
	cout << ans << endl;
	return 0;
}