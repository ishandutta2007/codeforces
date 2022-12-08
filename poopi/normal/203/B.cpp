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

ifstream fin("input.txt");
ofstream fout("output.txt");

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
//#define cin fin
//#define cout fout

int n, m;
int mat[1010][1010];

int calc(int r, int c){
	int mx = 0;
	for(int i = r; i < r + 3; i++)
		for(int j = c; j < c + 3; j++)
			mx = max(mx, mat[i][j]);
	return mx;
}

int main(){
	cin >> n >> m;
	int a, b;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			mat[i][j] = Inf;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		mat[a - 1][b - 1] = i + 1;
	}
	int res = Inf;
	for(int i = 0; i + 2 < n; i++)
		for(int j = 0; j + 2 < n; j++)
			res = min(res, calc(i, j));
	cout << (res == Inf ? -1 : res) << endl;
    return 0;
}