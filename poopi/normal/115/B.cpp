										/* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>

int r, c;
bool mat[200][200];
int dp[200][200];

int calc(int x, int y){
	int d = (x % 2 ? -1 : 1);
	int ny = y + d, next = -1;
	while(ny >= 0 && ny < c){
		if(mat[x][ny] || (x + 1 < r && mat[x + 1][ny]))
			next = ny;
		ny += d;
	}
	if(next == -1){
		if(x + 1 < r)
			return calc(x + 1, y) + 1;
		else return 0;
	}
	return calc(x, next) + abs(y - next);
}

int main(){
	while(cin >> r >> c){
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				char ch;
				cin >> ch;
				mat[i][j] = (ch == 'W' ? true : false);
			}
		}

		while(r > 0){
			bool fl = false;
			for(int j = 0; j < c; j++)
				if(mat[r - 1][j])
					fl = true;
			if(!fl)
				r--;
			else break;
		}
		int res = calc(0, 0);
		cout << res << endl;
	}
	return 0;
}