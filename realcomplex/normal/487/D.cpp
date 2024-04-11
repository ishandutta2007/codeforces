#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
const int M = 12;
int bl;

int n, m;
char dir[N][M];

int nxi[N][M];
int nxj[N][M];

void dfs(int pi, int pj, int lf, int rf){
	if(nxi[pi][pj] != -2)
		return;
	if(dir[pi][pj] == '>'){
		if(dir[pi][pj + 1]  == '<'){
			nxi[pi][pj] = -1;
			nxj[pi][pj] = -1;
			return;
		}
		if(pj + 1 > m){
			nxi[pi][pj] = pi;
			nxj[pi][pj] = pj + 1;
			return;
		}
		dfs(pi, pj + 1, lf, rf);
		nxi[pi][pj] = nxi[pi][pj + 1];
		nxj[pi][pj] = nxj[pi][pj + 1];
	}
	
	if(dir[pi][pj] == '<'){
		if(dir[pi][pj - 1]  == '>'){
			nxi[pi][pj] = -1;
			nxj[pi][pj] = -1;
			return;
		}
		if(pj - 1 == 0){
			nxi[pi][pj] = pi;
			nxj[pi][pj] = pj - 1;
			return;
		}
		dfs(pi, pj - 1, lf, rf);
		nxi[pi][pj] = nxi[pi][pj - 1];
		nxj[pi][pj] = nxj[pi][pj - 1];
	}
	if(dir[pi][pj] == '^'){
		if(pi - 1 < lf){
			nxi[pi][pj] = pi - 1;
			nxj[pi][pj] = pj;
			return;
		}
		dfs(pi - 1, pj, lf, rf);
		nxi[pi][pj] = nxi[pi - 1][pj];
		nxj[pi][pj] = nxj[pi - 1][pj];
	}
}

int main(){
	fastIO;
	int q;
	cin >> n >> m >> q;
	bl = int(sqrt(n));
	for(int i = 1; i <= n; i ++ ){
		for(int j = 1; j <= m ; j ++ ){
			cin >> dir[i][j];
		}
	}
	for(int i = 0 ;i < N; i ++ )
		for(int j = 0 ; j < M; j ++ )
			nxi[i][j] = -2, nxj[i][j] = -2;
	int cl, cr;
	for(int i = 1; i <= n ; i ++ ){
		cl = (i - 1)/bl;
		cl = cl * bl;
		++ cl;
		cr = cl + bl - 1;
		cr = min(cr, n);
		for(int j = 1; j <= m; j ++ ){
			dfs(i, j, cl, cr);
		}
	}
	char typ;
	int ci, cj;
	char ch;
	int in, jn;
	for(int i = 0 ;i < q; i ++ ){
		cin >> typ >> ci >> cj;
		if(typ == 'C'){
			cin >> ch;
			dir[ci][cj] = ch;
			cl = (ci - 1)/bl;
			cl = cl * bl;
			++ cl;
			cr = cl + bl - 1;
			cr = min(cr, n);
			for(int ii = cl; ii <= cr; ii ++ ){
				for(int jj = 1; jj <= m; jj ++ ){
					nxi[ii][jj] = -2;
					nxj[ii][jj] = -2;
				}
			}
			for(int ii = cl; ii <= cr; ii ++ ){
				for(int jj = 1; jj <= m ; jj ++ ){
					dfs(ii, jj, cl, cr);
				}
			}
		}
		else{
			while(ci >= 1 && ci <= n && cj >= 1 && cj <= m){
				in = nxi[ci][cj];
				jn = nxj[ci][cj];
				ci = in;
				cj = jn;
			}
			cout << ci << " " << cj << "\n";
		}
	}
	return 0;
}