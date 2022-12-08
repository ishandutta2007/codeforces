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
#define Inf 10000000
#define Mod 1000000007LL

int r, c;
int fx = -1, fy;
int mat[1010][1010];
int righ[1010][1010];
int down[1010][1010];

int calc(int x, int y){
	int sum = x * y;
	int a = fx, b = fy;
	while(true){
		if(b + y <= c && down[a][b + y] >= x){
			sum += x;
			b++;
		}
		else if(a + x <= r && righ[a + x][b] >= y){
			sum += y;
			a++;
		}
		else return sum;
	}
	return -1;
}

int main(){
	cin >> r >> c;
	char ch;
	int tot = 0;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> ch;
			mat[i][j] = (ch == 'X' ? 1 : 0);
			if(mat[i][j] && fx == -1)
				fx = i, fy = j;
			tot += mat[i][j];
		}
	}
	for(int i = r - 1; i >= 0; i--){
		for(int j = c - 1; j >= 0; j--){
			down[i][j] = mat[i][j];
			if(i < r - 1 && mat[i][j])
				down[i][j] += down[i + 1][j];
			righ[i][j] = mat[i][j];
			if(j < c - 1 && mat[i][j])
				righ[i][j] += righ[i][j + 1];
		}
	}

	int res = Inf;
	int x = down[fx][fy], y = righ[fx][fy];
	for(int i = 1; i <= y; i++)
		if(calc(x, i) == tot)
			res = min(res, x * i);
	for(int i = 1; i <= x; i++)
		if(calc(i, y) == tot)
			res = min(res, i * y);
	cout << (res == Inf ? -1 : res) << endl;
	return 0;
}