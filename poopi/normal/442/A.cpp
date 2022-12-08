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

int n;
int mat[5][5];
char col[5] = {'R', 'G', 'B', 'Y', 'W'};

int getId(char c){
	for(int i = 0; i < 5; i++)
		if(c == col[i])
			return i;
	return -1;
}

int main(){
	cin >> n;
	string str;
	for(int i = 0; i < n; i++){
		cin >> str;
		mat[getId(str[0])][str[1] - '1']++;
	}
	int res = 10;
	for(int i = 0; i < 32; i++){
		for(int j = 0; j < 32; j++){
			int cnt = 0;
			for(int k = 0; k < 5; k++){
				if(i & (1 << k))
					cnt++;
				if(j & (1 << k))
					cnt++;
			}
			bool can = true;
			for(int r = 0; r < 5; r++){
				for(int c = 0; c < 5; c++){
					for(int x = 0; x < 5; x++){
						for(int y = 0; y < 5; y++){
							if(r == x && c == y)
								continue;
							if(mat[x][y] == 0 || mat[r][c] == 0)
								continue;
							if(r != x && ((i & (1 << r)) || (i & (1 << x))))
								continue;
							if(c != y && ((j & (1 << c)) || (j & (1 << y))))
								continue;
							can = false;
						}
					}
				}
			}
			if(can)
				res = min(res, cnt);
		}
	}
	cout << res << endl;
	return 0;
}