#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 1e5 + 10, maxlog = 17;
int P[maxlog][maxn], h[maxn], dwn[maxn];
bool mark[maxn];
vector<int> v[maxn];
int n, q;

int dfs(int x, int p){
	mark[x] = true;
	dwn[x] = 1;
	P[0][x] = p;
	for(int i = 1; i < maxlog; i++)
		P[i][x] = P[i - 1][P[i - 1][x]];
	for(int i = 0; i < v[x].size(); i++){
		if(!mark[v[x][i]]){
			h[v[x][i]] = h[x] + 1;
			dwn[x] += dfs(v[x][i], x);
		}
	}
	return dwn[x];
}

int Ance(int x, int d){
	int i = 0;
	while(i < maxlog){
		if(d & (1 << i)){
			d -= (1 << i);
			x = P[i][x];
		}
		i++;
	}
	return x;
}

int LCA(int x, int y){
	if(x == 1 or y == 1)
		return 1;
	if(h[x] > h[y])
		x = Ance(x, h[x] - h[y]);
	else if(h[x] < h[y])
		y = Ance(y, h[y] - h[x]);
	if(x == y)
		return x;
	for(int i = maxlog - 1; i >= 0; i--){
		if(P[i][x] != P[i][y]){
			x = P[i][x];
			y = P[i][y];
		}
	}
	return P[0][x];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		v[fi].PB(se);
		v[se].PB(fi);
	}
	dfs(1, 0);
	cin >> q;
	while(q--){
		int fi, se;
		cin >> fi >> se;
		if(fi == se){
			cout << n << endl;
			continue;
		}
		int anc = LCA(fi, se);
		cerr << anc << '\t';
		int dfi = h[fi] - h[anc], 
			dse = h[se] - h[anc], 
			d = dfi + dse;
		if(d & 1){
			cout << 0 << endl;
			continue;
		}
		d /= 2;
		if(dfi == d){
			int x = Ance(fi, d - 1),
				y = Ance(se, d - 1);
			cout << n - dwn[x] - dwn[y] << endl;
			continue;
		}
		else if(dfi < d)
			swap(fi, se);
		se = Ance(fi, d);
		fi = Ance(fi, d - 1);
		cout << dwn[se] - dwn[fi] << endl;
	}
	return 0;
}