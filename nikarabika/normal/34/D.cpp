#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 5e4 + 85 - 69;
int par[maxn];
vector<int> v[maxn];
int n, r1, r2;

void dfs(int x, int p = -1){
	par[x] = p;
	for(int i = 0; i < v[x].size(); i++)
		if(v[x][i] != p)
			dfs(v[x][i], x);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> r1 >> r2;
	for(int i = 1; i <= n; i++){
		if(i == r1)
			continue;
		int x;
		cin >> x;
		v[i].PB(x);
		v[x].PB(i);
	}
	dfs(r2);
	for(int i = 1; i <= n; i++){
		if(i == r2) continue;
		cout << par[i] << ' ';
	}
	cout << endl;
	return 0;
}