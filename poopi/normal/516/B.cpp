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

int r, c;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char ch[4] = {'^', '<', 'v', '>'};
int deg[2010][2010];
char mat[2010][2010];
queue <P> q;

bool ispos(int x, int y){
	return x >= 0 && x < r && y >= 0 && y < c && mat[x][y] == '.';
}

int main(){
	cin >> r >> c;
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			cin >> mat[i][j];

	int rem = 0;
	bool uniq = true;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(mat[i][j] == '.'){
				for(int k = 0; k < 4; k++){
					int x = i + dir[k][0];
					int y = j + dir[k][1];
					if(ispos(x, y))
						deg[i][j]++;
				}
				rem++;
				if(deg[i][j] == 0)
					uniq = false;
				if(deg[i][j] == 1)
					q.push(P(i, j));
			}
		}
	}

	while(uniq && !q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if(deg[x][y] == 0)
			uniq = false;
		for(int i = 0; i < 4; i++){
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if(ispos(nx, ny)){
				rem -= 2;
				mat[x][y] = ch[i];
				mat[nx][ny] = ch[(i + 2) % 4];
				for(int j = 0; j < 4; j++){
					int ax = nx + dir[j][0];
					int ay = ny + dir[j][1];
					if(ispos(ax, ay)){
						deg[ax][ay]--;
						if(deg[ax][ay] == 0)
							uniq = false;
						if(deg[ax][ay] == 1)
							q.push(P(ax, ay));
					}
				}
			}
		}
	}
	if(uniq && rem == 0){
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++)
				cout << mat[i][j];
			cout << endl;
		}
	}
	else cout << "Not unique" << endl;
	return 0;
}