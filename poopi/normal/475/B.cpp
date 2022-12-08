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
#define Inf 100000000
#define Mod 1000000007LL

int r, c;
int mat[500][500];

int main(){
	cin >> r >> c;
	for(int i = 0; i < r * c; i++)
		for(int j = 0; j < r * c; j++)
			mat[i][j] = Inf;
	for(int i = 0; i < r * c; i++)
		mat[i][i] = 0;
	char ch;
	for(int i = 0; i < r; i++){
		cin >> ch;
		for(int j = 0; j + 1 < c; j++){
			if(ch == '>')
				mat[i * c + j][i * c + j + 1] = 1;
			else mat[i * c + j + 1][i * c + j] = 1;
		}
	}
	for(int j = 0; j < c; j++){
		cin >> ch;
		for(int i = 0; i + 1 < r; i++){
			if(ch == 'v')
				mat[i * c + j][i * c + j + c] = 1;
			else mat[i * c + j + c][i * c + j] = 1;
		}
	}
	int t = r * c;
	for(int k = 0; k < t; k++)
		for(int i = 0; i < t; i++)
			for(int j = 0; j < t; j++)
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
	string ans = "YES";
	for(int i = 0; i < t; i++)
		for(int j = 0; j < t; j++)
			if(mat[i][j] == Inf)
				ans = "NO";
	cout << ans << endl;
	return 0;
}