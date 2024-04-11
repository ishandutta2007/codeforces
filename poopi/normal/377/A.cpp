										/* in the name of Allah */
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL

int r, c, k;
int cnt;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char mat[510][510];

void dfs(int x, int y){
	mat[x][y] = '.';
	cnt--;
	for(int i = 0; i < 4; i++){
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if(cnt > 0 && nx >= 0 && nx < r && ny >= 0 && ny < c && mat[nx][ny] == 'X')
			dfs(nx, ny);
	}
}

int main(){
	cin >> r >> c >> k;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> mat[i][j];
			if(mat[i][j] == '.'){
				cnt++;
				mat[i][j] = 'X';
			}
		}
	}
	cnt -= k;
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			if(cnt > 0 && mat[i][j] == 'X')
				dfs(i, j);
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++)
			cout << mat[i][j];
		cout << endl;
	}
	return 0;
}