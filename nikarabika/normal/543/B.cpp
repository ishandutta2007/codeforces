#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 3e3 + 10;
int d[maxn][maxn];
vector<int> v[maxn];
bool mark[maxn];
int n, m, s1, s2, t1, t2, l1, l2;

void bfs(int x){
	mark[x] = true;
	queue<int> Q;
	Q.push(x);
	while(Q.size()){
		int y = Q.front();
		Q.pop();
		for(int i = 0; i < v[y].size(); i++){
			if(mark[v[y][i]])
				continue;
			mark[v[y][i]] = true;
			d[x][v[y][i]] = d[x][y] + 1;
			Q.push(v[y][i]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	int q = m;
	while(m--){
		int fi, se;
		cin >> fi >> se;
		v[fi].PB(se);
		v[se].PB(fi);
	}
	cin >> s1 >> t1 >> l1
		>> s2 >> t2 >> l2;
	for(int i = 1; i <= n; i++){
		bfs(i);
		memset(mark, false, sizeof mark);
	}
	int Min = 1e9;
	if(d[s1][t1] > l1 or d[s2][t2] > l2){
		cout << -1 << endl;
		return 0;
	}
	Min = d[s1][t1] + d[s2][t2];
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			int dc = d[i][j];
			if(dc > min(l1, l2))
				continue;
			int x = min(d[s1][i] + d[j][t1], d[t1][i] + d[j][s1]);
			int y = min(d[s2][i] + d[j][t2], d[t2][i] + d[j][s2]);
			if(x + dc <= l1 and y + dc <= l2)
				Min = min(Min, x + y + dc);
		}
	}
	cout << q - Min << endl;
	return 0;
}