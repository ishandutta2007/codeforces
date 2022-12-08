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

int dp[10][10][31];
char mat[10][10];

int isin(int r, int c){
	return r >= 0 && r <= 7 && c >= 0 && c <= 7;
}

int mem(int r, int c, int tm){
	if(tm > 28)
		return 0;
	if(r == 0 && c == 7)
		return 1;
	int& ref = dp[r][c][tm];
	if(ref != -1)
		return ref;
	ref = 0;
	for(int i = -1; i < 2; i++){
		for(int j = -1; j < 2; j++){
			int nr = r + i, nc = c + j;
			int np = r - tm;
			if(isin(nr, nc) && (np < 0 || mat[np][nc] != 'S') &&
				(np - 1 < 0 || mat[np - 1][nc] != 'S') && mem(nr, nc, tm + 1))
				ref = 1;
		}
	}
	return ref;
}

int main(){
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			cin >> mat[i][j];
	memset(dp, -1, sizeof dp);
	int res = mem(7, 0, 0);
	cout << (res ? "WIN" : "LOSE") << endl;
	return 0;
}