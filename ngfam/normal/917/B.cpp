#include <bits/stdc++.h>

using namespace std;

const int N = 101;

int n, m;
int e[N][N];
int f[N][N][2][30];

int dp(int x, int y, int p, int c){
	int &cur = f[x][y][p][c];
	if(cur != -1) return cur;

	cur = 0;

	if(p == 0){
		for(int v = 1; v <= n; ++v){
			if(e[x][v] >= c) cur = max(cur, 1 - dp(v, y, 1 - p, e[x][v]));
		}
	}
	else{
		for(int v = 1; v <= n; ++v){
			if(e[y][v] >= c) cur = max(cur, 1 - dp(x, v, 1 - p, e[y][v]));
		}
	}
	return cur;
}

int main(){

	memset(f, -1, sizeof f);
	memset(e, -1, sizeof e);

	cin >> n >> m;
	for(int i = 1; i <= m; ++i){
		int x, y; char t;
		cin >> x >> y >> t;

		e[x][y] = max(e[x][y], int(t - 'a'));
	}

	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(dp(i, j, 0, 0)) cout << 'A';
			else cout << 'B';
		}
		cout << endl;
	}
	
	return 0;
}