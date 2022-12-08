							/* in the name of Allah */
#include <iostream>
#include <string>
using namespace std;

int r, c, n, x, y, cnt = 0;
int dir[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
char mat[20][20][20];
bool mark[20][20][20];

bool isin(int i, int j, int k){
	return i >= 0 && j >= 0 && k >= 0 && i < r && j < c && k < n;
}

void dfs(int i, int j, int k){
	cnt++;
	mark[i][j][k] = true;
	//cout << i << ' ' << j << ' ' << k << endl;
	for(int ii = 0; ii < 6; ii++){
		int ni = i + dir[ii][0];
		int nj = j + dir[ii][1];
		int nk = k + dir[ii][2];
		if(isin(ni, nj, nk) && mat[ni][nj][nk] == '.' && !mark[ni][nj][nk])
			dfs(ni, nj, nk);
	}
}

int main(){
	cin >> r >> c >> n;
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			for(int k = 0; k < n; k++)
				cin >> mat[i][j][k];
	cin >> x >> y;
	x--, y--;
	dfs(0, x, y);
	cout << cnt << endl;
	return 0;
}